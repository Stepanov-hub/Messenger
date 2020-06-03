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
        ServerWindow->setStyleSheet(QString::fromUtf8("/*-----QWidget-----*/   \n"
"QWidget\n"
"{\n"
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
"	min-width: 80px;\n"
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
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color"
                        ": qlineargradient(spread:repeat, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(74, 74, 74, 255),stop:1 rgba(49, 49, 49, 255));\n"
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
"\n"
"/*-----QPlainTExtEdit-----*/\n"
"QPlainTextEdit\n"
"{\n"
"	background-color: #131313;\n"
"	color : #eee;\n"
"	border: 1px solid #343434;\n"
"	border-radius: 8px;\n"
"	padding: 3px;\n"
"	padding-left: 5px;\n"
"\n"
"}\n"
"\n"
"/*-----QLabel-----*/\n"
"QLabel\n"
"{\n"
"	background-color: transparent;\n"
"	color: #fff;\n"
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
""
                        "	background-color: rgb(47, 49, 49);\n"
"	color : rgb(150, 148, 152)\n"
"\n"
"}\n"
"\n"
"\n"
"/*-----QCheckBox-----*/\n"
"QCheckBox\n"
"{\n"
"	background-color: transparent;\n"
"    color: lightgray;\n"
"	border: none;\n"
"\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover\n"
"{\n"
"	border: 1px solid #b78620; \n"
"	border-radius: 5px;\n"
"\n"
"}\n"
"\n"
"\n"
"QCheckBox::disabled\n"
"{\n"
"	color: #656565;\n"
"\n"
"}\n"
"\n"
"\n"
"QCheckBox::indicator:disabled\n"
"{\n"
"	background-color: #656565;\n"
"	color: #656565;\n"
"    border: 1px solid #656565;\n"
"\n"
"}\n"
"\n"
"\n"
""));
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
