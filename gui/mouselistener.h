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
signals:
	void emulateMouse(bool p_lb, bool p_rb, int p_dx, int p_dy);
	void emulateKB(int keycode);// enum Keycode (keycodes.h)
	void layoutChanged(int layoutIndex);// enum LayoutIndex (layout.h)
private:
	struct MouseEvent{ // touch screen event representation (for develop time emulating by regular mouse)
		MouseEvent();
		int xPos;
		int yPos;
		Keycode keycode;
		bool bnLeft; // regilar touch
		bool bnRight; // touch with large touch square (using for screen locking)
	};
	Keycode hitButton(int p_x, int p_y);
	void processMouseEvent(const MouseEvent &p_mouseEvent);
	void switchLayout(LayoutIndex p_index);

private:
	int _fd;
	MouseEvent _mouseEvent; // last mouse press event
	MouseEvent _lastMouseEvent; // last mouse event
	LayoutIndex _layoutIndex;
	CommonSettings * const _settings;
};

#endif // MOUSELISTENER_H
