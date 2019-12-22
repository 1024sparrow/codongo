#include "qmlgenerator.h"
#include "layout.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include <stdio.h>

QmlGenerator::QmlGenerator()
{

}

bool QmlGenerator::generate()
{
	QStringList filesToCopy;
	filesToCopy << "Botton.qml" << "util.js";
	for (QString templateFileName : filesToCopy)
	{
		QFile fileTemplate(":qmltemplate/" + templateFileName);
		if (!fileTemplate.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			fprintf(
				stderr, "can't open resource file '%s' for reading\n",
				//templateFileName.toStdString().c_str()
				fileTemplate.fileName().toStdString().c_str()
			);
			qDebug() << fileTemplate.errorString();
			return false;
		}
		QByteArray ba = fileTemplate.readAll();
		fileTemplate.close();
		QFile destFile("conf2/" + templateFileName);
		if (!destFile.open(QIODevice::Truncate | QIODevice::WriteOnly | QIODevice::Text))
		{
			fprintf(
				stderr,
				"can't open '%s' for writing\n",
				templateFileName.toStdString().c_str()
			);
			return false;
		}
		destFile.write(ba);
		destFile.close();
	}

	QFile fileMain("conf2/main.qml");
	if (!fileMain.open(QIODevice::Truncate | QIODevice::WriteOnly | QIODevice::Text))
	{
		fprintf(stderr, "can't open main.qml for writing\n");
		return false;
	}
	QTextStream tsMain(&fileMain);
	tsMain << R"(import QtQuick 2.6
import QtQuick.Controls 2.0
import io.qt.examples.backend 1.0

ApplicationWindow {
	id: root
	visible: true
	color: "#80000000"

	BackEnd {
		id: backend
	}

)";

	for (Layout layout : LAYOUTS)
	{
		qDebug() << layout.title;
		tsMain << "\t" << layout.title << R"( {
		id: )" << getLayoutId(layout.title) << R"(
		anchors.fill: parent
	}

)";

		QFile fileLayout("conf2/" + layout.title + ".qml");
		if (!fileLayout.open(QIODevice::Truncate | QIODevice::WriteOnly | QIODevice::Text))
		{
			fprintf(stderr, "can't open main.qml for writing\n");
			return false;
		}
		{
			QTextStream tsLayout(&fileLayout);
		}
		fileLayout.close();
	}
	fileMain.close();
	return false;
}

QString QmlGenerator::getLayoutId(const QString &layoutTitle)
{
	return "lay" + layoutTitle;
}
