#pragma once
#include "enum.h"
#include <queue>

extern std::queue<KeyCodeWindowInput> keyPressedWin;

void keyPressedWindow(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);