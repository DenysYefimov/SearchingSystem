#pragma once
#include <iostream>
#include "ControlScreen.h"
#include "DrawFrame.h"

void DrawUserSearch(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int selected_item = 0);