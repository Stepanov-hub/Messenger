#ifndef MYSERVER_H
#define MYSERVER_H

//#include <QThreadPool>
#include <QTcpServer>

#include <QDebug>
#include <QObject>
#include <QList>

#include "worker.h"


class ChatServer : public QTcpServer
{
	Q_OBJECT

public:
	explicit ChatServer(QObject *parent = nullptr);

	void StopServer();

signals:
	void logMessage(const QString &msg);

public slots:
	void UserDisconnected(Worker *sender);

private slots:
	void JsonReceived(Worker *sender, const QJsonObject jsonObj);
	void Broadcast(const QJsonObject jsonObj, Worker *exclude);

protected:
	void incomingConnection(qintptr handle) override;

private:
	void JsonFromLoggedIn(Worker *sender, const QJsonObject jsonObj);
	void JsonFromLoggedOut(Worker *sender, const QJsonObject jsonObj);

	void SendJson(Worker *receiver, const QJsonObject jsonObj);


	QList <Worker *> clients;
	//QThreadPool *threadPool;

};

#endif // MYSERVER_H
