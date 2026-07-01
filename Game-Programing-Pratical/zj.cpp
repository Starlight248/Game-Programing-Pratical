////	Ask the compiler to include minimal header files for our program.
//#define WIN32_LEAN_AND_MEAN
//#include <Windows.h>
//#include <iostream>
//#include <d3d9.h> //	include the Direct3D 9 library
//
//#pragma comment(lib,"d3d9.lib")
////--------------------------------------------------------------------
//
//using namespace std;
//
//// Window handle
//HWND g_hWnd = NULL;
//// Window structure
//WNDCLASS wndClass;
//// Window message
//MSG msg;
//IDirect3DDevice9* d3dDevice;
//
//int red = 0;
//int green = 0;
//int blue = 0;
////--------------------------------------------------------------------
//
////	Window Procedure, for event handling
//LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	switch (message)
//	{
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//
//	case WM_KEYDOWN:
//		switch (wParam)
//		{
//		case 0x51:
//			PostQuitMessage(0);
//			break;
//		case VK_ESCAPE:
//			PostQuitMessage(0);
//			break;
//		case 0x52:
//			red++;
//			break;
//		case 0x47:
//			green++;
//			break;
//		case 0x42:
//			blue++;
//			break;
//		}
//		break;
//	default:
//		return DefWindowProc(hWnd, message, wParam, lParam);
//	}
//	return 0;
//}
////--------------------------------------------------------------------
//
//void CreateMyWindow()
//{
//	//	Window's structure
//
//	//	Sset all members in wndClass to 0.
//	ZeroMemory(&wndClass, sizeof(wndClass));
//
//	//	Filling wndClass. You are to refer to MSDN for each of the members details.
//	//	These are the fundamental structure members to be specify, in order to create your window.
//	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
//	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wndClass.hInstance = GetModuleHandle(NULL);
//	wndClass.lpfnWndProc = WindowProcedure;
//	wndClass.lpszClassName = "Resident Evil";
//	wndClass.style = CS_HREDRAW | CS_VREDRAW;
//
//	//	Register the window.
//	RegisterClass(&wndClass);
//
//	/*
//		Step 2
//		Create the Window.
//	*/
//	//	You are to refer to MSDN for each of the parameters details.
//	g_hWnd = CreateWindowEx(0, wndClass.lpszClassName, "Resident Evil", WS_OVERLAPPEDWINDOW, 0, 100, 400, 300, NULL, NULL, GetModuleHandle(NULL), NULL);
//	ShowWindow(g_hWnd, 1);
//
//	//	Some interesting function to try out.
//	//	ShowCursor(false);
//}
//
//bool WindowIsRunning(MSG msg)
//{
//	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
//		//	Receive a quit message
//		if (msg.message == WM_QUIT) { return false; };
//		//	Translate the message 
//		TranslateMessage(&msg);
//		//	Send message to your window procedure
//		DispatchMessage(&msg);
//	}
//	return true;
//}
//
//void CleanupWindow() {
//	UnregisterClass(wndClass.lpszClassName, GetModuleHandle(NULL));
//}
//
//bool CreateDirectX() {
//	//	Define Direct3D 9.
//	IDirect3D9* direct3D9 = Direct3DCreate9(D3D_SDK_VERSION);
//
//	//	Define how the screen presents.
//	D3DPRESENT_PARAMETERS d3dPP;
//	ZeroMemory(&d3dPP, sizeof(d3dPP));
//
//	//	Refer to Direct3D 9 documentation for the meaning of the members.
//	d3dPP.Windowed = true;
//	d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
//	d3dPP.BackBufferFormat = D3DFMT_X8R8G8B8;
//	d3dPP.BackBufferCount = 1;
//	d3dPP.BackBufferWidth = 400;
//	d3dPP.BackBufferHeight = 300;
//	d3dPP.hDeviceWindow = g_hWnd;
//
//
//	HRESULT hr = direct3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dPP, &d3dDevice); //	Create a Direct3D 9 device.
//
//	return hr;
//}
//
//void Render() {
//	//	Clear the back buffer.
//	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(red, green, blue), 1.0f, 0);
//
//	//	Begin the scene
//	d3dDevice->BeginScene();
//
//	//	To Do:
//	//	Drawing.
//
//	//	End the scene
//	d3dDevice->EndScene();
//
//	//	Present the back buffer to screen
//	d3dDevice->Present(NULL, NULL, NULL, NULL);
//}
//
//void CleanupDirect() {
//	d3dDevice->Release();	//	Release the device when exiting.
//	d3dDevice = NULL;		//	Reset pointer to NULL, a good practice.
//}
//
////	use int main if you want to have a console to print out message
////int main()
//
////	use WinMain if you don't want the console
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
//	/*
//		Step 1
//		Define and Register a Window.
//	*/
//
//	ZeroMemory(&msg, sizeof(msg));
//	CreateMyWindow();
//	HRESULT hr = CreateDirectX();
//
//	//	To Do: Cout out the message to indicate the failure.
//	if (FAILED(hr))
//		return 0;
//
//
//	while (WindowIsRunning(msg)) {
//		Render();
//	}
//
//	//	Free up the memory.	
//	CleanupDirect();
//	CleanupWindow();
//
//	return 0;
//}
////--------------------------------------------------------------------