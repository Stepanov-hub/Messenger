#include "worker.h"
#include "chatserver.h"

Worker::Worker(QObject *parent) : QObject(parent), serverSocket(new QTcpSocket(this))
{
	connect(serverSocket, &QTcpSocket::disconnected, this, &Worker::disconnectedFromServer);
	connect(serverSocket, &QTcpSocket::readyRead, this, &Worker::onReadyRead);
}


bool Worker::setSocketDescriptor(int handle)
{
	if(!serverSocket->setSocketDescriptor(handle)){

		logMessage("Error: cant't set socket descriptor");
		return false;
	}

	socketDescriptor = handle;
	return true;
}


void Worker::SendJson(const QJsonObject jsonObj){

	QByteArray dataArray = QJsonDocument(jsonObj).toJson();

	emit logMessage("Sending to: " + UserName() + dataArray);

	QDataStream socketStream(serverSocket);
	socketStream << dataArray;

}


void Worker::DisconnectFromServer(){
	serverSocket->disconnectFromHost();
}


void Worker::onReadyRead()
{
	QByteArray buffer;

	QDataStream socketStream(serverSocket);
	socketStream >> buffer;

	QJsonParseError parseError;
	QJsonDocument dataDoc = QJsonDocument::fromJson(buffer, &parseError);

	if(parseError.error == QJsonParseError::NoError){

		if(dataDoc.isObject()){
			emit jsonReceived(this ,dataDoc.object());
		}
		else{
			logMessage("ERROR: Recieved not json object :" + QString::fromUtf8(dataDoc.toJson()));
		}
	}
	else{
		logMessage("ERROR occured when convetring data to jsonDocument!\nData: " + QString::fromUtf8(buffer));
	}
}


void Worker::SetUserName(QString userName){
	this->userName = userName;
}


QString Worker::UserName(){
	return userName;
}
