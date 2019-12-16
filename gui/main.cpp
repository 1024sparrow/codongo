#include <QApplication>
//#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "backend.h"

int main(int argc, char *argv[])
{
	//QGuiApplication app(argc, argv);
	QApplication app(argc, argv);

	qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");

	QQmlApplicationEngine engine;
	//engine.load(QUrl(QStringLiteral("qrc:/conf/main.qml")));
	//engine.load("../91129/conf/main.qml"); // for shadow build
	engine.load("conf/main.qml");

	return app.exec();
}


//#include <QApplication>

//#include <stdio.h>
//#include <unistd.h>

//#include "mw.h"

//int main(int argc, char **argv)
//{
//	QApplication app(argc, argv);

//	QDeclarativeView* v = new QDeclarativeView;

//	MW mw;
//	mw.show();

//	return app.exec();
//}
