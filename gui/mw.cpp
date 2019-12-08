#include "mw.h"

#include <QPainter>

MW::MW()
	:QWidget(nullptr)
{
	setStyleSheet("background:transparent");
	setAttribute(Qt::WA_TranslucentBackground);
	setAttribute(Qt::WA_AlwaysStackOnTop);
	setWindowFlags(Qt::FramelessWindowHint);

	setFixedSize(200, 100);
	move(0,0);

}

void MW::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	painter.setPen(Qt::yellow);
	painter.drawRect(20, 20, 50, 50);
	painter.fillRect(24, 24, 42, 42, QColor(0,255,0,100));
}
