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
        centralwidget = new QWidget(ChatWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        chatView = new QListView(centralwidget);
        chatView->setObjectName(QString::fromUtf8("chatView"));
        chatView->setGeometry(QRect(10, 40, 561, 301));
        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(420, 5, 155, 30));
        connectButton->setStyleSheet(QString::fromUtf8("font: 15pt \"Monaco\";"));
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(510, 348, 61, 31));
        messageEdit = new QLineEdit(centralwidget);
        messageEdit->setObjectName(QString::fromUtf8("messageEdit"));
        messageEdit->setGeometry(QRect(10, 350, 490, 25));
        ipLabel = new QLabel(centralwidget);
        ipLabel->setObjectName(QString::fromUtf8("ipLabel"));
        ipLabel->setGeometry(QRect(425, 3, 59, 16));
        portLabel = new QLabel(centralwidget);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));
        portLabel->setGeometry(QRect(425, 19, 59, 16));
        portLabel->setAlignment(Qt::AlignCenter);
        IP = new QLabel(centralwidget);
        IP->setObjectName(QString::fromUtf8("IP"));
        IP->setGeometry(QRect(490, 3, 58, 16));
        PORT = new QLabel(centralwidget);
        PORT->setObjectName(QString::fromUtf8("PORT"));
        PORT->setGeometry(QRect(490, 19, 58, 16));
        disconnectButton = new QPushButton(centralwidget);
        disconnectButton->setObjectName(QString::fromUtf8("disconnectButton"));
        disconnectButton->setGeometry(QRect(304, 5, 111, 30));
        disconnectButton->setStyleSheet(QString::fromUtf8("font: 15pt \"Monaco\";"));
        changeNameButton = new QPushButton(centralwidget);
        changeNameButton->setObjectName(QString::fromUtf8("changeNameButton"));
        changeNameButton->setGeometry(QRect(170, 10, 71, 24));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 148, 19));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 13pt \"Monaco\";\n"
"background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0))"));

        horizontalLayout->addWidget(label);

        userNameLabel = new QLabel(widget);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));

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
        ipLabel->setText(QCoreApplication::translate("ChatWindow", "Server IP:", nullptr));
        portLabel->setText(QCoreApplication::translate("ChatWindow", "Port:", nullptr));
        IP->setText(QString());
        PORT->setText(QString());
        disconnectButton->setText(QCoreApplication::translate("ChatWindow", "Disconnect", nullptr));
        changeNameButton->setText(QCoreApplication::translate("ChatWindow", "Change", nullptr));
        label->setText(QCoreApplication::translate("ChatWindow", "UserName:", nullptr));
        userNameLabel->setText(QCoreApplication::translate("ChatWindow", "__________", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
