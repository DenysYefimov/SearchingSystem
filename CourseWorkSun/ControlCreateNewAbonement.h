#pragma once
#include <conio.h>
#include <fstream>
#include <iostream>
#include "Book.h"
#include "User.h"
#include "DrawSearch.h"
#include "DrawSuccessfully.h"

void ControlCreateNewAbonement(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR);