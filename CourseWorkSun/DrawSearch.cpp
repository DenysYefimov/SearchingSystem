#include "DrawSearch.h"

void DrawSearchFrame(HANDLE output_handle, COORD& frame, int ch)
{
	SetConsoleCursorPosition(output_handle, frame);
	std::cout << char(ch);
}

void DrawSearch(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int selected_item)
{
	int AMOUNT_OF_ITEMS = 2;
	const char* InterfaceArr[]{ "Search", "User search", "Book search", "Create a new abonement", "View the abonent list", "View the book list", "Exit" };
	ControlScreen(output_handle, CSBufInf, INACTIVE_COLOUR);
	COORD interval = { (CSBufInf.srWindow.Right / 2) - 3, (CSBufInf.srWindow.Bottom / 2) - 7 }, library{ (CSBufInf.srWindow.Right / 2) - 3, (CSBufInf.srWindow.Bottom / 2) - 10 }, frame{ (CSBufInf.srWindow.Right / 2) - 7, (CSBufInf.srWindow.Bottom / 2) - 8 }, border{ (CSBufInf.srWindow.Right / 2) - 7, (CSBufInf.srWindow.Bottom / 2) - 6 };
	SetConsoleCursorPosition(output_handle, library);
	SetConsoleTextAttribute(output_handle, 0375);
	std::cout << "Biblio";

	SetConsoleTextAttribute(output_handle, INACTIVE_COLOUR);
	SetConsoleCursorPosition(output_handle, frame);
	std::cout << char(201);
	for (int i = 0; i < 13; i++)
	{
		++frame.X;
		DrawSearchFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawSearchFrame(output_handle, frame, 187);

	for (int i = 0; i < 5; i++)
	{
		++frame.Y;
		DrawSearchFrame(output_handle, frame, 186);

		frame.X -= 14;
		DrawSearchFrame(output_handle, frame, 186);
		frame.X += 14;
	}

	frame.X -= 14;
	++frame.Y;
	DrawSearchFrame(output_handle, frame, 200);

	for (int i = 0; i < 13; i++)
	{
		++frame.X;
		DrawSearchFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawSearchFrame(output_handle, frame, 188);;

	++frame.Y;
	frame.X += 6;
	DrawSearchFrame(output_handle, frame, 187);

	++frame.Y;
	DrawSearchFrame(output_handle, frame, 186);

	++frame.Y;
	DrawSearchFrame(output_handle, frame, 188);

	for (int i = 0; i < 24; i++)
	{
		--frame.X;
		DrawSearchFrame(output_handle, frame, 461);
	}

	--frame.X;
	DrawSearchFrame(output_handle, frame, 200);

	--frame.Y;
	DrawSearchFrame(output_handle, frame, 186);

	--frame.Y;
	DrawSearchFrame(output_handle, frame, 201);

	for (int i = 0; i < 24; i++)
	{
		++frame.X;
		DrawSearchFrame(output_handle, frame, 461);
	}

	frame.Y += 3;
	DrawSearchFrame(output_handle, frame, 187);

	++frame.Y;
	DrawSearchFrame(output_handle, frame, 186);

	++frame.Y;
	DrawSearchFrame(output_handle, frame, 188);

	for (int i = 0; i < 23; i++)
	{
		--frame.X;
		DrawSearchFrame(output_handle, frame, 461);
	}

	--frame.X;
	DrawSearchFrame(output_handle, frame, 200);

	--frame.Y;
	DrawSearchFrame(output_handle, frame, 186);

	--frame.Y;
	DrawSearchFrame(output_handle, frame, 201);

	for (int i = 0; i < 23; i++)
	{
		++frame.X;
		DrawSearchFrame(output_handle, frame, 461);
	}

	frame.Y += 3;
	DrawSearchFrame(output_handle, frame, 187);

	++frame.Y;
	DrawSearchFrame(output_handle, frame, 186);

	++frame.Y;
	DrawSearchFrame(output_handle, frame, 188);

	for (int i = 0; i < 20; i++)
	{
		--frame.X;
		DrawSearchFrame(output_handle, frame, 461);
	}

	--frame.X;
	DrawSearchFrame(output_handle, frame, 200);

	--frame.Y;
	DrawSearchFrame(output_handle, frame, 186);

	--frame.Y;
	DrawSearchFrame(output_handle, frame, 201);

	for (int i = 0; i < 20; i++)
	{
		++frame.X;
		DrawSearchFrame(output_handle, frame, 461);
	}

	DrawSearchFrame(output_handle, border, 199);
	for (int i = 0; i < 13; i++)
	{
		++border.X;
		DrawSearchFrame(output_handle, border, 196);
	}
	++border.X;
	DrawSearchFrame(output_handle, border, 182);

	SetConsoleCursorPosition(output_handle, interval);
	std::cout << InterfaceArr[0];
	interval.X -= 2;
	interval.Y += 2;
	for (int i = 0; i < AMOUNT_OF_ITEMS; i++)
	{
		SetConsoleCursorPosition(output_handle, interval);
		if (i == selected_item) SetConsoleTextAttribute(output_handle, ACTIVE_COLOUR);
		std::cout << InterfaceArr[i + 1];
		SetConsoleTextAttribute(output_handle, INACTIVE_COLOUR);
		interval.Y += 2;
	}

	interval.Y -= 2;
	for (int i = 3; i < 7; i++)
	{
		if (i == 3) interval.X -= 5;
		if (i == 5) interval.X += 2;
		if (i == 6) interval.X += 7;
		interval.Y += 3;
		SetConsoleCursorPosition(output_handle, interval);
		std::cout << InterfaceArr[i];
	}
}