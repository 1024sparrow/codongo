#include "mouselistener.h"
#include "layout.h"

#include <QDebug>

#include <unistd.h>
#include <fcntl.h>

MouseListener::MouseListener(CommonSettings * const p_settings, QObject *p_parent)
	:QThread(p_parent), _settings(p_settings)
{
	_state.xPos = p_settings->screenWidth / 2;
	_state.yPos = p_settings->screenHeight / 2;
	_state.bnLeft = false;
	_state.bnRight = false;

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
	while (1)
	{
		// Read Mouse
		bytes = read(fd, data, sizeof(data));
		if (bytes > 0)
		{
			left = data[0] & 0x1;
			right = data[0] & 0x2;
			middle = data[0] & 0x4;
			x = data[1] & 0x7;
			y = data[2] & 0x7;
			printf("x=%d, y=%d, left=%d, middle=%d, right=%d\n", x, y, left, middle, right);
			int tmp = data[0];
			printf("-------%i-----", tmp);
			tmp = data[1];
			printf("==-----%i-----", tmp);
			State state;
			state.xPos += x;
			state.yPos += y;
			state.bnLeft = left;
			state.bnRight = right;
			processMouseEvent(state);
		}
		else
		{
			break;
		}
	}
}

void MouseListener::processMouseEvent(const State &p_state)
{
	_state = p_state;
	LAYOUTS; // boris here
}
