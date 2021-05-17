#pragma once
#include <string>
#include <conio.h>
#include <iostream>
#include <fstream>
#include "Book.h"
#include "DrawSearch.h"
#include "DrawBookSearch.h"

void ControlBookSearch(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR);