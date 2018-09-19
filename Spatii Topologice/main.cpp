#include <QtWidgets/QApplication>
#include "GUI.h"
#include "TestSubs.h"
int main(int argc, char *argv[])
{
	testAll();
	QApplication a(argc, argv);
	Multime<int> mul{ 100 };
	VectorDinamic familie(100);
	GUI gui{mul,familie};
	return a.exec();
}
