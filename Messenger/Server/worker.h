#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <QDataStream>

#include <QTcpSocket>
#include <QAbstractSocket>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>


class Worker : public QObject
{
	Q_OBJECT
public:
	explicit Worker(QObject *parent = nullptr);

	bool setSocketDescriptor(int handle);
	void SetUserName(QString userName);
	QString UserName();

	void SendJson(const QJsonObject jsonObj);


signals:
	void logMessage(const QString &msg);
	void disconnectedFromServer();
	void jsonReceived(Worker *sender, const QJsonObject jsonObj);

public slots:
	void DisconnectFromServer();
	void onReadyRead();

private:

	QString userName;
	QTcpSocket *serverSocket;
	int socketDescriptor;

};

#endif // WORKER_H
