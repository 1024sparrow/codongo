#include "backend.h"
#include "mouselistener.h"

#include <QApplication>
#include <QDesktopWidget>

BackEnd::BackEnd(QObject *parent) :
	QObject(parent)
{
	{
		auto *desktopWidget = QApplication::desktop();
		_settings.screenWidth = desktopWidget->width();
		_settings.screenHeight = desktopWidget->height();
	}

	_mouseListener = new MouseListener(&_settings, this);

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
