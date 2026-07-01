#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <d3d9.h>
#include <iostream>

#pragma comment(lib, "d3d9.lib")

using namespace std;

HWND g_hWnd = NULL;	//window handle
WNDCLASS wndClass;	//window structure
MSG msg;

int red = 0;
int blue = 0;
int green = 0;

const char* g_szClassName = "Genshin 2.0";	//window name

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		switch (wParam) {
		case 0x51:
			PostQuitMessage(0);
			break;
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		case 0x52:
			red++;
			break;
		case 0x47:
			green++;
			break;
		case 0x42:
			blue++;
			break;
		}
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void CreateMyWindow()
{
	HINSTANCE hInstance = GetModuleHandle(NULL);
	ZeroMemory(&wndClass, sizeof(wndClass));

	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hInstance = GetModuleHandle(NULL);
	wndClass.lpfnWndProc = WindowProcedure;
	wndClass.lpszClassName = "Genshin 2.0";
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);
	g_hWnd = CreateWindowEx(0, wndClass.lpszClassName, "Genshin 2.0", WS_OVERLAPPEDWINDOW, 0, 100, 1080, 720, NULL, NULL, wndClass.hInstance, NULL);
	ShowWindow(g_hWnd, 1);

	ZeroMemory(&msg, sizeof(msg));
}

bool WindowIsRunning()
{
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
		{
			return false;
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return true;
}

void CleanupWindow()
{
	UnregisterClass(wndClass.lpszClassName, GetModuleHandle(NULL));
}

void Render()
{
	//	To Do:
		//	Update.

		//	Clear the back buffer.
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(red, green, blue), 1.0f, 0);

	//	Begin the scene
	d3dDevice->BeginScene();

	//	To Do:
	//	Drawing.

	//	End the scene
	d3dDevice->EndScene();

	//	Present the back buffer to screen
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

void CreateDirectX() {
	//	Define Direct3D 9.

	//	Define how the screen presents.
	D3DPRESENT_PARAMETERS d3dPP;
	ZeroMemory(&d3dPP, sizeof(d3dPP));

	//	Refer to Direct3D 9 documentation for the meaning of the members.
	d3dPP.Windowed = true;
	d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dPP.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dPP.BackBufferCount = 1;
	d3dPP.BackBufferWidth = 400;
	d3dPP.BackBufferHeight = 300;
	d3dPP.hDeviceWindow = g_hWnd;

	IDirect3DDevice9* d3dDevice;
	//	Create a Direct3D 9 device.
	HRESULT hr = direct3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dPP, &d3dDevice);

	//	To Do: Cout out the message to indicate the failure.
	if (FAILED(hr))
		return 0;
}

void CleanUpDirectX()
{
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	CreateMyWindow();
	CreateDirectX();


	while (WindowIsRunning())
	{
		//Game - GetInput()
		//Game - Physics()
		//Game - Update()
		//Game - Render()
		Render();

	}

	//	Release the device when exiting.
	d3dDevice->Release();
	//	Reset pointer to NULL, a good practice.
	d3dDevice = NULL;
	CleanUpDirectX();
	CleanupWindow();

	return 0;
}