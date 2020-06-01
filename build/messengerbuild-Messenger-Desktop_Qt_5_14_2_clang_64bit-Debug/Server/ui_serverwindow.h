/********************************************************************************
** Form generated from reading UI file 'serverwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWINDOW_H
#define UI_SERVERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWindow
{
public:
    QWidget *centralwidget;
    QPushButton *startServerButton;
    QPushButton *stopServerButton;
    QPlainTextEdit *logEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *serverStateLabel;
    QLabel *ipValueLabel;
    QLabel *portValueLabel;
    QCheckBox *ipCheckBox;
    QCheckBox *portCheckBox;
    QLineEdit *ipEdit;
    QLineEdit *portEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ServerWindow)
    {
        if (ServerWindow->objectName().isEmpty())
            ServerWindow->setObjectName(QString::fromUtf8("ServerWindow"));
        ServerWindow->resize(589, 395);
        centralwidget = new QWidget(ServerWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        startServerButton = new QPushButton(centralwidget);
        startServerButton->setObjectName(QString::fromUtf8("startServerButton"));
        startServerButton->setGeometry(QRect(30, 230, 111, 51));
        stopServerButton = new QPushButton(centralwidget);
        stopServerButton->setObjectName(QString::fromUtf8("stopServerButton"));
        stopServerButton->setGeometry(QRect(30, 290, 111, 51));
        logEdit = new QPlainTextEdit(centralwidget);
        logEdit->setObjectName(QString::fromUtf8("logEdit"));
        logEdit->setGeometry(QRect(190, 10, 391, 331));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 21, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 31, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 20, 51, 21));
        serverStateLabel = new QLabel(centralwidget);
        serverStateLabel->setObjectName(QString::fromUtf8("serverStateLabel"));
        serverStateLabel->setGeometry(QRect(70, 20, 81, 21));
        ipValueLabel = new QLabel(centralwidget);
        ipValueLabel->setObjectName(QString::fromUtf8("ipValueLabel"));
        ipValueLabel->setGeometry(QRect(60, 50, 111, 16));
        portValueLabel = new QLabel(centralwidget);
        portValueLabel->setObjectName(QString::fromUtf8("portValueLabel"));
        portValueLabel->setGeometry(QRect(60, 70, 111, 16));
        ipCheckBox = new QCheckBox(centralwidget);
        ipCheckBox->setObjectName(QString::fromUtf8("ipCheckBox"));
        ipCheckBox->setEnabled(true);
        ipCheckBox->setGeometry(QRect(10, 100, 151, 22));
        ipCheckBox->setChecked(true);
        portCheckBox = new QCheckBox(centralwidget);
        portCheckBox->setObjectName(QString::fromUtf8("portCheckBox"));
        portCheckBox->setGeometry(QRect(10, 160, 141, 22));
        portCheckBox->setChecked(true);
        ipEdit = new QLineEdit(centralwidget);
        ipEdit->setObjectName(QString::fromUtf8("ipEdit"));
        ipEdit->setEnabled(false);
        ipEdit->setGeometry(QRect(30, 130, 113, 24));
        ipEdit->setReadOnly(true);
        portEdit = new QLineEdit(centralwidget);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));
        portEdit->setEnabled(false);
        portEdit->setGeometry(QRect(30, 190, 71, 24));
        portEdit->setReadOnly(true);
        ServerWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ServerWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 589, 22));
        ServerWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ServerWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ServerWindow->setStatusBar(statusbar);

        retranslateUi(ServerWindow);

        QMetaObject::connectSlotsByName(ServerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ServerWindow)
    {
        ServerWindow->setWindowTitle(QCoreApplication::translate("ServerWindow", "ServerWindow", nullptr));
        startServerButton->setText(QCoreApplication::translate("ServerWindow", "Start Server", nullptr));
        stopServerButton->setText(QCoreApplication::translate("ServerWindow", "Stop Server", nullptr));
        label->setText(QCoreApplication::translate("ServerWindow", "IP :", nullptr));
        label_2->setText(QCoreApplication::translate("ServerWindow", "Port :", nullptr));
        label_3->setText(QCoreApplication::translate("ServerWindow", "STATE:", nullptr));
        serverStateLabel->setText(QCoreApplication::translate("ServerWindow", "PAUSED", nullptr));
        ipValueLabel->setText(QCoreApplication::translate("ServerWindow", "--------", nullptr));
        portValueLabel->setText(QCoreApplication::translate("ServerWindow", "--------", nullptr));
        ipCheckBox->setText(QCoreApplication::translate("ServerWindow", "Default IP", nullptr));
        portCheckBox->setText(QCoreApplication::translate("ServerWindow", "Default Port", nullptr));
        ipEdit->setText(QCoreApplication::translate("ServerWindow", "127.0.0.1", nullptr));
        portEdit->setText(QCoreApplication::translate("ServerWindow", "9999", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerWindow: public Ui_ServerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWINDOW_H
