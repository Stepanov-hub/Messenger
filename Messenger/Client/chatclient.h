#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

#include <QDataStream>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>


class ChatClient : public QObject
{
	Q_OBJECT
public:
	explicit ChatClient(QObject *parent = nullptr);

	void connectToServer(const QHostAddress &hostAddress, quint16 port);
	void disconnectFromServer();
	void login(const QString &userName);
	void sendMessage(const QString &text);
	void jsonReceived(const QJsonObject &docObj);

public slots:
	void onReadyRead();

signals:
	void connectedToHost();
	void disconnected();
	void loggedIn();
	void loginError(const QString &reason);
	void messageReceived(QString sender, QString message);
	void userJoined(const QString userName);
	void userLeft(const QString userName);


private:
	QTcpSocket *clientSocket;


};

#endif // CHATCLIENT_H
