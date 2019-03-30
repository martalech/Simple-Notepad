#include "stdafx.h"
#include "Notepad.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setWindowIcon(QIcon(":/Notepad/Resources/notepad.ico"));
	/*QString workingDir = a.applicationDirPath();
	QDir::setCurrent(workingDir);*/
	Notepad w;
	w.show();
	return a.exec();
}
