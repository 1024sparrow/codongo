#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>

#include "commonsettings.h"

class MouseListener;
class BackEnd : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)

public:
	explicit BackEnd(QObject *parent = nullptr);

	QString userName();
	void setUserName(const QString &userName);

signals:
	void userNameChanged();

private slots:
	void onLayoutChanged(int p_layoutIndex);

private:
	QString m_userName;
	MouseListener *_mouseListener;
	CommonSettings _settings;
};

#endif // BACKEND_H
