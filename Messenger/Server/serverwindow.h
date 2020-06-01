#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "chatserver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ServerWindow; }
QT_END_NAMESPACE

class ServerWindow : public QMainWindow
{
	Q_OBJECT

public:
	ServerWindow(QWidget *parent = nullptr);
	~ServerWindow();

private slots:
	void StartButtonClicked();
	void StopButtonClicked();

	void ipStateChanged();
	void portStateChanged();

	void logMessage(const QString &msg);

private:
	Ui::ServerWindow *ui;

	ChatServer *server;
	QHostAddress hostAddress;
	quint16 port;

	void setButtsServListn();
	void backButtonsState();
};
#endif // SERVERWINDOW_H
