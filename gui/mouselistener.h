#ifndef MOUSELISTENER_H
#define MOUSELISTENER_H

#include <QThread>

#include "commonsettings.h"
#include "layout.h"

class MouseListener : public QThread
{
	Q_OBJECT
public:
	MouseListener(CommonSettings * const p_settings, QObject *p_parent = 0);
	void run() override;
private:
	struct MouseEvent{
		int xPos;
		int yPos;
		Keycode keycode;
		bool bnLeft;
		bool bnRight;
	};
	Keycode hitButton(int p_x, int p_y);
	void processMouseEvent(const MouseEvent &p_mouseEvent);

private:
	int _fd;
	MouseEvent _mouseEvent;
	int _modeTouchpad; // 0 or 1
	LayoutIndex _layoutIndex;
	CommonSettings * const _settings;
};

#endif // MOUSELISTENER_H
