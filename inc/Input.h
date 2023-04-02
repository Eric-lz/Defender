#pragma once

#include <Windows.h>

class Input
{
public:
	static char keyPressed() {
		if (GetAsyncKeyState('W')) {
			return 'w';
		}
		else if (GetAsyncKeyState('A')) {
			return 'a';
		}
		else if (GetAsyncKeyState('S')) {
			return 's';
		}
		else if (GetAsyncKeyState('D')) {
			return 'd';
		}
		else if (GetAsyncKeyState(VK_SPACE)) {
			return ' ';
		}
		else return '\0';
	}
};

