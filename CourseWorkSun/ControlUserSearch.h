#pragma once
#include <string>
#include <conio.h>
#include <fstream>
#include "User.h"
#include "ControlAdding.h"
#include "DrawSearch.h"

void ControlUserSearch(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR);