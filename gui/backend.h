#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>

#include "commonsettings.h"

class MouseListener;
class BackEnd : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)//
	Q_PROPERTY(int layoutIndex READ layoutIndex WRITE setLayoutIndex NOTIFY layoutIndexChanged)

public:
	explicit BackEnd(QObject *parent = nullptr);

	QString userName();
	void setUserName(const QString &userName);
	int layoutIndex();
	void setLayoutIndex(int p_layoutIndex);

signals:
	void userNameChanged();
	void layoutIndexChanged(int p_layoutIndex);

private slots:
	void onLayoutChanged(int p_layoutIndex);

private:
	QString m_userName;
	int _layoutIndex;
	MouseListener *_mouseListener;
	CommonSettings _settings;
};

#endif // BACKEND_H
