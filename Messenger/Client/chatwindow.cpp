#include "chatwindow.h"
#include "ui_chatwindow.h"

ChatWindow::ChatWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::ChatWindow)
	, client(new ChatClient(this))
	, chatModel(new QStandardItemModel(this))
{
	ui->setupUi(this);

	ui->messageEdit->setEnabled(false);
	ui->sendButton->setEnabled(false);


	chatModel->insertColumn(0);

	ui->chatView->setModel(chatModel);


	connect(client, &ChatClient::connectedToHost, this, &ChatWindow::connectedToServer);
	connect(client, &ChatClient::loggedIn, this, &ChatWindow::loggedIn);
	connect(client, &ChatClient::messageReceived, this, &ChatWindow::messageReceived);
	connect(client, &ChatClient::disconnected, this, &ChatWindow::disconnectedFromServer);
	connect(client, &ChatClient::userJoined, this, &ChatWindow::userJoined);
	connect(client, &ChatClient::userLeft, this, &ChatWindow::userLeft);
	connect(client, &ChatClient::loginError, this, &ChatWindow::loginFailed);

	connect(ui->connectButton, &QPushButton::clicked, this, &ChatWindow::attemptConnection);
	connect(ui->sendButton, &QPushButton::clicked, this, &ChatWindow::sendMessage);
	connect(ui->messageEdit, &QLineEdit::returnPressed, this, &ChatWindow::sendMessage);
}

ChatWindow::~ChatWindow()
{
	delete ui;
}


void ChatWindow::attemptConnection(){
	const QString hostAddress = QInputDialog::getText(
				this,
				tr("Choose Server"),
				tr("Server Address"),
				QLineEdit::Normal,
				QString("127.0.0.1")
				);
	if (hostAddress.isEmpty()){
		return;
	}
	ui->connectButton->setEnabled(false);
	client->connectToServer(QHostAddress(hostAddress), 9999);
}


void ChatWindow::connectedToServer(){

	QString userName = QInputDialog::getText(
				this,
				tr("Choose UserName"),
				tr("UserName")
				);

	if (userName.isEmpty()){
		client->disconnectFromServer();
	}

	attemptLogin(userName);

}


void ChatWindow::attemptLogin(const QString &userName){
	client->login(userName);
}


void ChatWindow::loginFailed(const QString &reason){
	QMessageBox::critical(this, tr("Login Error"), reason);
	connectedToServer();
}


void ChatWindow::loggedIn(){
	ui->sendButton->setEnabled(true);
	ui->messageEdit->setEnabled(true);
	ui->chatView->setEnabled(true);

}


void ChatWindow::messageReceived(const QString &sender, const QString &text){

	int newRow = chatModel->rowCount();

	if(sender != lastUserName){
		lastUserName = sender;

		QFont boldFont;
		boldFont.setBold(true);

		chatModel->insertRows(newRow, 2);

		chatModel->setData(chatModel->index(newRow, 0), sender + ':');

		chatModel->setData(chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignVCenter), Qt::TextAlignmentRole);

		chatModel->setData(chatModel->index(newRow, 0), boldFont, Qt::FontRole);

		++newRow;
	}
	else{
		chatModel->insertRow(newRow);
	}

	chatModel->setData(chatModel->index(newRow, 0), text);
	chatModel->setData(chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignVCenter), Qt::TextAlignmentRole);

	ui->chatView->scrollToBottom();

}


void ChatWindow::sendMessage(){
	client->sendMessage(ui->messageEdit->text());

	const int newRow = chatModel->rowCount();
	chatModel->insertRow(newRow);

	chatModel->setData(chatModel->index(newRow, 0), ui->messageEdit->text());

	chatModel->setData(chatModel->index(newRow, 0), int(Qt::AlignRight | Qt::AlignVCenter), Qt::TextAlignmentRole);

	ui->messageEdit->clear();

	ui->chatView->scrollToBottom();

	lastUserName.clear();
}


void ChatWindow::disconnectedFromServer(){
	QMessageBox::warning(this, tr("Disconnected"), tr("The host terminated the connection"));

	ui->sendButton->setEnabled(false);
	ui->messageEdit->setEnabled(false);

	ui->chatView->setEnabled(false);
	ui->connectButton->setEnabled(true);

	lastUserName.clear();
}


void ChatWindow::userJoined(const QString &userName){

	int newRow = chatModel->rowCount();

	chatModel->insertRow(newRow);
	chatModel->setData(chatModel->index(newRow, 0), tr("%1 Joined the chat").arg(userName));

	 chatModel->setData(chatModel->index(newRow, 0), Qt::AlignCenter, Qt::TextAlignmentRole);

	 chatModel->setData(chatModel->index(newRow, 0), QBrush(Qt::blue), Qt::ForegroundRole);

	 ui->chatView->scrollToBottom();

	 lastUserName.clear();



}


void ChatWindow::userLeft(const QString &userName){
	const int newRow = chatModel->rowCount();
	chatModel->insertRow(newRow);

	chatModel->setData(chatModel->index(newRow, 0), tr("%1 Left the Chat").arg(userName));

	chatModel->setData(chatModel->index(newRow, 0), Qt::AlignCenter, Qt::TextAlignmentRole);

	chatModel->setData(chatModel->index(newRow, 0), QBrush(Qt::red), Qt::ForegroundRole);

	ui->chatView->scrollToBottom();

	lastUserName.clear();


}


