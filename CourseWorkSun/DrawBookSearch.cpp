#include "DrawBookSearch.h"

void DrawBookSearch(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR)
{
	ControlScreen(output_handle, CSBufInf, INACTIVE_COLOUR);
	COORD interval = { (CSBufInf.srWindow.Right / 2) - 6, (CSBufInf.srWindow.Bottom / 2) - 7 }, library{ (CSBufInf.srWindow.Right / 2) - 3, (CSBufInf.srWindow.Bottom / 2) - 10 }, frame{ (CSBufInf.srWindow.Right / 2) - 8, (CSBufInf.srWindow.Bottom / 2) - 8 };
	SetConsoleCursorPosition(output_handle, library);
	SetConsoleTextAttribute(output_handle, 0375);
	std::cout << "Biblio";

	SetConsoleTextAttribute(output_handle, INACTIVE_COLOUR);
	DrawFrame(output_handle, frame, 201);
	for (int i = 0; i < 13; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawFrame(output_handle, frame, 187);

	++frame.Y;
	DrawFrame(output_handle, frame, 186);

	frame.X -= 14;
	DrawFrame(output_handle, frame, 186);
	frame.X += 14;

	frame.X -= 14;
	++frame.Y;
	DrawFrame(output_handle, frame, 200);

	for (int i = 0; i < 13; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawFrame(output_handle, frame, 188);

	SetConsoleTextAttribute(output_handle, ACTIVE_COLOUR);
	SetConsoleCursorPosition(output_handle, interval);
	std::cout << "Book search";
	SetConsoleTextAttribute(output_handle, INACTIVE_COLOUR);

	++frame.Y;
	frame.X -= 24;
	DrawFrame(output_handle, frame, 201);
	for (int i = 0; i < 33; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawFrame(output_handle, frame, 187);

	++frame.Y;
	DrawFrame(output_handle, frame, 186);

	frame.X -= 34;
	DrawFrame(output_handle, frame, 186);
	frame.X += 34;

	frame.X -= 34;
	++frame.Y;
	DrawFrame(output_handle, frame, 200);

	for (int i = 0; i < 33; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawFrame(output_handle, frame, 188);
}
