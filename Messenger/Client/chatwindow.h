#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTcpSocket>
#include <QDebug>
#include <QHostAddress>

#include <QMessageBox>
#include <QStandardItemModel>
#include <QInputDialog>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>

#include "chatclient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChatWindow; }
QT_END_NAMESPACE

class ChatWindow : public QMainWindow
{
	Q_OBJECT

public:
	ChatWindow(QWidget *parent = nullptr);
	~ChatWindow();

public slots:
	void attemptLogin(const QString &userName);
	void attemptConnection();
	void connectedToServer();


	void messageReceived(const QString &sender, const QString &text);
	void sendMessage();
	void disconnectedFromServer();
	void userJoined(const QString &userName);
	void userLeft(const QString &userName);


	void loggedIn();
	void loginFailed(const QString &reason);

private:
	Ui::ChatWindow *ui;

	QString lastUserName;

	QStandardItemModel *chatModel;
	ChatClient *client;
};
#endif // CHATWINDOW_H
