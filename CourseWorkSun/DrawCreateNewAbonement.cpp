#include "DrawCreateNewAbonement.h"

void DrawCreateNewAbonement(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR)
{
	ControlScreen(output_handle, CSBufInf, INACTIVE_COLOUR);
	COORD interval = { (CSBufInf.srWindow.Right / 2) - 12, (CSBufInf.srWindow.Bottom / 2) - 7 }, library{ (CSBufInf.srWindow.Right / 2) - 3, (CSBufInf.srWindow.Bottom / 2) - 10 }, frame{ (CSBufInf.srWindow.Right / 2) - 14, (CSBufInf.srWindow.Bottom / 2) - 8 };
	SetConsoleCursorPosition(output_handle, library);
	SetConsoleTextAttribute(output_handle, 0375);
	std::cout << "Biblio";

	SetConsoleTextAttribute(output_handle, INACTIVE_COLOUR);
	DrawFrame(output_handle, frame, 201);
	for (int i = 0; i < 24; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawFrame(output_handle, frame, 187);

	++frame.Y;
	DrawFrame(output_handle, frame, 186);

	frame.X -= 25;
	DrawFrame(output_handle, frame, 186);
	frame.X += 25;

	frame.X -= 25;
	++frame.Y;
	DrawFrame(output_handle, frame, 200);

	for (int i = 0; i < 24; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawFrame(output_handle, frame, 188);

	SetConsoleTextAttribute(output_handle, ACTIVE_COLOUR);
	SetConsoleCursorPosition(output_handle, interval);
	std::cout << "Create a new abonement";
	SetConsoleTextAttribute(output_handle, INACTIVE_COLOUR);

	frame.Y += 3;
	frame.X -= 60;
	SetConsoleCursorPosition(output_handle, frame);
	std::cout << "First name";
	frame.X += 67;
	SetConsoleCursorPosition(output_handle, frame);
	std::cout << "Last name";

	--frame.X;
	++frame.Y;
	DrawFrame(output_handle, frame, 201);
	for (int i = 0; i < 24; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawFrame(output_handle, frame, 187);

	++frame.Y;
	DrawFrame(output_handle, frame, 186);

	frame.X -= 25;
	DrawFrame(output_handle, frame, 186);
	frame.X += 25;

	frame.X -= 25;
	++frame.Y;
	DrawFrame(output_handle, frame, 200);

	for (int i = 0; i < 24; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawFrame(output_handle, frame, 188);

	frame.Y -= 2;
	frame.X -= 92;
	DrawFrame(output_handle, frame, 201);
	for (int i = 0; i < 24; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawFrame(output_handle, frame, 187);

	++frame.Y;
	DrawFrame(output_handle, frame, 186);

	frame.X -= 25;
	DrawFrame(output_handle, frame, 186);
	frame.X += 25;

	frame.X -= 25;
	++frame.Y;
	DrawFrame(output_handle, frame, 200);

	for (int i = 0; i < 24; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawFrame(output_handle, frame, 188);

	frame.X -= 24;
	frame.Y += 3;
	SetConsoleCursorPosition(output_handle, frame);
	std::cout << "The date of birth";
	--frame.X;
	++frame.Y;
	DrawFrame(output_handle, frame, 201);
	for (int i = 0; i < 24; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawFrame(output_handle, frame, 187);

	++frame.Y;
	DrawFrame(output_handle, frame, 186);

	frame.X -= 25;
	DrawFrame(output_handle, frame, 186);
	frame.X += 25;

	frame.X -= 25;
	++frame.Y;
	DrawFrame(output_handle, frame, 200);

	for (int i = 0; i < 24; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawFrame(output_handle, frame, 188);

	frame.Y -= 3;
	frame.X += 43;

	--frame.X;
	++frame.Y;
	DrawFrame(output_handle, frame, 201);
	for (int i = 0; i < 24; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawFrame(output_handle, frame, 187);

	++frame.Y;
	DrawFrame(output_handle, frame, 186);

	frame.X -= 25;
	DrawFrame(output_handle, frame, 186);
	frame.X += 25;

	frame.X -= 25;
	++frame.Y;
	DrawFrame(output_handle, frame, 200);

	for (int i = 0; i < 24; i++)
	{
		++frame.X;
		DrawFrame(output_handle, frame, 461);
	}
	++frame.X;
	DrawFrame(output_handle, frame, 188);

	frame.X -= 24;
	frame.Y -= 3;
	SetConsoleCursorPosition(output_handle, frame);
	std::cout << "Add the book";
}
