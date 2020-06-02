#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>
#include <QCheckBox>

namespace Ui {
class ConnectionDialog;
}

class ConnectionDialog : public QDialog
{
	Q_OBJECT

public:
	explicit ConnectionDialog(QWidget *parent = nullptr);
	~ConnectionDialog();

	QString getHostAddress();
	quint16 getPort();

public slots:
	void okButtonClicked();
	void cancelButtonClicked();
	void ipCheckBoxChanged();
	void portCheckBoxChanged();

private:
	Ui::ConnectionDialog *ui;
	QString hostAddress;
	quint16 port;
};

#endif // CONNECTIONDIALOG_H
