#include "ControlAdding.h"

void ControlAdding(HANDLE output_handle, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int selected_item)
{
	COORD add{ 17, 24 };
	SetConsoleCursorPosition(output_handle, add);

	if (selected_item == 1)
	{
		SetConsoleTextAttribute(output_handle, ACTIVE_COLOUR);
	}

	std::cout << "Add the book";

	if (selected_item == 1)
	{
		SetConsoleTextAttribute(output_handle, INACTIVE_COLOUR);
	}

	add.X -= 2;
	--add.Y;
	DrawFrame(output_handle, add, 201);
	for (int i = 0; i < 14; i++)
	{
		++add.X;
		DrawFrame(output_handle, add, 461);
	}
	++add.X;
	DrawFrame(output_handle, add, 187);

	++add.Y;
	DrawFrame(output_handle, add, 186);

	add.X -= 15;
	DrawFrame(output_handle, add, 186);
	add.X += 15;

	add.X -= 15;
	++add.Y;
	DrawFrame(output_handle, add, 200);

	for (int i = 0; i < 14; i++)
	{
		++add.X;
		DrawFrame(output_handle, add, 461);
	}
	++add.X;
	DrawFrame(output_handle, add, 188);

	add.X += 49;
	--add.Y;
	SetConsoleCursorPosition(output_handle, add);

	if (selected_item == 2)
	{
		SetConsoleTextAttribute(output_handle, ACTIVE_COLOUR);
	}

	std::cout << "Return the book";

	if (selected_item == 2)
	{
		SetConsoleTextAttribute(output_handle, INACTIVE_COLOUR);
	}

	add.X -= 2;
	--add.Y;
	DrawFrame(output_handle, add, 201);
	for (int i = 0; i < 17; i++)
	{
		++add.X;
		DrawFrame(output_handle, add, 461);
	}
	++add.X;
	DrawFrame(output_handle, add, 187);

	++add.Y;
	DrawFrame(output_handle, add, 186);

	add.X -= 18;
	DrawFrame(output_handle, add, 186);
	add.X += 18;

	add.X -= 18;
	++add.Y;
	DrawFrame(output_handle, add, 200);

	for (int i = 0; i < 17; i++)
	{
		++add.X;
		DrawFrame(output_handle, add, 461);
	}
	++add.X;
	DrawFrame(output_handle, add, 188);

	add.X -= 58;
	add.Y -= 2;
	DrawFrame(output_handle, add, 201);
	for (int i = 0; i < 33; i++)
	{
		++add.X;
		DrawFrame(output_handle, add, 461);
	}
	++add.X;
	DrawFrame(output_handle, add, 187);

	++add.Y;
	DrawFrame(output_handle, add, 186);

	add.X -= 34;
	DrawFrame(output_handle, add, 186);
	add.X += 34;

	add.X -= 34;
	++add.Y;
	DrawFrame(output_handle, add, 200);

	for (int i = 0; i < 33; i++)
	{
		++add.X;
		DrawFrame(output_handle, add, 461);
	}
	++add.X;
	DrawFrame(output_handle, add, 188);
}