#include "chatclient.h"

ChatClient::ChatClient(QObject *parent) : QObject(parent), clientSocket(new QTcpSocket(this))
{
	connect(clientSocket, &QTcpSocket::connected, this, &ChatClient::connectedToHost);
	connect(clientSocket, &QTcpSocket::readyRead, this, &ChatClient::onReadyRead);
	connect(clientSocket, &QTcpSocket::disconnected, this, &ChatClient::disconnected);
}


void ChatClient::connectToServer(const QHostAddress &hostAddress, quint16 port){
	clientSocket->connectToHost(hostAddress, port);
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

		clientStream << QJsonDocument(loginMessage).toJson();
	}
}


void ChatClient::sendMessage(const QString &text){
	if (text.isEmpty()){
		return;
	}

	QDataStream clientStream(clientSocket);

	QJsonObject message;

	message["type"] = "message";
	message["text"] = text;

	clientStream << QJsonDocument(message).toJson();


}


void ChatClient::onReadyRead()
{
	QByteArray jsonArray;
	//clientSocket->flush();

	QDataStream clientStream(clientSocket);

	clientStream >> jsonArray;

	QJsonParseError jsonError;
	QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonArray, &jsonError);

	if(jsonError.error == QJsonParseError::NoError)
	{
		if(jsonDoc.isObject()){
//			qDebug() << "Object success" << QString::fromUtf8(jsonDoc.toJson());
			jsonReceived(jsonDoc.object());
		}
		else{
//			qDebug() << "json isn't object! " << jsonArray;
		}
	}
	else{
//		qDebug() << "Error with pasing json: " << jsonError.errorString()
//				 << "\n From: " << jsonArray;
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
		QString text = textValue.toString();
		QString sender = senderValue.toString();

		emit messageReceived(sender, text);

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

}
