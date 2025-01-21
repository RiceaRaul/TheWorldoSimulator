#pragma once
#include <windows.h>
#include <iostream>

class ConsoleManager
{
private:
	static CONSOLE_FONT_INFOEX originalFont;

public:
	static void saveOriginalFont();
	static void updateBoardAt(int x, int y, char item);
	static void setOriginalFont();
	static void setBoardFont(int size);
};

