#ifndef LAYOUT_H
#define LAYOUT_H

#include <QList>
#include <QString>

struct LayoutCell
{
	const char * code;
	QString title; // to display
};

struct LayoutRow
{
	int height;
	QList<QList<LayoutCell> > cells; // in column
};

struct Layout
{
	const char *code;
	QString title;
	int width = 2;
	int height = 2;
	QList<LayoutRow> buttons;
};

Layout l1 = {
	"n",
	"Normal",
	2, // width
	2, // height
	{ // buttons
		{ // row 0
			1, // height
			{ // cells
				{
					{"a", "A"},
				},
				{
					{"b", "B"}
				}
			}
		},
		{ // row 1
			1, // height
			{ // cells
				{
					{"c", "C"},
				},
				{
					{"d", "D"}
				}
			}
		}
	}
};
Layout l2 = {
	"a",
	"Addon",
	2, // width
	2, // height
	{ // buttons
		{ // row 0
			1, // height
			{ // cells
				{
					{"a", "A"},
					{"a2", "A2"},
				},
				{
					{"b", "B"}
				}
			}
		},
		{ // row 1
			1, // height
			{ // cells
				{
					{"c", "C"},
				},
				{
					{"d", "D"}
				}
			}
		}
	}
};
auto LAYOUTS = QList<Layout>() << l1 << l2;

#endif // LAYOUT_H
