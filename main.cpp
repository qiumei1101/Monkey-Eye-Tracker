#include "qt_guidemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	QT_GUIDEMO w;
	w.show();
	
	return a.exec();
}
