#include "qmlgenerator.h"
#include "layout.h"
#include "screenspec.h"
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
			tsLayout << R"(import QtQuick 2.6
import QtQuick.Controls 2.0
import "util.js" as Util

Rectangle {
	id: root
	color: "#80000000"
)";
			/*
	Botton {
		text: "Boris"
		x: 500
		y: 500
		width: 500
		height: 500
	}
			*/
			const double heightKoef = CONST_HEIGHT / layout.height;
			const double widthKoef = CONST_WIDTH / layout.width;
			int xCell{0}, yRow{0}, yCell, wCell, hRow, hCell;
			for (LayoutRow row : layout.buttons)
			{
				xCell = 0;
				hRow = heightKoef * row.height;
				for (LayoutCol col : row.columns)
				{
					wCell = widthKoef * col.width;
					if (!col.cells.count())
					{
						fprintf(stderr, "incorrect empty set of buttons in columns\n");
						return false;
					}
					hCell = hRow / col.cells.count();
					yCell = yRow;
					for (LayoutCell cell : col.cells)
					{
						tsLayout << R"(
	Botton {
		text: ")" << cell.title << R"("
		x: )" << xCell << R"(
		y: )" << yCell << R"(
		width: )" << wCell << R"(
		height: )" << hCell << R"(
	}
)";
						yCell += hCell;
					}
					xCell += wCell;
				}
				yRow += hRow;
			}
			tsLayout << R"(}
)";
		}
		fileLayout.close();
	}
	tsMain << "}";
	fileMain.close();
	return true;
}

QString QmlGenerator::getLayoutId(const QString &layoutTitle)
{
	return "lay" + layoutTitle;
}
