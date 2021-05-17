#include "DrawInterface.h"

void DrawInterface(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int selected_item)
{
	int AMOUNT_OF_ITEMS = 5;
	const char* InterfaceArr[]{ "Search", "Create a new abonement", "View the abonent list", "View the book list", "Exit" };
	ControlScreen(output_handle, CSBufInf, INACTIVE_COLOUR);
	COORD interval = { (CSBufInf.srWindow.Right / 2) - 3, (CSBufInf.srWindow.Bottom / 2) - 7 }, library{ (CSBufInf.srWindow.Right / 2) - 3, (CSBufInf.srWindow.Bottom / 2) - 10 }, frame{ (CSBufInf.srWindow.Right / 2) - 5, (CSBufInf.srWindow.Bottom / 2) - 8 };
	SetConsoleCursorPosition(output_handle, library);
	SetConsoleTextAttribute(output_handle, 0375);
	std::cout << "Biblio";
	SetConsoleTextAttribute(output_handle, INACTIVE_COLOUR);

	SetConsoleCursorPosition(output_handle, frame);
	std::cout << char(201);
	for (int i = 0; i < 8; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawFrame(output_handle, frame, 187);

	++frame.Y;
	DrawFrame(output_handle, frame, 186);

	frame.X -= 9;
	DrawFrame(output_handle, frame, 186);

	++frame.Y;
	DrawFrame(output_handle, frame, 200);

	for (int i = 0; i < 8; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawFrame(output_handle, frame, 188);

	++frame.Y;
	frame.X += 8;
	DrawFrame(output_handle, frame, 187);

	++frame.Y;
	DrawFrame(output_handle, frame, 186);

	++frame.Y;
	DrawFrame(output_handle, frame, 188);

	for (int i = 0; i < 24; i++)
	{
		--frame.X;
		DrawFrame(output_handle, frame, 461);
	}

	--frame.X;
	DrawFrame(output_handle, frame, 200);

	--frame.Y;
	DrawFrame(output_handle, frame, 186);

	--frame.Y;
	DrawFrame(output_handle, frame, 201);

	for (int i = 0; i < 24; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}

	frame.Y += 3;
	DrawFrame(output_handle, frame, 187);

	++frame.Y;
	DrawFrame(output_handle, frame, 186);

	++frame.Y;
	DrawFrame(output_handle, frame, 188);

	for (int i = 0; i < 23; i++)
	{
		--frame.X;
		DrawFrame(output_handle, frame, 461);
	}

	--frame.X;
	DrawFrame(output_handle, frame, 200);

	--frame.Y;
	DrawFrame(output_handle, frame, 186);

	--frame.Y;
	DrawFrame(output_handle, frame, 201);

	for (int i = 0; i < 23; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}

	frame.Y += 3;
	DrawFrame(output_handle, frame, 187);

	++frame.Y;
	DrawFrame(output_handle, frame, 186);

	++frame.Y;
	DrawFrame(output_handle, frame, 188);

	for (int i = 0; i < 20; i++)
	{
		--frame.X;
		DrawFrame(output_handle, frame, 461);
	}

	--frame.X;
	DrawFrame(output_handle, frame, 200);

	--frame.Y;
	DrawFrame(output_handle, frame, 186);

	--frame.Y;
	DrawFrame(output_handle, frame, 201);

	for (int i = 0; i < 20; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}

	for (int i = 0; i < AMOUNT_OF_ITEMS; i++)
	{
		SetConsoleCursorPosition(output_handle, interval);
		if (i == selected_item) SetConsoleTextAttribute(output_handle, ACTIVE_COLOUR);
		std::cout << InterfaceArr[i];
		SetConsoleTextAttribute(output_handle, INACTIVE_COLOUR);
		interval.Y += 3;
		if (i == 0) interval.X -= 8;
		if (i == 2) interval.X += 2;
		if (i == 3) interval.X += 7;
	}
}
