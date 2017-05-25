#include "TinyRaspiGui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	TinyRaspiGui w;
	//w.showFullScreen();
	w.show();

	return a.exec();
}
