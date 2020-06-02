#include "chatwindow.h"
#include "ui_chatwindow.h"

ChatWindow::ChatWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::ChatWindow)
	, client(new ChatClient(this))
	, chatModel(new QStandardItemModel(this))
{
	ui->setupUi(this);
	setFixedSize(579, 425);

	ui->disconnectButton->setVisible(false);

	ui->messageEdit->setEnabled(false);
	ui->sendButton->setEnabled(false);
	ui->changeNameButton->setEnabled(false);

	ui->ipLabel->setVisible(false);
	ui->portLabel->setVisible(false);
	ui->PORT->setVisible(false);
	ui->IP->setVisible(false);

	chatModel->insertColumn(0);
	ui->chatView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	ui->chatView->setModel(chatModel);
	ui->chatView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->chatView->setSelectionMode(QAbstractItemView::NoSelection);


	connect(client, &ChatClient::connectedToHost, this, &ChatWindow::connectedToServer);
	connect(client, &ChatClient::loggedIn, this, &ChatWindow::loggedIn);
	connect(client, &ChatClient::messageReceived, this, &ChatWindow::messageReceived);
	connect(client, &ChatClient::disconnected, this, &ChatWindow::disconnectedFromServer);
	connect(client, &ChatClient::userJoined, this, &ChatWindow::userJoined);
	connect(client, &ChatClient::userLeft, this, &ChatWindow::userLeft);
	connect(client, &ChatClient::loginError, this, &ChatWindow::loginFailed);
	connect(client, &ChatClient::userChangedName, this, &ChatWindow::userChangedName);
	connect(client, &ChatClient::changedName, this, &ChatWindow::changeName);
	connect(client, &ChatClient::errorOccured, this, &ChatWindow::handlingErrors);

	connect(ui->changeNameButton, &QPushButton::clicked, this, &ChatWindow::tryChangeName);
	connect(ui->connectButton, &QPushButton::clicked, this, &ChatWindow::attemptConnection);
	connect(ui->disconnectButton, &QPushButton::clicked, this, &ChatWindow::disconnectFromServer);
	connect(ui->sendButton, &QPushButton::clicked, this, &ChatWindow::sendMessage);
	connect(ui->messageEdit, &QLineEdit::returnPressed, this, &ChatWindow::sendMessage);
}

ChatWindow::~ChatWindow()
{
	delete ui;
}


void ChatWindow::attemptConnection(){

	ConnectionDialog attemptConnect(this);

	if(attemptConnect.exec() == QDialog::Rejected){

		ui->sendButton->setEnabled(false);
		ui->messageEdit->setEnabled(false);
		ui->chatView->setEnabled(false);
		ui->connectButton->setEnabled(true);
		ui->disconnectButton->setVisible(false);
		lastUserName.clear();

		return;
	}

	hostAddress = attemptConnect.getHostAddress();
	port = attemptConnect.getPort();

	if(hostAddress.isEmpty() || port == 0){
		restartButtonState();
		return;
	}

	ui->connectButton->setEnabled(false);
	client->connectToServer(QHostAddress(hostAddress), port);
}


void ChatWindow::connectedToServer(){

	userName = QInputDialog::getText(
				this,
				tr("Choose UserName"),
				tr("UserName")
				);

	if (userName.isEmpty()){
		client->disconnectFromServer();
		return;
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

	ui->connectButton->setVisible(false);
	ui->disconnectButton->setVisible(true);
	ui->ipLabel->setVisible(true);
	ui->portLabel->setVisible(true);

	ui->IP->setText(hostAddress);
	ui->PORT->setText(QString::number(port));
	ui->PORT->setVisible(true);
	ui->IP->setVisible(true);
	ui->changeNameButton->setEnabled(true);

	ui->userNameLabel->setText(userName);
	ui->sendButton->setEnabled(true);
	ui->messageEdit->setEnabled(true);
	ui->chatView->setEnabled(true);

	int newRow = chatModel->rowCount();
	chatModel->insertRow(newRow);
	chatModel->setData(chatModel->index(newRow, 0), tr("Welcome to Chat!"));
	QFont boldFont;
	chatModel->setData(chatModel->index(newRow, 0), boldFont, Qt::FontRole);
	chatModel->setData(chatModel->index(newRow, 0), Qt::AlignCenter, Qt::TextAlignmentRole);
	chatModel->setData(chatModel->index(newRow, 0), QBrush(Qt::blue), Qt::ForegroundRole);
	ui->chatView->scrollToBottom();


}


void ChatWindow::messageReceived(const QString &sender, const QString &text, const QString &time){

	int newRow = chatModel->rowCount();

	if(sender != lastUserName){
		lastUserName = sender;

		QFont boldFont;
		boldFont.setBold(true);
		boldFont.setPointSize(13);

		chatModel->insertRows(newRow, 2);

		chatModel->setData(chatModel->index(newRow, 0), sender + ':');

		chatModel->setData(chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignVCenter), Qt::TextAlignmentRole);

		chatModel->setData(chatModel->index(newRow, 0), boldFont, Qt::FontRole);
		++newRow;

		lastMinuteMessage = time;
		QFont boldFon2;
		boldFon2.setPointSize(6);
		chatModel->setData(chatModel->index(newRow, 0), time);
		chatModel->setData(chatModel->index(newRow, 0), boldFon2, Qt::FontRole);
		chatModel->setData(chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignBottom), Qt::TextAlignmentRole);
		newRow++;
		chatModel->insertRow(newRow);
	}
	else{

		chatModel->insertRow(newRow);
	}

	if (time != lastMinuteMessage){
		lastMinuteMessage = time;
		QFont boldFont;
		boldFont.setPointSize(6);
		chatModel->setData(chatModel->index(newRow, 0), time);
		chatModel->setData(chatModel->index(newRow, 0), boldFont, Qt::FontRole);
		chatModel->setData(chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignBottom), Qt::TextAlignmentRole);
		newRow++;
		chatModel->insertRow(newRow);
	}

	chatModel->setData(chatModel->index(newRow, 0), text);
	chatModel->setData(chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignTop), Qt::TextAlignmentRole);

	ui->chatView->scrollToBottom();

}


void ChatWindow::sendMessage(){

	if(ui->messageEdit->text().isEmpty())
		return;

	QString time = QTime::currentTime().toString("hh:mm");
	int newRow = chatModel->rowCount();

	if (time != myLastMinuteMessage){

		myLastMinuteMessage = time;

		chatModel->insertRows(newRow, 2);
		QFont smallFont;
		smallFont.setPointSize(6);
		chatModel->setData(chatModel->index(newRow, 0), time);
		chatModel->setData(chatModel->index(newRow, 0), smallFont, Qt::FontRole);
		chatModel->setData(chatModel->index(newRow, 0), int(Qt::AlignRight | Qt::AlignBottom), Qt::TextAlignmentRole);
		newRow++;
	}
	else{

		chatModel->insertRow(newRow);
	}

	client->sendMessage(ui->messageEdit->text(), time);

	chatModel->setData(chatModel->index(newRow, 0), ui->messageEdit->text());
	chatModel->setData(chatModel->index(newRow, 0), int(Qt::AlignRight | Qt::AlignVCenter), Qt::TextAlignmentRole);

	ui->messageEdit->clear();
	ui->chatView->scrollToBottom();
	lastUserName.clear();
}


void ChatWindow::disconnectedFromServer(){
	if (!Idisconnect){
		QMessageBox::warning(this, tr("Disconnected"), tr("The host terminated the connection"));
	}

	restartButtonState();
}


void ChatWindow::disconnectFromServer(){

	Idisconnect = true;
	client->disconnectFromServer();

	Idisconnect = false;
	QMessageBox msgBox;
	msgBox.setText("Disconneted from Server succesfully!");
	msgBox.setInformativeText("Do you want save your chat history?");
	msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
	msgBox.setDefaultButton(QMessageBox::Save);
	int answer = msgBox.exec();

	switch (answer) {
	case QMessageBox::Save:
			break;
	case QMessageBox::Discard:
		chatModel->removeRows(0, chatModel->rowCount());
		break;
	}

	restartButtonState();
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


void ChatWindow::tryChangeName(){
	QMessageBox msgBox;
	msgBox.setText("Are you sure you wand to change UserName?");
	msgBox.setInformativeText("All chat members will see this changes!");
	QPushButton *changeBtn = msgBox.addButton("Change", QMessageBox::YesRole);
	QPushButton *discardBtn = msgBox.addButton("Cancel", QMessageBox::NoRole);
	msgBox.setDefaultButton(changeBtn);

	msgBox.exec();
	if (msgBox.clickedButton() == discardBtn){
		return;
	}
	newName();
}


void ChatWindow::newName(){
	QString newUserName = QInputDialog::getText(
				this,
				tr("Choose new UserName"),
				tr("UserName")
				);

	if (newUserName.isEmpty()){
		QMessageBox::warning(this, "Change UserName Error", "UserName can't be empty!");
		return;
	}

	client->changeName(userName, newUserName);
}


void ChatWindow::userChangedName(const QString &oldName, const QString &newName){
	int newRow = chatModel->rowCount();

	chatModel->insertRow(newRow);

	chatModel->setData(chatModel->index(newRow, 0), tr("Be carefull! User <%1> changed name to <%2>").arg(oldName).arg(newName));
	chatModel->setData(chatModel->index(newRow, 0), Qt::AlignCenter, Qt::TextAlignmentRole);
	QColor color(255, 0, 204);
	chatModel->setData(chatModel->index(newRow, 0), QBrush(color), Qt::ForegroundRole);

	ui->chatView->scrollToBottom();
	lastUserName.clear();
}


void ChatWindow::changeName(const QString &newName){
	this->userName = newName;

	ui->userNameLabel->setText(newName);
}


void ChatWindow::handlingErrors(const QString &errorReason){
	if (errorReason == "User with that name already exists!"){
		QMessageBox::warning(this, "Duplicate UserName!", errorReason + ", choose another one!");
		return;
	}
	else if(errorReason == "Can't connect to that host!"){
		QMessageBox::warning(this, "Connecting Error", errorReason + ". Try another one!");
		restartButtonState();
		return;
	}
}



void ChatWindow::restartButtonState(){

	ui->userNameLabel->setText("__________");

	ui->changeNameButton->setEnabled(false);
	ui->connectButton->setVisible(true);
	ui->disconnectButton->setVisible(false);
	ui->ipLabel->setVisible(false);
	ui->portLabel->setVisible(false);
	ui->PORT->setVisible(false);
	ui->IP->setVisible(false);
	ui->PORT->setText("");
	ui->PORT->setText("");
	ui->sendButton->setEnabled(false);
	ui->messageEdit->setEnabled(false);

	ui->chatView->setEnabled(false);
	ui->connectButton->setEnabled(true);

	lastUserName.clear();
}
