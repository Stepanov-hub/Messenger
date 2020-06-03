/********************************************************************************
** Form generated from reading UI file 'chatwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QWidget *centralwidget;
    QListView *chatView;
    QPushButton *connectButton;
    QPushButton *sendButton;
    QLineEdit *messageEdit;
    QLabel *ipLabel;
    QLabel *portLabel;
    QLabel *IP;
    QLabel *PORT;
    QPushButton *disconnectButton;
    QPushButton *changeNameButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *userNameLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName(QString::fromUtf8("ChatWindow"));
        ChatWindow->resize(579, 425);
        ChatWindow->setStyleSheet(QString::fromUtf8("/*-----QWidget-----*/   \n"
"QWidget\n"
"{\n"
"	/*background-image: url(:/img/img/background.jpg);*/\n"
"	background-color: #3a3a3a;\n"
"	color: #fff;\n"
"	selection-background-color: #b78620;\n"
"	selection-color: #000;\n"
"\n"
"}\n"
"\n"
"\n"
"/*-----QPushButton-----*/\n"
"QPushButton\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(84, 84, 84, 255),stop:1 rgba(59, 59, 59, 255));\n"
"	color: #ffffff;\n"
"	min-width: 70px;\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-radius: 6px;\n"
"	border-color: #051a39;\n"
"	padding: 5px;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::flat\n"
"{\n"
"	background-color: transparent;\n"
"	border: none;\n"
"	color: #fff;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::disabled\n"
"{\n"
"	background-color: #404040;\n"
"	color: #656565;\n"
"	border-color:  rgb(175, 168, 167)    /*#051a39;*/\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::hover\n"
"{\n"
"	background-color: rgba(183, 134, 32, 20%);\n"
"	border: 1px solid #b78620;\n"
"\n"
"}\n"
""
                        "\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(74, 74, 74, 255),stop:1 rgba(49, 49, 49, 255));\n"
"	border: 1px solid #b78620;\n"
"\n"
"}\n"
"\n"
"\n"
"QPushButton::checked\n"
"{\n"
"	background-color: qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(74, 74, 74, 255),stop:1 rgba(49, 49, 49, 255));\n"
"	border: 1px solid #222;\n"
"\n"
"}\n"
"\n"
"/*-----QLineEdit-----*/\n"
"QLineEdit\n"
"{\n"
"	\n"
"	selection-background-color: darkgray;\n"
"	background-color: #131313;\n"
"	color : #eee;\n"
"	border: 1px solid #343434;\n"
"	border-radius: 4px;\n"
"	padding: 3px;\n"
"	padding-left: 5px;\n"
"\n"
"}\n"
"\n"
"\n"
"QLineEdit:disabled\n"
"{\n"
"	background-color: rgb(47, 49, 49);\n"
"	color : rgb(150, 148, 152)\n"
"\n"
"}\n"
"\n"
"\n"
"/*-----QLabel-----*/\n"
"QLabel\n"
"{\n"
"	background-color: transparent;\n"
"	color: #fff;\n"
"\n"
"}\n"
"\n"
"/*-----QListView-----*/\n"
"QListView \n"
"{\n"
"	background-image: url(:/im"
                        "g/img/background.jpg);/*#2d2d2d;*/\n"
"    border : 3px;\n"
"	border-radius: 5px;\n"
"    color: white;\n"
"    show-decoration-selected: 1; \n"
"    outline: 0;\n"
"	border: 1px solid gray;\n"
"\n"
"}\n"
"\n"
"\n"
"QListView::disabled \n"
"{\n"
"	background-image: url(:/img/img/cat10.jpg);\n"
"	/*background-color:  rgb(47, 49, 49);*/\n"
"	color: #1b1b1b;\n"
"    border: 1px solid #656565;\n"
"\n"
"}\n"
""));
        centralwidget = new QWidget(ChatWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        chatView = new QListView(centralwidget);
        chatView->setObjectName(QString::fromUtf8("chatView"));
        chatView->setGeometry(QRect(10, 40, 561, 301));
        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(420, 7, 155, 30));
        connectButton->setStyleSheet(QString::fromUtf8("font: 15pt \"Monaco\";"));
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(510, 348, 62, 30));
        sendButton->setStyleSheet(QString::fromUtf8("min-width: 40px;\n"
"width: 40px;"));
        messageEdit = new QLineEdit(centralwidget);
        messageEdit->setObjectName(QString::fromUtf8("messageEdit"));
        messageEdit->setGeometry(QRect(10, 352, 490, 25));
        ipLabel = new QLabel(centralwidget);
        ipLabel->setObjectName(QString::fromUtf8("ipLabel"));
        ipLabel->setGeometry(QRect(425, 5, 65, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        ipLabel->setFont(font);
        portLabel = new QLabel(centralwidget);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));
        portLabel->setGeometry(QRect(425, 19, 59, 16));
        portLabel->setFont(font);
        portLabel->setAlignment(Qt::AlignCenter);
        IP = new QLabel(centralwidget);
        IP->setObjectName(QString::fromUtf8("IP"));
        IP->setGeometry(QRect(495, 5, 58, 16));
        IP->setFont(font);
        PORT = new QLabel(centralwidget);
        PORT->setObjectName(QString::fromUtf8("PORT"));
        PORT->setGeometry(QRect(495, 19, 58, 16));
        PORT->setFont(font);
        disconnectButton = new QPushButton(centralwidget);
        disconnectButton->setObjectName(QString::fromUtf8("disconnectButton"));
        disconnectButton->setGeometry(QRect(304, 7, 111, 30));
        disconnectButton->setStyleSheet(QString::fromUtf8("font: 15pt \"Monaco\";"));
        changeNameButton = new QPushButton(centralwidget);
        changeNameButton->setObjectName(QString::fromUtf8("changeNameButton"));
        changeNameButton->setGeometry(QRect(160, 7, 92, 30));
        changeNameButton->setStyleSheet(QString::fromUtf8("font-size: 15px;"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 148, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(label);

        userNameLabel = new QLabel(widget);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));
        userNameLabel->setFont(font);

        horizontalLayout->addWidget(userNameLabel);

        ChatWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChatWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 579, 22));
        ChatWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ChatWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChatWindow->setStatusBar(statusbar);

        retranslateUi(ChatWindow);

        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChatWindow)
    {
        ChatWindow->setWindowTitle(QCoreApplication::translate("ChatWindow", "ChatWindow", nullptr));
        connectButton->setText(QCoreApplication::translate("ChatWindow", "Connect", nullptr));
        sendButton->setText(QCoreApplication::translate("ChatWindow", "Send", nullptr));
        messageEdit->setText(QString());
        ipLabel->setText(QCoreApplication::translate("ChatWindow", "Server IP :", nullptr));
        portLabel->setText(QCoreApplication::translate("ChatWindow", "Port :", nullptr));
        IP->setText(QString());
        PORT->setText(QString());
        disconnectButton->setText(QCoreApplication::translate("ChatWindow", "Disconnect", nullptr));
        changeNameButton->setText(QCoreApplication::translate("ChatWindow", "Change \342\232\231\357\270\217", nullptr));
        label->setText(QCoreApplication::translate("ChatWindow", "UserName :", nullptr));
        userNameLabel->setText(QCoreApplication::translate("ChatWindow", "__________", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
