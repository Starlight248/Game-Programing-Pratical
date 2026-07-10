#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "Initialization.h"


extern HWND g_hWnd;

bool windowIsRunning();

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
