#include "ControlSearch.h"

void ControlSearch(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR)
{
	int Key = 33, selected_item = 0, AMOUNT_OF_ITEMS = 2;
	bool stop = false;

	enum KeY
	{
		KEY_ARROW_DOWN = 80,
		KEY_ARROW_UP = 72,
		KEY_ENTER = 13,
		KEY_ESC = 27
	};

	enum Search
	{
		USER_SEARCH = 0,
		BOOK_SEARCH = 1
	};


	while (!stop)
	{
		if (_kbhit())
		{
			Key = _getch();

			switch (Key)
			{
			case KEY_ARROW_DOWN:

				if (selected_item < AMOUNT_OF_ITEMS - 1)
				{
					selected_item++;
				}
				else selected_item = 0;

				DrawSearch(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, selected_item);
				break;

			case KEY_ARROW_UP:

				if (selected_item > 0)
				{
					selected_item--;
				}
				else selected_item = AMOUNT_OF_ITEMS - 1;

				DrawSearch(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, selected_item);
				break;

			case KEY_ENTER:

				switch (selected_item)
				{

				case USER_SEARCH:
					DrawUserSearch(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR);
					ControlUserSearch(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR);
					break;

				case BOOK_SEARCH:
					DrawBookSearch(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR);
					ControlBookSearch(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR);
					break;
				}
				break;

			case KEY_ESC:
				stop = true;
				DrawInterface(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0);
				break;
			}
		}
		fflush(stdin);
	}
}
