#include "TestQtGuiApplication.h"
#include <QtWidgets/QApplication>



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestQtGuiApplication w;
	w.show();
	return a.exec();
}
