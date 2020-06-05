#ifndef MYSERVER_H
#define MYSERVER_H

//#include <QThreadPool>
#include <QTcpServer>

#include <QDebug>
#include <QObject>
#include <QList>

#include "worker.h"

// Основной класс управления сервером
class ChatServer : public QTcpServer
{
	Q_OBJECT

public:
	explicit ChatServer(QObject *parent = nullptr);

	// остановка сервера
	void StopServer();

signals:
	// сигнал при отправке сообщения в лог
	void logMessage(const QString &msg);

public slots:
	// набор действий если пользователь отключился
	void UserDisconnected(Worker *sender);

private slots:
	// Если к нам пришло сообещение в формате josn, обрабатыаем его
	void JsonReceived(Worker *sender, const QJsonObject jsonObj);
	// Трансляция нашего jsonObject на всех пользователей
	void Broadcast(const QJsonObject jsonObj, Worker *exclude);

protected:
	// Обработка входящих подключений
	void incomingConnection(qintptr handle) override;

private:
	// Если пришел json от залогиненного пользователя
	void JsonFromLoggedIn(Worker *sender, const QJsonObject jsonObj);
	// Если пришел   json от нового пользователя
	void JsonFromLoggedOut(Worker *sender, const QJsonObject jsonObj);
	// Передаем jsonObject получателю
	void SendJson(Worker *receiver, const QJsonObject jsonObj);

	// Храним список подключенных пользователей
	QList <Worker *> clients;
	//QThreadPool *threadPool;

};

#endif // MYSERVER_H
