#ifndef LAYOUT_H
#define LAYOUT_H

#include <QList>
#include <QString>
#include "keycodes.h"

struct LayoutCell
{
	Keycode code;
	QString title; // to display
	// TODO: CSV to draw image instead of simple text
};

struct LayoutCol // column in row
{
	int width;
	QList<LayoutCell> cells;
};

struct LayoutRow
{
	int height;
	//QList<QList<LayoutCell> > cells; // in column
	QList<LayoutCol> columns;
};

struct Layout
{
	QString title;
	int width = 2;
	int height = 2;
	QList<LayoutRow> buttons;
};

enum LayoutIndex
{
	LAYOUT_KB = 0,
//	LAYOUT_NUMPAD, // NumPad and Ins/Del/Home/End etc. Combined with TouchpadLayout
	//LAYOUT_OPACITY,
	LAYOUT__COUNT
};

extern Layout LAYOUTS[LAYOUT__COUNT];

#endif // LAYOUT_H
