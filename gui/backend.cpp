#include "backend.h"
#include "mouselistener.h"
#include "layout.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

BackEnd::BackEnd(QObject *parent) :
	QObject(parent)
{
	{
		auto *desktopWidget = QApplication::desktop();
		_settings.screenWidth = desktopWidget->width();
		_settings.screenHeight = desktopWidget->height();
	}

	_mouseListener = new MouseListener(&_settings, this);
	connect(_mouseListener, SIGNAL(layoutChanged(int)), SLOT(onLayoutChanged(int)));

	_mouseListener->start();
}

QString BackEnd::userName()
{
	return m_userName;
}

void BackEnd::setUserName(const QString &userName)
{
	if (userName == m_userName)
		return;

	m_userName = userName;
	emit userNameChanged();
}

void BackEnd::onLayoutChanged(int p_layoutIndex)
{
	//qDebug() << "qwe:" << p_layoutIndex;
	Layout layout = LAYOUTS[p_layoutIndex];
}
