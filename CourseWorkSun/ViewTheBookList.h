#pragma once
#include <fstream>
#include <conio.h>
#include "ControlScreen.h"

void ViewTheBookList(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR);