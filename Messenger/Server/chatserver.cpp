#include "chatserver.h"

ChatServer::ChatServer(QObject * parent) : QTcpServer(parent)
{
	//threadPool = new QThreadPool();
	//threadPool->setMaxThreadCount(2);
}



void ChatServer::incomingConnection(qintptr handle)
{
	Worker *worker = new Worker(this);
	worker->setSocketDescriptor(handle);

	connect(worker, &Worker::jsonReceived, this, &ChatServer::JsonReceived);
	connect(worker, &Worker::disconnectedFromServer, this, std::bind(&ChatServer::UserDisconnected, this, worker));
	connect(worker, &Worker::logMessage, this, &ChatServer::logMessage);

	clients.append(worker);

	emit logMessage("New user Connected!");
}


void ChatServer::JsonReceived(Worker *sender, const QJsonObject jsonObj){

	logMessage("Json received: " + QString::fromUtf8(QJsonDocument(jsonObj).toJson()));

	if (sender->UserName().isNull() || sender->UserName().isEmpty()){
		JsonFromLoggedOut(sender, jsonObj);
		return;
	}

	JsonFromLoggedIn(sender, jsonObj);
}


void ChatServer::SendJson(Worker *receiver, const QJsonObject jsonObj){
	QByteArray dataArray = QJsonDocument(jsonObj).toJson();

	receiver->SendJson(jsonObj);
}


void ChatServer::Broadcast(const QJsonObject jsonObj, Worker *exclude){

	for(Worker *worker : clients){
		if(worker == exclude){
			continue;
		}

		SendJson(worker, jsonObj);
	}
}


void ChatServer::JsonFromLoggedOut(Worker *sender, const QJsonObject jsonObj){

	QJsonValue jsonValue = jsonObj.value("type");
	if (jsonValue.toString() != "login")
		return;

	QJsonValue  nameValue = jsonObj.value("username");
	if(nameValue.isNull())
		return;

	for(Worker *worker : clients){
		if (worker == sender){
			continue;
		}

		if(worker->UserName() == nameValue.toString()){
			QJsonObject message;
			message["type"] = "login";
			message["success"] = false;
			message["reason"] = "Duplicate UserName";

			SendJson(sender, message);
			return;
		}
	}

	QString userName = nameValue.toString();

	sender->SetUserName(userName);

	QJsonObject SuccessMessage;
	SuccessMessage["type"] = "login";
	SuccessMessage["success"] = true;

	SendJson(sender, SuccessMessage);

	QJsonObject newUserMessage;
	newUserMessage["type"] = "newUser";
	newUserMessage["username"] = sender->UserName();

	Broadcast(newUserMessage, sender);
}


void ChatServer::JsonFromLoggedIn(Worker *sender, const QJsonObject jsonObj){

	QJsonValue jsonValue = jsonObj.value("type");

	if (jsonValue.toString() !=  "message")
		return;

	QJsonValue textValue = jsonObj.value("text");
	if(textValue.isNull())
		return;

	QString text = textValue.toString();

	QJsonValue timeValue = jsonObj.value("time");
	if (timeValue.isNull() || !timeValue.isString())
		return;

	QString time = timeValue.toString();

	QJsonObject message;
	message["type"] = "message";
	message["text"] = text;
	message["sender"] = sender->UserName();
	message["time"] = time;

	Broadcast(message, sender);
}


void ChatServer::UserDisconnected(Worker *sender){
	clients.removeAll(sender);
	if (!sender->UserName().isEmpty()){
		QJsonObject disconnectedMessage;
		disconnectedMessage["type"] = "userDisconnected";
		disconnectedMessage["username"] = sender->UserName();

		Broadcast(disconnectedMessage, nullptr);
	}

	sender->deleteLater();
}


void ChatServer::StopServer(){
	for (Worker *worker : clients){
		worker->DisconnectFromServer();
	}
}
