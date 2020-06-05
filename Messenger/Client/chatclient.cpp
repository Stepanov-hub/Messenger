#include "chatclient.h"

ChatClient::ChatClient(QObject *parent) : QObject(parent), clientSocket(new QTcpSocket(this))
{
	connect(clientSocket, &QTcpSocket::connected, this, &ChatClient::connectedToHost);
	connect(clientSocket, &QTcpSocket::readyRead, this, &ChatClient::onReadyRead);
	connect(clientSocket, &QTcpSocket::disconnected, this, &ChatClient::disconnected);
}


void ChatClient::connectToServer(const QHostAddress &hostAddress, quint16 port){
	clientSocket->connectToHost(hostAddress, port);
	clientSocket->waitForConnected(3000);

	if (clientSocket->state() == QAbstractSocket::UnconnectedState)
		emit errorOccured("Can't connect to that host!");

}


void ChatClient::disconnectFromServer(){
	clientSocket->disconnectFromHost();
}


void ChatClient::login(const QString &userName){
	if (clientSocket->state() == QAbstractSocket::ConnectedState){

		QDataStream clientStream(clientSocket);

		QJsonObject loginMessage;
		loginMessage["type"] = "login";
		loginMessage["username"] = userName;
		this->userName = userName;

		clientStream << QJsonDocument(loginMessage).toJson();
	}
}


void ChatClient::changeName(const QString &oldName, const QString &newName){
	if (clientSocket->state() == QAbstractSocket::ConnectedState){

		QDataStream clientStream(clientSocket);

		QJsonObject newNameMessage;
		newNameMessage["type"] = "changename";
		newNameMessage["oldName"] = oldName;
		newNameMessage["newName"] = newName;
		this->userName = newName;

		clientStream << QJsonDocument(newNameMessage).toJson();
	}
}


void ChatClient::sendMessage(const QString &text, const QString &time){
	if (text.isEmpty()){
		return;
	}

	QDataStream clientStream(clientSocket);

	QJsonObject message;

	message["type"] = "message";
	message["text"] = text;
	message["time"] = time;

	clientStream << QJsonDocument(message).toJson();


}


void ChatClient::onReadyRead()
{
	QByteArray jsonArray;
	QDataStream clientStream(clientSocket);

	for(;;){
		clientStream.startTransaction();

		clientStream >> jsonArray;

		if (clientStream.commitTransaction()){
			QJsonParseError jsonError;
			QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonArray, &jsonError);

			if(jsonError.error == QJsonParseError::NoError)	
				if(jsonDoc.isObject())
					jsonReceived(jsonDoc.object());
		}
		else
			break;
	}
}


void ChatClient::jsonReceived(const QJsonObject &docObj)
{
	const QJsonValue typeValue = docObj.value("type");
	if(typeValue.isNull()){
		return;
	}

	if(typeValue.toString() == "login"){
		const QJsonValue loginValue = docObj.value("success");
		if(loginValue.isNull() || !loginValue.isBool()){
			return;
		}

		bool loginSuccess = loginValue.toBool();
		if (loginSuccess){
		   emit loggedIn();
			return;
		}

		const QJsonValue reasonValue = docObj.value("reason");
		if (reasonValue.isNull() || !reasonValue.isString()){
			return;
		}
		this->userName = "__________";
		emit loginError(reasonValue.toString());

	}

	else if(typeValue.toString() == "message"){
		const QJsonValue textValue = docObj.value("text");
		if(textValue.isNull() || !textValue.isString()){
			return;
		}

		const QJsonValue senderValue = docObj.value("sender");
		if(senderValue.isNull() || !textValue.isString()){
			return;
		}

		const QJsonValue timeValue = docObj.value("time");
		if(timeValue.isNull() || !timeValue.isString()){
			return;
		}
		QString time = timeValue.toString();
		QString text = textValue.toString();
		QString sender = senderValue.toString();

		emit messageReceived(sender, text, time);

	}
	else if(typeValue.toString() == "newUser"){

		const QJsonValue userNameValue = docObj.value("username");

		if(userNameValue.isNull() || !userNameValue.isString()){
			return;
		}
		QString userName = userNameValue.toString();

		emit userJoined(userName);
	}
	else if(typeValue.toString() == "userDisconnected"){

		const QJsonValue userNameValue = docObj.value("username");
		if (userNameValue.isNull() || !userNameValue.isString()){
			return;
		}

		QString userName = userNameValue.toString();

		emit userLeft(userName);
	}
	else if(typeValue.toString() == "changeName"){
		const QJsonValue oldNameValue = docObj.value("oldName");
		const QJsonValue newNameValue = docObj.value("newName");

		if (oldNameValue.isNull() || !oldNameValue.isString() || newNameValue.isNull() || !newNameValue.isString()){
			return;
		}

		const QString oldName = oldNameValue.toString();
		const QString newName = newNameValue.toString();

		emit userChangedName(oldName, newName);
	}

	if (typeValue.toString() == "resultNameChanged"){
		const QJsonValue successValue = docObj.value("success");
		if (successValue.isNull() || !successValue.isBool()){
			return;
		}

		bool success = successValue.toBool();

		if(success){
			QJsonValue newNameValue = docObj.value("newName");
			if(newNameValue.isNull() || !newNameValue.isString()){
				return;
			}

			QString newName = newNameValue.toString();
			emit changedName(newName);
		}
		else{
			const QJsonValue reasonValue = docObj.value("reason");
			if(reasonValue.isNull() || !reasonValue.isString()){
				return;
			}
			const QString errorReason = reasonValue.toString();

			emit errorOccured(errorReason);
		}
	}

}
