#include "connectiondialog.h"
#include "ui_connectiondialog.h"

ConnectionDialog::ConnectionDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::ConnectionDialog)
{
	ui->setupUi(this);
	setFixedSize(251, 162);

	connect(ui->ipCheckBox, &QCheckBox::stateChanged, this, &ConnectionDialog::ipCheckBoxChanged);
	connect(ui->portCheckBox, &QCheckBox::stateChanged, this, &ConnectionDialog::portCheckBoxChanged);
	connect(ui->OkButton, &QPushButton::clicked, this, &ConnectionDialog::okButtonClicked);
	connect(ui->cancelButton, &QPushButton::clicked, this, &ConnectionDialog::cancelButtonClicked);
}


void ConnectionDialog::okButtonClicked(){
	hostAddress = ui->ipEdit->text();
	port = ui->portSpinBox->value();
	accept();
}


void ConnectionDialog::cancelButtonClicked(){
	reject();
}


quint16 ConnectionDialog::getPort(){
	return port;
}


QString ConnectionDialog::getHostAddress(){
	return hostAddress;
}


void ConnectionDialog::ipCheckBoxChanged(){
	if(ui->ipCheckBox->isChecked()){
		ui->ipEdit->setEnabled(false);
	}
	else{
		ui->ipEdit->setEnabled(true);
	}
}


void ConnectionDialog::portCheckBoxChanged(){
	if(ui->portCheckBox->isChecked()){
		ui->portSpinBox->setEnabled(false);
	}
	else{
		ui->portSpinBox->setEnabled(true);
	}
}


ConnectionDialog::~ConnectionDialog()
{
	delete ui;
}
