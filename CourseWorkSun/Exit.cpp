#include "Exit.h"

void Exit(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, bool& stop, int ACTIVE_COLOUR)
{
	bool stop_Exit = false;
	int Key = 33, KEY_ENTER = 13, KEY_ESC = 27;
	ControlScreen(output_handle, CSBufInf, INACTIVE_COLOUR);
	COORD interval{ (CSBufInf.srWindow.Right / 2) - 13, (CSBufInf.srWindow.Bottom / 2) - 2 };
	SetConsoleCursorPosition(output_handle, interval);
	std::cout << "Do you really want to exit?";
	interval.X -= 27;
	interval.Y += 3;
	SetConsoleCursorPosition(output_handle, interval);
	std::cout << "Press \"Enter\" to stop the programme or \"Esc\" to continue and return to Interface";

	while (!stop)
	{
		if (_kbhit())
		{
			Key = _getch();

			if (Key == KEY_ENTER)
			{
				system("cls");
				stop = true;
				break;
			}
			if (Key == KEY_ESC)
			{
				DrawInterface(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 4);
				break;
			}
		}
		fflush(stdin);
	}
}