#include "mouselistener.h"

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

// 1280x1024
#define CONST_WIDTH 1280 // ширина экрана
#define CONST_HEIGHT 1024 // высота экрана
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

MouseListener::MouseListener(CommonSettings * const p_settings, QObject *p_parent)
	: QThread(p_parent)
	, _settings(p_settings)
	, _modeTouchpad(0)
	, _layoutIndex(LAYOUT_KB)
{
	_mouseEvent.xPos = 0;//CONST_WIDTH / 2;
	_mouseEvent.yPos = 0;//CONST_HEIGHT / 2;
	//_mouseEvent.keycode
	_mouseEvent.bnLeft = false;
	_mouseEvent.bnRight = false;

}

void MouseListener::run()
{
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
			x = data[1];// & 0x7;
			//y = ((data[2] & 8) ? -1 : +1) * data[2] & 7;
			//y = 4 - (data[2] & 0x7);
			y = - data[2];
			printf("\t\tx=%d, y=%d, left=%d, middle=%d, right=%d\n", x, y, left, middle, right);
			int tmp = data[0];
			//printf("-------%i-----", tmp);
			tmp = data[1];
			//printf("==-----%i-----", tmp);
			MouseEvent mouseEvent;
			gerCursorPos(mouseEvent.xPos, mouseEvent.yPos);
			mouseEvent.keycode = hitButton(mouseEvent.xPos, mouseEvent.yPos);
			mouseEvent.bnLeft = left;
			mouseEvent.bnRight = right;
			processMouseEvent(mouseEvent);
		}
		else
		{
			break;
		}
	}
}

Keycode MouseListener::hitButton(int p_x, int p_y)
{
	Layout layout = LAYOUTS[_modeTouchpad];
	//int indexRow = p_y >
	printf("x: %i\n", (int)(p_x * koefMiceHor));
	printf("y: %i\n", (int)(p_y * koefMiceVert));
	return KEY_1;
}

void MouseListener::processMouseEvent(const MouseEvent &p_mouseEvent)
{
	LAYOUTS; // boris here

	if (_mouseEvent.keycode != p_mouseEvent.keycode)
	{
		// mouse moving detected
	}

	Layout layout = LAYOUTS[_layoutIndex];

	int
		buttonWUnit(CONST_WIDTH / layout.width),
		buttonHUnit(CONST_HEIGHT / layout.height)
	;
	//
	_mouseEvent = p_mouseEvent;
}
