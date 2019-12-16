#ifndef MOUSELISTENER_H
#define MOUSELISTENER_H

#include <QThread>

#include "commonsettings.h"

class MouseListener : public QThread
{
	Q_OBJECT
public:
	MouseListener(CommonSettings * const p_settings, QObject *p_parent = 0);
	void run() override;
private:
	struct State{
		int xPos;
		int yPos;
		bool bnLeft;
		bool bnRight;
	};
	void processMouseEvent(const State &p_state);

private:
	int _fd;
	State _state;
	CommonSettings * const _settings;
};

#endif // MOUSELISTENER_H
