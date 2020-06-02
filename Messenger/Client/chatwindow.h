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
#include "connectiondialog.h"

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


	void messageReceived(const QString &sender, const QString &text, const QString &time);
	void sendMessage();
	void disconnectedFromServer();
	void disconnectFromServer();
	void userJoined(const QString &userName);
	void userLeft(const QString &userName);
	void tryChangeName();
	void userChangedName(const QString &oldName, const QString &newName);
	void changeName(const QString &newName);

	void handlingErrors(const QString &errorReason);

	void loggedIn();
	void loginFailed(const QString &reason);

private:
	void newName();
	void restartButtonState();

private:
	Ui::ChatWindow *ui;
	QString hostAddress;
	quint16 port;

	QString userName;
	QString lastUserName;
	QString lastMinuteMessage;
	QString myLastMinuteMessage;

	QStandardItemModel *chatModel;
	ChatClient *client;

	bool Idisconnect;

};
#endif // CHATWINDOW_H
