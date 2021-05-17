#include "DrawFrame.h"

void DrawFrame(HANDLE output_handle, COORD& frame, int ch)
{
	SetConsoleCursorPosition(output_handle, frame);
	std::cout << char(ch);
}