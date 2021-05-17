#include "ControlInterface.h"

void ControlInterface(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR)
{
	int Key = 33, selected_item = 0, AMOUNT_OF_ITEMS = 5;
	bool stop = false;

	enum KeY
	{
		KEY_ARROW_DOWN = 80,
		KEY_ARROW_UP = 72,
		KEY_ENTER = 13,
		KEY_ESC = 27
	};

	enum Interface
	{
		SEARCH = 0,
		CREATE_NEW_ABONEMENT = 1,
		VIEW_ABONENT_LIST = 2,
		VIEW_BOOK_LIST = 3,
		EXIT = 4
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

				DrawInterface(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, selected_item);
				break;

			case KEY_ARROW_UP:

				if (selected_item > 0)
				{
					selected_item--;
				}
				else selected_item = AMOUNT_OF_ITEMS - 1;

				DrawInterface(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, selected_item);
				break;

			case KEY_ENTER:

				switch (selected_item)
				{

				case SEARCH:

					DrawSearch(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0);
					ControlSearch(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR);
					break;

				case CREATE_NEW_ABONEMENT:
					DrawCreateNewAbonement(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR);
					ControlCreateNewAbonement(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR);
					DrawInterface(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, selected_item);
					break;

				case VIEW_ABONENT_LIST:
					ViewAbonentList(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR);
					DrawInterface(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, selected_item);
					break;

				case VIEW_BOOK_LIST:
					ViewTheBookList(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR);
					DrawInterface(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, selected_item);
					break;

				case EXIT:

					Exit(output_handle, CSBufInf, INACTIVE_COLOUR, stop, ACTIVE_COLOUR);
					break;
				}
			}
		}
		fflush(stdin);
	}
}
