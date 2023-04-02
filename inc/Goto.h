#pragma once

#include <windows.h>

class Goto
{
public:
  static void gotoxy(short x, short y){
    // initialize objects for cursor manipulation
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD destCoord = { x, y };

    // set cursor position
    SetConsoleCursorPosition(hStdout, destCoord);
  }
};

