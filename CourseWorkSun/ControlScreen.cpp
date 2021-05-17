#include "ControlScreen.h"

void ControlScreen(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int COLOUR)
{
	GetConsoleScreenBufferInfo(output_handle, &CSBufInf);
	SetConsoleTextAttribute(output_handle, COLOUR);
	system("cls");
	CONSOLE_CURSOR_INFO ccInfo;
	ccInfo.bVisible = false;
	ccInfo.dwSize = 100;
	SetConsoleCursorInfo(output_handle, &ccInfo);
}
