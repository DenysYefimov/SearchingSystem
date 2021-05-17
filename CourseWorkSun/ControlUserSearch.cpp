#include "ControlUserSearch.h"

void ControlUserSearch(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR)
{
	enum KeY
	{
		KEY_ARROW_LEFT = 75,
		KEY_ARROW_RIGHT = 77,
		KEY_ENTER = 13,
		KEY_ESC = 27
	};

	enum Action
	{
		ADD = 1,
		RETURN = 2
	};

	COORD CiN{ 39, 9 }, output{ 0, 12 }, action_book{ 39, 24 };
	bool stop = false;
	char ch;
	int Key = 33, selected_item = 1, count = 0;
	User user, temp_user;
	std::string temp;
	Book book;
	std::list<User> users;
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(output_handle, &structCursorInfo);
	structCursorInfo.bVisible = true;
	SetConsoleCursorInfo(output_handle, &structCursorInfo);
	SetConsoleCursorPosition(output_handle, CiN);
	std::getline(std::cin, temp);
	structCursorInfo.bVisible = false;
	SetConsoleCursorInfo(output_handle, &structCursorInfo);

	std::ifstream fin_book, fin_user1("UsersData.txt"), fin_user2;
	std::ofstream fout;
	while (fin_user1 >> temp_user && !fin_user1.eof())
	{
		if (temp == (temp_user.GetFirstName() + " " + temp_user.GetLastName()))
		{
			SetConsoleCursorPosition(output_handle, output);
			user = temp_user;
			std::cout << user;
			break;
		}
		
	}
	if (fin_user1.eof())
	{
		system("cls");
		SetConsoleCursorPosition(output_handle, { (CSBufInf.srWindow.Right / 2) - 16, (CSBufInf.srWindow.Bottom / 2) });
		std::cout << "You've entered an incorrect name!";
		fin_user1.close();
		Sleep(2000);
		DrawSearch(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0);
		return;
	}
	fin_user1.close();
	ControlAdding(output_handle, INACTIVE_COLOUR, ACTIVE_COLOUR, selected_item);

	while (!stop)
	{
		if (_kbhit())
		{
			Key = _getch();

			switch (Key)
			{

			case KEY_ARROW_LEFT:
				if (selected_item == 1)
				{
					selected_item = 2;
				}
				else selected_item = 1;
				ControlAdding(output_handle, INACTIVE_COLOUR, ACTIVE_COLOUR, selected_item);
				break;

			case KEY_ARROW_RIGHT:
				if (selected_item == 1)
				{
					selected_item = 2;
				}
				else selected_item = 1;
				ControlAdding(output_handle, INACTIVE_COLOUR, ACTIVE_COLOUR, selected_item);
				break;

			case KEY_ENTER:
				switch (selected_item)
				{
				case ADD:
					structCursorInfo.bVisible = true;
					SetConsoleCursorInfo(output_handle, &structCursorInfo);
					SetConsoleCursorPosition(output_handle, action_book);
					std::getline(std::cin, temp);
					structCursorInfo.bVisible = false;
					SetConsoleCursorInfo(output_handle, &structCursorInfo);
					fin_book.open("BooksData.txt");
					while (fin_book >> book && !fin_book.eof())
					{
						if (("\"" + temp + "\"") == book.GetName())
						{
							fin_book.close();
							user.AddBook(book);
							break;
						}
					}
					count = 0;
					fin_user2.open("UsersData.txt");
					while (count < user.GetCounter())
					{
						fin_user2 >> temp_user;
						if ((temp_user.GetFirstName() + " " + temp_user.GetLastName()) == (user.GetFirstName() + " " + user.GetLastName()))
						{
							temp_user = user;
						}
						users.push_back(temp_user);
						++count;
					}
					fin_user2.close();
					fout.open("UsersData.txt");
					for (User user : users)
					{
						fout << user << std::endl << std::endl;
					}
					fout.close();
					users.clear();

					break;

				case RETURN:
					structCursorInfo.bVisible = true;
					SetConsoleCursorInfo(output_handle, &structCursorInfo);
					SetConsoleCursorPosition(output_handle, action_book);
					std::getline(std::cin, temp);
					structCursorInfo.bVisible = false;
					SetConsoleCursorInfo(output_handle, &structCursorInfo);
					fin_book.open("BooksData.txt");
					while (fin_book >> book && !fin_book.eof())
					{
						if (("\"" + temp + "\"") == book.GetName())
						{
							fin_book.close();
							user.ReturnBook(book);
							break;
						}
					}

					count = 0;
					fin_user2.open("UsersData.txt");
					while (count < user.GetCounter())
					{
						fin_user2 >> temp_user;
						if ((temp_user.GetFirstName() + " " + temp_user.GetLastName()) == (user.GetFirstName() + " " + user.GetLastName()))
						{
							temp_user = user;
						}
						users.push_back(temp_user);
						++count;
					}
					fin_user2.close();
					fout.open("UsersData.txt");
					for (User user : users)
					{
						fout << user << std::endl << std::endl;
					}
					fout.close();
					users.clear();
					break;

				}
				break;

			case KEY_ESC:
				DrawSearch(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0);
				stop = true;
				break;
			}
		}
	}
}