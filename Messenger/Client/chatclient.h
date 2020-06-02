#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QTime>

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
	void changeName(const QString &oldName, const QString &newName);
	void sendMessage(const QString &text, const QString &time);
	void jsonReceived(const QJsonObject &docObj);

	QString userName;

public slots:
	void onReadyRead();

signals:
	void connectedToHost();
	void disconnected();
	void loggedIn();
	void loginError(const QString &reason);
	void messageReceived(QString sender, QString message, QString time);
	void userJoined(const QString userName);
	void userLeft(const QString userName);
	void userChangedName(const QString &oldName, const QString &newName);
	void changedName(const QString &newName);
	void errorOccured(const QString &reason);


private:
	QTcpSocket *clientSocket;

	bool connectedOnce;

};

#endif // CHATCLIENT_H
