#include "ConsoleManager.h"

CONSOLE_FONT_INFOEX ConsoleManager::originalFont;

void ConsoleManager::saveOriginalFont()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	originalFont.cbSize = sizeof(originalFont);

	GetCurrentConsoleFontEx(hConsole, FALSE, &originalFont);
}

void ConsoleManager::updateBoardAt(int x, int y, char item) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { static_cast<SHORT>(y), static_cast<SHORT>(x) };
	SetConsoleCursorPosition(hConsole, position);
	std::cout << item;
}

void ConsoleManager::setBoardFont(int size)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX cfi;

	cfi.cbSize = sizeof(cfi);

	cfi.dwFontSize.X = size;
	cfi.dwFontSize.Y = size;

	cfi.FontFamily = FF_MODERN;
	cfi.FontWeight = FW_NORMAL;

	SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

void ConsoleManager::setOriginalFont()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetCurrentConsoleFontEx(hConsole, FALSE, &originalFont);
}