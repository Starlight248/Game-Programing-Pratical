#pragma once
#include <Windows.h>



class WindowEvent {
	bool windowIsRunning();

	LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
}