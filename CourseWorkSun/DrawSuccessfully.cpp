#include "DrawSuccessfully.h"

void DrawSuccessfully(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR)
{
	ControlScreen(output_handle, CSBufInf, INACTIVE_COLOUR);
	COORD position{ (CSBufInf.srWindow.Right / 2) - 22, CSBufInf.srWindow.Bottom / 2 };
	SetConsoleCursorPosition(output_handle, position);
	std::cout << "The abonement has been created successfully!";
	Sleep(2000);
}