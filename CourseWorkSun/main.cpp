#include <windows.h>
#include <fstream>
#include "Book.h"
#include "User.h"
#include "DrawInterface.h"
#include "ControlInterface.h"
#define WHITE_ON_PEACH 0317
#define WHITE_ON_VIOLET 0137

HANDLE output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO CSBufInf;

int main()
{
	system("title Library");

	/*Book book1("Taras Shevchenko", "Kobzar"), book2("Ivan Franko", "Kameniari"), book3("Lesia Ukrainka", "The Forest Song"), book4("Olha Kobylianska", "Earth"), book5("Mykhailo Kotsiubynsky", "Fata Morgana"), 
		book6("Mykhailo Kotsiubynsky", "Shadows of Forgotten Ancestors"), book7("Valerian Pidmohylny", "The city"), book8("Valerian Pidmohylny", "A Little Touch of Drama"), book9("Charles Dickens", "A Christmas Carol"), book10("George Orwell", "Animal Farm"), 
		book11("Isaac Asimov", "Profession"), book12("Ivan Bahrianyi", "The Hunters and the Hunted"), book13("Jack London", "Love of Life"), book14("Mark Twain", "Tom Sawyer"), book15("Mikhail Bulgakov", "The Master and Margarita"), 
		book16("Robert Louis Stevenson", "Treasure Island"), book17("William Shakespeare", "Romeo and Juliet"), book18("William Shakespeare", "The Tragical Historie of Hamlet, Prince of Denmarke");*/

	/*Book arr[18]{ book1, book2, book3, book4, book5, book6, book7, book8, book9, book10, book11, book12, book13, book14, book15, book16, book17, book18 };

	std::ofstream fout("Data.txt", std::ofstream::app);

	for (Book book : arr)
	{
		fout << book << std::endl;
	}*/

	/*User user1("Artem", "Boborykin", "29.08.2003", book2), user2("Vyacheslav", "Liashenko", "03.10.2003", book1), user3("Vladyslav", "Vlasenko", "06.12.2002", book17), user4("Polina", "Pishova", "05.06.2003", book3), user5("Matviy", "Ostapchuk", "28.12.2002", book10), user6("Vitaliy", "Strashuk", "14.01.2003", book5);
	User arru[6]{ user1, user2, user3, user4, user5, user6 };
	std::ofstream fout("UsersData.txt");

	for (User user : arru)
	{
		fout << user << std::endl << std::endl;
	}*/

	DrawInterface(output_handle, CSBufInf, WHITE_ON_PEACH, WHITE_ON_VIOLET, 0);
	ControlInterface(output_handle, CSBufInf, WHITE_ON_PEACH, WHITE_ON_VIOLET);
	return 0;
}