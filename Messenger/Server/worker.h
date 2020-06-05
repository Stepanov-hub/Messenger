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


// Класс на стороне сервера для взаимодейсвтия с пользователем
class Worker : public QObject
{
	Q_OBJECT
public:
	explicit Worker(QObject *parent = nullptr);

	// устанавливаем дискриптор для клиента
	bool setSocketDescriptor(int handle);
	// Функции для установления имени клиента
	void SetUserName(QString userName);
	// Получение имени
	QString UserName();
	// Отправка сообщения на клиентский сокет
	void SendJson(const QJsonObject jsonObj);


signals:
	// Для отправки сообщения в лог
	void logMessage(const QString &msg);
	// При отключении пользователя
	void disconnectedFromServer();
	// Транслируем сообщение в класс ChatServer, чтобы там его обработать
	void jsonReceived(Worker *sender, const QJsonObject jsonObj);

public slots:
	// Закрваем соединение на сокете
	void DisconnectFromServer();
	// Если у нас имеются новые данные, считываем их, проверяем на json
	void onReadyRead();

private:

	QString userName;
	// Храним сокет
	QTcpSocket *serverSocket;
	int socketDescriptor;

};

#endif // WORKER_H
