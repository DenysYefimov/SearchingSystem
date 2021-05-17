#include "ControlBookSearch.h"

void ControlBookSearch(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR)
{
	enum KeY
	{
		KEY_ENTER = 13,
		KEY_ESC = 27
	};

	COORD CiN{ 39, 9 }, output{10, 12};
	bool stop = false;
	int Key = 33;
	std::string temp;
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(output_handle, &structCursorInfo);
	structCursorInfo.bVisible = true;
	SetConsoleCursorInfo(output_handle, &structCursorInfo);
	SetConsoleCursorPosition(output_handle, CiN);
	std::getline(std::cin, temp);
	structCursorInfo.bVisible = false;
	SetConsoleCursorInfo(output_handle, &structCursorInfo);
	std::ifstream fin("BooksData.txt");
	Book book;
	while (!fin.eof())
	{
		fin >> book;
		if (("\"" + temp + "\"") == book.GetName())
		{
			SetConsoleCursorPosition(output_handle, output);
			std::cout << book;
			break;
		}
	}
	if (fin.eof())
	{
		system("cls");
		SetConsoleCursorPosition(output_handle, { (CSBufInf.srWindow.Right / 2) - 16, (CSBufInf.srWindow.Bottom / 2) });
		std::cout << "You've entered an incorrect name!";
		fin.close();
		Sleep(2000);
		DrawSearch(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 1);
		return;
	}
	fin.close();
	while (!stop)
	{
		if (_kbhit())
		{
			Key = _getch();

			switch (Key)
			{
			case KEY_ENTER:
				DrawBookSearch(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR);
				structCursorInfo.bVisible = true;
				SetConsoleCursorInfo(output_handle, &structCursorInfo);
				SetConsoleCursorPosition(output_handle, CiN);
				std::getline(std::cin, temp);
				structCursorInfo.bVisible = false;
				SetConsoleCursorInfo(output_handle, &structCursorInfo);
				fin.open("BooksData.txt");
				while (!fin.eof())
				{
					fin >> book;
					if (("\"" + temp + "\"") == book.GetName())
					{
						SetConsoleCursorPosition(output_handle, output);
						std::cout << book;
						break;
					}
				}
				fin.close();
				break;

			case KEY_ESC:
				DrawSearch(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 1);
				stop = true;
				break;
			}
		}
	}
}