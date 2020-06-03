#include "serverwindow.h"
#include "ui_serverwindow.h"

ServerWindow::ServerWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::ServerWindow)
	, server(new ChatServer)
{
	ui->setupUi(this);

	setFixedSize(589, 395);

	ui->logEdit->setReadOnly(true);
	ui->stopServerButton->setEnabled(false);

	connect(ui->startServerButton, &QPushButton::clicked, this, &ServerWindow::StartButtonClicked);
	connect(ui->stopServerButton, &QPushButton::clicked, this, &ServerWindow::StopButtonClicked);

	connect(ui->ipCheckBox, &QCheckBox::stateChanged, this, &ServerWindow::ipStateChanged);
	connect(ui->portCheckBox, &QCheckBox::stateChanged, this, &ServerWindow::portStateChanged);

	connect(server, &ChatServer::logMessage, this, &ServerWindow::logMessage);
}


ServerWindow::~ServerWindow()
{
	delete ui;
}


void ServerWindow::logMessage(const QString &msg){
	ui->logEdit->appendPlainText(msg);
}



void ServerWindow::StartButtonClicked(){
	hostAddress = QHostAddress(ui->ipEdit->text());
	port = ui->portEdit->text().toInt();

	if(!server->isListening()){
		if(!server->listen(hostAddress, port)){
			QMessageBox::critical(this, tr("Error"), tr("Unable to start server!"));
			return;
		}
		else{
			logMessage("Server started!\n"
					   "IP: " + hostAddress.toString() +"\n"
						"Port: " + QString::number(port) +"\n");

		}
	}

	setButtsServListn();
}


void ServerWindow::StopButtonClicked(){
	if(server->isListening()){
		server->StopServer();
		server->close();
		logMessage("Server stopped!");
	}

	backButtonsState();
}


void ServerWindow::ipStateChanged(){
	if(ui->ipCheckBox->isChecked()){
		ui->ipEdit->setText("127.0.0.1");
		ui->ipEdit->setEnabled(false);
		ui->ipEdit->setReadOnly(true);
	}
	else{
		ui->ipEdit->setEnabled(true);
		ui->ipEdit->setReadOnly(false);
	}
}


void ServerWindow::portStateChanged(){
	if(ui->portCheckBox->isChecked()){
		ui->portEdit->setText("9999");
		ui->portEdit->setEnabled(false);
		ui->portEdit->setReadOnly(true);
	}
	else{
		ui->portEdit->setEnabled(true);
		ui->portEdit->setReadOnly(false);
	}

}


void ServerWindow::setButtsServListn(){

	ui->startServerButton->setText("Listenning!");

	ui->ipValueLabel->setText(hostAddress.toString());
	ui->portValueLabel->setText(QString::number(port));
	ui->serverStateLabel->setText("WORKING");

	ui->ipCheckBox->setEnabled(false);
	ui->portCheckBox->setEnabled(false);

	ui->ipEdit->setEnabled(false);
	ui->portEdit->setEnabled(false);

	ui->startServerButton->setEnabled(false);
	ui->stopServerButton->setEnabled(!false);
}


void ServerWindow::backButtonsState(){

	ui->startServerButton->setText("Start Server");
	ui->serverStateLabel->setText("PAUSED");
	ui->ipValueLabel->setText("--------");
	ui->portValueLabel->setText("--------");


	ui->ipCheckBox->setEnabled(true);
	ui->portCheckBox->setEnabled(true);

	if (ui->portCheckBox->isChecked()){
		ui->portEdit->setEnabled(false);
		ui->portEdit->setReadOnly(true);
	}
	else{
		ui->portEdit->setEnabled(true);
		ui->portEdit->setReadOnly(false);
	}

	if (ui->ipCheckBox->isChecked()){
		ui->ipEdit->setEnabled(false);
		ui->ipEdit->setReadOnly(true);
	}
	else{
		ui->ipEdit->setEnabled(true);
		ui->ipEdit->setReadOnly(false);
	}

	ui->startServerButton->setEnabled(true);
	ui->stopServerButton->setEnabled(false);
}
