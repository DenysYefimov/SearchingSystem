#include "ViewAbonentList.h"

void ViewAbonentList(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR)
{
	enum KeY
	{
		KEY_ENTER = 13,
		KEY_ESC = 27
	};
	bool stop = false;
	int Key = 33;
	ControlScreen(output_handle, CSBufInf, INACTIVE_COLOUR);
	COORD interval = { (CSBufInf.srWindow.Right / 2) - 11, (CSBufInf.srWindow.Bottom / 2) - 7 }, library{ (CSBufInf.srWindow.Right / 2) - 3, (CSBufInf.srWindow.Bottom / 2) - 10 }, frame{ (CSBufInf.srWindow.Right / 2) - 13, (CSBufInf.srWindow.Bottom / 2) - 8 }, output{ 10, 8 };
	SetConsoleCursorPosition(output_handle, library);
	SetConsoleTextAttribute(output_handle, 0375);
	std::cout << "Biblio";

	SetConsoleTextAttribute(output_handle, INACTIVE_COLOUR);
	DrawFrame(output_handle, frame, 201);
	for (int i = 0; i < 23; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawFrame(output_handle, frame, 187);

	++frame.Y;
	DrawFrame(output_handle, frame, 186);

	frame.X -= 24;
	DrawFrame(output_handle, frame, 186);
	frame.X += 24;

	frame.X -= 24;
	++frame.Y;
	DrawFrame(output_handle, frame, 200);

	for (int i = 0; i < 23; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawFrame(output_handle, frame, 188);

	SetConsoleTextAttribute(output_handle, ACTIVE_COLOUR);
	SetConsoleCursorPosition(output_handle, interval);
	std::cout << "View the abonent list";
	SetConsoleTextAttribute(output_handle, INACTIVE_COLOUR);

	SetConsoleCursorPosition(output_handle, output);
	char ch;
	std::ifstream fin("UsersData.txt");
	while (fin.get(ch))
	{
		std::cout << ch;
		if (ch == '\n')
		{
			++output.Y;
			SetConsoleCursorPosition(output_handle, output);
		}
	}

	while (!stop)
	{
		if (_kbhit())
		{
			Key = _getch();

			switch (Key)
			{
			case KEY_ENTER:
				stop = true;
				break;

			case KEY_ESC:
				stop = true;
				break;
			}
		}
		fflush(stdin);
	}
}