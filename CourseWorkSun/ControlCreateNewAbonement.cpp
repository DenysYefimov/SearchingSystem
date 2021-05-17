#include "ControlCreateNewAbonement.h"

void ControlCreateNewAbonement(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR)
{
	enum KeY
	{
		KEY_ENTER = 13,
		KEY_ESC = 27
	};

	COORD first_name{ 7, 12 }, last_name{ 74, 12 }, date_of_birth{ 7, 18 }, add_book{ 74, 18 };
	bool stop = false;
	int Key = 33;
	std::string temp_first, temp_last, temp_date, temp_book;
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(output_handle, &structCursorInfo);
	structCursorInfo.bVisible = true;
	SetConsoleCursorInfo(output_handle, &structCursorInfo);
	SetConsoleCursorPosition(output_handle, first_name);
	std::getline(std::cin, temp_first);
	SetConsoleCursorPosition(output_handle, last_name);
	std::getline(std::cin, temp_last);
	SetConsoleCursorPosition(output_handle, date_of_birth);
	std::getline(std::cin, temp_date);
	SetConsoleCursorPosition(output_handle, add_book);
	std::getline(std::cin, temp_book);
	structCursorInfo.bVisible = false;
	SetConsoleCursorInfo(output_handle, &structCursorInfo);

	std::ifstream fin("BooksData.txt");
	Book book;
	
	while (!fin.eof())
	{
		fin >> book;
		if (("\"" + temp_book + "\"") == book.GetName())
		{
			User New(temp_first, temp_last, temp_date, book);
			std::ofstream fout("UsersData.txt", std::ofstream::app);
			fout << New;
			fout.close();
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
		return;
	}
	fin.close();
	DrawSuccessfully(output_handle, CSBufInf, INACTIVE_COLOUR);
}