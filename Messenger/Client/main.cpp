#include "chatwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ChatWindow w;

	// классные кнопки орнажевые
//	QFile File1("/Users/kremenevskiy/Desktop/Messenger/Messenger/StyleSheets/Combinear/Combinear.qss");
//	File1.open(QFile::ReadOnly);
//	QString StyleSheet1 = QLatin1String(File1.readAll());
//	a.setStyleSheet(StyleSheet1);


	// норм листвью
//	QFile File2("/Users/kremenevskiy/Desktop/Messenger/Messenger/StyleSheets/Darkeum/Darkeum.qss");
//	File2.open(QFile::ReadOnly);
//	QString StyleSheet2 = QLatin1String(File2.readAll());
//	a.setStyleSheet(StyleSheet2);






	// норм, только чекбокс говно, темная
//	QFile File5("/Users/kremenevskiy/Desktop/Messenger/Messenger/StyleSheets/Diffnes/Diffnes.qss");
//	File5.open(QFile::ReadOnly);
//	QString StyleSheet5 = QLatin1String(File5.readAll());
//	a.setStyleSheet(StyleSheet5);











	w.show();
	return a.exec();
}
