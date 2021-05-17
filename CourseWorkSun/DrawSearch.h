#pragma once
#include <windows.h>
#include <iostream>
#include "ControlScreen.h"

void DrawSearch(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int selected_item);