#include "mouselistener.h"
#include "screenspec.h"

#include <QDebug>

#include <unistd.h>
#include <fcntl.h>

#include <getopt.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>
#include <X11/extensions/Xdamage.h>
#include <X11/extensions/Xrender.h>
#include <X11/extensions/shape.h>

//#define CONST_MARGIN 64 // ширина края, распознаваемая в жестах как край экрана
//#define CONST_MODSEL_HEIGHT 64 // высота переключателя режимов

double koefMiceVert = (double)CONST_HEIGHT / 1568.; // сумма смещений, накопленная при перемещении мышт сверху вниз
double koefMiceHor = (double)CONST_WIDTH / 1286.; // сумма смещений, накопленная при перемещении мышт сверху вниз

bool gerCursorPos(int &p_x, int &p_y)
{
	char *display_name = getenv("DISPLAY");
	if (!display_name) {
		fprintf(stderr, "DISPLAY not set\n");
		return false;
	}
	Display *display = XOpenDisplay(display_name);
	if (!display) {
		fprintf(stderr, "cannot open display '%s'\n", display_name);
		return false;
	}
	XFixesCursorImage *cursor = XFixesGetCursorImage(display);
	p_x = cursor->x;
	p_y = cursor->y;
	XCloseDisplay(display);
	return true;
}

MouseListener::MouseEvent::MouseEvent()
{
	xPos = -1;
	yPos = -1;
	keycode = KEY_UNDEFINED;
	bnLeft = false;
	bnRight = false;
}

MouseListener::MouseListener(CommonSettings * const p_settings, QObject *p_parent)
	: QThread(p_parent)
	, _settings(p_settings)
	, _layoutIndex(LAYOUT_KB)
{
}

void MouseListener::run()
{
	emit layoutChanged(_layoutIndex);
	int fd, bytes;
	unsigned char data[3];
	const char *pDevice = "/dev/input/mouse0";
	if ((fd = open(pDevice, O_RDWR)) < 0)
	{
		perror("ERROR Opening device file");
		return;
	}

	int left, middle, right;
	signed char x, y;
	//int x, y;
	while (1)
	{
		// Read Mouse
		bytes = read(fd, data, sizeof(data));
		if (bytes > 0)
		{
			left = data[0] & 0x1;
			right = data[0] & 0x2;
			middle = data[0] & 0x4;
			x = data[1];
			y = - data[2];
			//printf("\t\tx=%d, y=%d, left=%d, middle=%d, right=%d\n", x, y, left, middle, right);

			if (left || right || _lastMouseEvent.bnLeft || _lastMouseEvent.bnRight)
			{
				printf("\t\tx=%d, y=%d, left=%d, right=%d\n", x, y, left, right);
				MouseEvent mouseEvent;
				gerCursorPos(mouseEvent.xPos, mouseEvent.yPos);
				mouseEvent.keycode = hitButton(mouseEvent.xPos, mouseEvent.yPos);
				mouseEvent.bnLeft = left;
				mouseEvent.bnRight = right;
				if (!(_lastMouseEvent.bnLeft || _lastMouseEvent.bnRight))
				{
					if (left || right)
					{
						_mouseEvent = mouseEvent;
					}
				}
				processMouseEvent(mouseEvent);
				_lastMouseEvent = mouseEvent;
			}
			else
			{
				//
			}
		}
		else
		{
			break;
		}
	}
}

Keycode MouseListener::hitButton(int p_x, int p_y)
{
	// boris here 2
	Layout layout = LAYOUTS[_layoutIndex];
	int
		buttonWUnit(CONST_WIDTH / layout.width),
		buttonHUnit(CONST_HEIGHT / layout.height)
	;
	//int indexRow = p_y >
	printf("x: %i\n", (int)(p_x * koefMiceHor));
	printf("y: %i\n", (int)(p_y * koefMiceVert));
	return KEY_A;
}

void MouseListener::processMouseEvent(const MouseEvent &p_mouseEvent)
{
	emit layoutChanged(_layoutIndex = LAYOUT_MICE);//
	if (_mouseEvent.keycode == KEY_MOUSE_AREA)
	{
		// boris here 1: Связать BackEnd с сигналом layoutChanged(), отрисовка экранной клавиатуры по конфе (layout.h)
		// boris here 3: добавить в проект эмулятор клавиатуры (генерация событий)
		// Реализация эмулятора мыши возможна только при взаимодействии через тачпад (и, соответственно, наличии реализации перехвата реальных координат не через XOrg, а через устройство)
	}
	else
	{
		if (!p_mouseEvent.bnLeft) // mouse button released
		{
			if (_mouseEvent.keycode == p_mouseEvent.keycode)
			{
				emit emulateKB(p_mouseEvent.keycode);
			}
			else // mouse moving detected
			{
				if (_layoutIndex == LAYOUT_KB || _layoutIndex == LAYOUT_NUMPAD)
				{
					switchLayout(LAYOUT_MICE);
					_mouseEvent = p_mouseEvent;
					_mouseEvent.keycode = KEY_MOUSE_AREA;
					_lastMouseEvent = _mouseEvent;
					emit layoutChanged(_layoutIndex = LAYOUT_MICE);
				}
				// else ignoring
			}
		}
	}

	if (p_mouseEvent.bnLeft && !_mouseEvent.bnLeft) // mouse button pressed
		_mouseEvent = p_mouseEvent;
}

void MouseListener::switchLayout(LayoutIndex p_index)
{
	_mouseEvent = MouseEvent();
}
