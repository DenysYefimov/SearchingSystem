#pragma once
#include <windows.h>
#include <conio.h>
#include "DrawInterface.h"
#include "DrawSearch.h"
#include "ControlSearch.h"
#include "Exit.h"
#include "DrawCreateNewAbonement.h"
#include "ControlCreateNewAbonement.h"
#include "ViewAbonentList.h"
#include "ViewTheBookList.h"

void ControlInterface(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR);