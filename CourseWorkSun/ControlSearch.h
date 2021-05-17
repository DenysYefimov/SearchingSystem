#pragma once
#include <conio.h>
#include "DrawSearch.h"
#include "DrawInterface.h"
#include "ControlUserSearch.h"
#include "DrawBookSearch.h"
#include "ControlBookSearch.h"

void ControlSearch(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR);