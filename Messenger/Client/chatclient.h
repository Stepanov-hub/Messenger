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
	// подключение к серверу
	void connectToServer(const QHostAddress &hostAddress, quint16 port);
	// Отключение от сервера
	void disconnectFromServer();
	// Отпраялем сообщение серверу, чтобы проверить уникальность имени
	void login(const QString &userName);
	// Отсылем на сервер сообщение с запросом поменять ник
	void changeName(const QString &oldName, const QString &newName);
	// Отправка сообщения на серверную часть
	void sendMessage(const QString &text, const QString &time);
	// Если полученные данные являются josn + обработка их
	void jsonReceived(const QJsonObject &docObj);

	QString userName;

public slots:
	// Есои на сокете есть данныые, которые возможно прочитать
	void onReadyRead();

signals:
	// Если мы успе
	void connectedToHost();
	// Если соедение с серверной частью потеряно
	void disconnected();
	// Если сервер разрешил подлючиться к серверу
	void loggedIn();
	// Если возникла ошибка при подлючении к серверу
	void loginError(const QString &reason);
	// Если мы получили в json сообещние, которое успешно распарсили
	void messageReceived(QString sender, QString message, QString time);
	// Уведомление, если какой-то пользователь подключился
	void userJoined(const QString userName);
	// Уведомление, если какой-то пользователь отключился
	void userLeft(const QString userName);
	// Если какой-то пользователь сменил ник уведомление
	void userChangedName(const QString &oldName, const QString &newName);
	// Если сервер дал ответ о возможности смены ника
	void changedName(const QString &newName);
	// Если сервер прислал ошибку
	void errorOccured(const QString &reason);


private:
	QTcpSocket *clientSocket;
	bool connectedOnce;
};

#endif // CHATCLIENT_H
