/********************************************************************************
** Form generated from reading UI file 'connectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONDIALOG_H
#define UI_CONNECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectionDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *ipEdit;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpinBox *portSpinBox;
    QCheckBox *ipCheckBox;
    QCheckBox *portCheckBox;
    QPushButton *OkButton;
    QPushButton *cancelButton;
    QFrame *line;

    void setupUi(QDialog *ConnectionDialog)
    {
        if (ConnectionDialog->objectName().isEmpty())
            ConnectionDialog->setObjectName(QString::fromUtf8("ConnectionDialog"));
        ConnectionDialog->resize(251, 162);
        ConnectionDialog->setStyleSheet(QString::fromUtf8("/*-----QLineEdit-----*/\n"
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
"/*-----QSpinBox & QDateTimeEdit-----*/\n"
"QSpinBox\n"
"{\n"
"    selection-background-color: darkgray;\n"
"	background-color: #131313;\n"
"	color : #eee;\n"
"	border: 1px solid #343434;\n"
"	border-radius: 4px;\n"
"	padding: 3px;\n"
"	padding-left: 5px;\n"
"\n"
"}\n"
"\n"
"QSpinBox:disabled\n"
"{\n"
"    background-color: rgb(47, 49, 49);\n"
"	color : rgb(150, 148, 152);\n"
"}\n"
"\n"
"QSpinBox::up-button\n"
"{\n"
"	border-top-right-radius:2px;\n"
"	background-color: #777777;\n"
"    width: 16px; \n"
"    border-width: 1px;\n"
"\n"
"}\n"
"\n"
"\n"
"QSpinBox::up-button:hover\n"
"{\n"
"	background-color: #585858;\n"
"\n"
"}\n"
"\n"
""
                        "\n"
"QSpinBox::up-button:pressed\n"
"{\n"
"	background-color: #252525;\n"
"    width: 16px; \n"
"    border-width: 1px;\n"
"\n"
"}\n"
"\n"
"\n"
"QSpinBox::down-button\n"
"{\n"
"	border-bottom-right-radius:2px;\n"
"	background-color: rgb(182, 179, 184);\n"
"    width: 16px; \n"
"    border-width: 1px;\n"
"\n"
"}\n"
"\n"
"\n"
"QSpinBox::down-button:hover\n"
"{\n"
"	background-color: #585858;\n"
"\n"
"}\n"
"\n"
"\n"
"QSpinBox::down-button:pressed\n"
"{\n"
"	background-color: #252525;\n"
"    width: 16px; \n"
"    border-width: 1px;\n"
"\n"
"}\n"
""));
        layoutWidget = new QWidget(ConnectionDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 70, 229, 83));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        ipEdit = new QLineEdit(layoutWidget);
        ipEdit->setObjectName(QString::fromUtf8("ipEdit"));
        ipEdit->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ipEdit->sizePolicy().hasHeightForWidth());
        ipEdit->setSizePolicy(sizePolicy1);
        ipEdit->setDragEnabled(false);
        ipEdit->setReadOnly(false);
        ipEdit->setClearButtonEnabled(false);

        horizontalLayout->addWidget(ipEdit);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(8, -1, 50, -1);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        portSpinBox = new QSpinBox(layoutWidget);
        portSpinBox->setObjectName(QString::fromUtf8("portSpinBox"));
        portSpinBox->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(portSpinBox->sizePolicy().hasHeightForWidth());
        portSpinBox->setSizePolicy(sizePolicy3);
        portSpinBox->setMaximum(10000);
        portSpinBox->setValue(9999);

        gridLayout->addWidget(portSpinBox, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        ipCheckBox = new QCheckBox(ConnectionDialog);
        ipCheckBox->setObjectName(QString::fromUtf8("ipCheckBox"));
        ipCheckBox->setGeometry(QRect(10, 10, 86, 22));
        ipCheckBox->setChecked(true);
        portCheckBox = new QCheckBox(ConnectionDialog);
        portCheckBox->setObjectName(QString::fromUtf8("portCheckBox"));
        portCheckBox->setGeometry(QRect(10, 30, 94, 22));
        portCheckBox->setChecked(true);
        OkButton = new QPushButton(ConnectionDialog);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));
        OkButton->setGeometry(QRect(160, 10, 71, 24));
        cancelButton = new QPushButton(ConnectionDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(160, 40, 71, 24));
        line = new QFrame(ConnectionDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 70, 260, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        retranslateUi(ConnectionDialog);

        QMetaObject::connectSlotsByName(ConnectionDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectionDialog)
    {
        ConnectionDialog->setWindowTitle(QCoreApplication::translate("ConnectionDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ConnectionDialog", "Hostname/IP :", nullptr));
        ipEdit->setText(QCoreApplication::translate("ConnectionDialog", "127.0.0.1", nullptr));
        label_2->setText(QCoreApplication::translate("ConnectionDialog", "Port :", nullptr));
        ipCheckBox->setText(QCoreApplication::translate("ConnectionDialog", "Default IP", nullptr));
        portCheckBox->setText(QCoreApplication::translate("ConnectionDialog", "Default Port", nullptr));
        OkButton->setText(QCoreApplication::translate("ConnectionDialog", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("ConnectionDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectionDialog: public Ui_ConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONDIALOG_H
