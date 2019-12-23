#include <QApplication>
//#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "backend.h"
#include "qmlgenerator.h"

int main(int argc, char *argv[])
{
	//QGuiApplication app(argc, argv);

	QApplication app(argc, argv);//

	QmlGenerator qmlGen; // boris commented
	if (!qmlGen.generate())
	{
		return 1;
	}

//	QApplication app(argc, argv);

	qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");

	QQmlApplicationEngine engine;
	//engine.load(QUrl(QStringLiteral("qrc:/conf/main.qml")));
	//engine.load("../91129/conf/main.qml"); // for shadow build

	engine.load("conf2/main.qml");

	/*engine.loadData(R"(
import QtQuick 2.6
import QtQuick.Controls 2.0
import io.qt.examples.backend 1.0
ApplicationWindow {
	color: "#80000000"
}
)");*/

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
