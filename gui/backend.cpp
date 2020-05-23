#include "backend.h"
#include "mouselistener.h"
#include "layout.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

BackEnd::BackEnd(QObject *parent) :
	QObject(parent), _layoutIndex{ -1 }
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

int BackEnd::layoutIndex()
{
	return _layoutIndex;
}

void BackEnd::setLayoutIndex(int p_layoutIndex)
{
	_layoutIndex = p_layoutIndex;
}

void BackEnd::onLayoutChanged(int p_layoutIndex)
{
	//qDebug() << "qwe:" << p_layoutIndex;
	//Layout layout = LAYOUTS[p_layoutIndex];
	emit layoutIndexChanged(p_layoutIndex);
}
