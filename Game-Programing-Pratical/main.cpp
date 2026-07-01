//	Ask the compiler to include minimal header files for our program.
#define WIN32_LEAN_AND_MEAN
#include<d3d9.h>
#include <Windows.h>
#include<iostream>

#pragma comment(lib,"d3d9.lib")

using namespace std;
//Global Var
//--------------------------------------------------------------------
HWND g_hWnd = NULL; //	Window handle
WNDCLASS wndClass;
IDirect3DDevice9* d3dDevice;

int red = 0;
int green = 0;
int blue = 0;

//--------------------------------------------------------------------
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
bool createDirectX();
void createWindow();
void cleanUpDirectX();
void cleanupWindow();
void render();
bool windowIsRunning();
//--------------------------------------------------------------------


/*
Return True if DirectX Succesfully created, else false
*/
bool createDirectX() {
    //	Define how the screen presents.
    D3DPRESENT_PARAMETERS d3dPP;
    ZeroMemory(&d3dPP, sizeof(d3dPP));
    //	Define Direct3D 9.
    IDirect3D9* direct3D9 = Direct3DCreate9(D3D_SDK_VERSION);

    //	Refer to Direct3D 9 documentation for the meaning of the members.
    d3dPP.Windowed = true;
    d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dPP.BackBufferFormat = D3DFMT_X8R8G8B8;
    d3dPP.BackBufferCount = 1;
    d3dPP.BackBufferWidth = 400;
    d3dPP.BackBufferHeight = 300;
    d3dPP.hDeviceWindow = g_hWnd;



    //	Create a Direct3D 9 device.
    HRESULT hr = direct3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dPP, &d3dDevice);
    if (FAILED(hr))
        return false;
    else
    {
        return true;
    }
}

void createWindow() {

//	Window's structure
    
    //	Sset all members in wndClass to 0.
    ZeroMemory(&wndClass, sizeof(wndClass));

    //	Filling wndClass. You are to refer to MSDN for each of the members details.
    //	These are the fundamental structure members to be specify, in order to create your window.
    wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hInstance = GetModuleHandle(NULL);	//	GetModuleHandle(NULL);
    wndClass.lpfnWndProc = WindowProcedure;
    wndClass.lpszClassName = "Spy Family";
    wndClass.style = CS_HREDRAW | CS_VREDRAW;

    //	Register the window.
    RegisterClass(&wndClass);

    /*
        Step 2
        Create the Window.
    */
    //	You are to refer to MSDN for each of the parameters details.
    g_hWnd = CreateWindowEx(0, wndClass.lpszClassName, "???", WS_OVERLAPPEDWINDOW, 0, 100, 400, 300, NULL, NULL, GetModuleHandle(NULL), NULL);
    ShowWindow(g_hWnd, 1);

    //	Some interesting function to try out.
    //	ShowCursor(false);
        //	Free up the memory.
    UnregisterClass(wndClass.lpszClassName, GetModuleHandle(NULL));

     


    return;

}

void cleanUpDirectX() {
    d3dDevice->Release();//	Release the device when exiting.
    d3dDevice = NULL;//	Reset pointer to NULL, a good practice.
}

void cleanupWindow() {
    //	Free up the memory.
    UnregisterClass(wndClass.lpszClassName, GetModuleHandle(NULL));
    return;
};

void render() {
    //	Clear the back buffer.
    d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(red, green, blue), 1.0f, 0);

    //	Begin the scene
    d3dDevice->BeginScene();

    //	End the scene
    d3dDevice->EndScene();

    //	Present the back buffer to screen
    d3dDevice->Present(NULL, NULL, NULL, NULL);

}

bool windowIsRunning() {
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));

    /*
        Step 3
        Handling window messages
        NOTE! There are several ways of writing the message loop.
        You have to based on which kind of application your are writing.
    */
    while (msg.message != WM_QUIT)
    {
        /*
            The if- version process one message per one iteration loop
            The while- version will clear the message queue before dealing with your own code.

            Another function is GetMessage.
            This function is not suitable for game, because it will block your program until it recieves a message.
            your code will only executed when you have messages, otherwies your pogram will be waiting... (similar to cin)
            Suitable for event based program, such as bussiness app.
        */
        //	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            //	Receive a quit message
            if (msg.message == WM_QUIT)
            {
                return false;
            };
            //	Translate the message 
            TranslateMessage(&msg);
            //	Send message to your window procedure
            DispatchMessage(&msg);
            return true;
        }
        /*
            Write your code here...
        */
    }
    return false;
}

//	Window Procedure, for event handling
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        //	The message is post when we destroy the window.
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_KEYDOWN:
        switch (wParam) {

            //A
        case 0x41:
            break;
            //Esc
        case 0x1B:
            PostQuitMessage(0);
            break;
            //r
        case 0x52:
            red+=10;
            break;
            //g
        case 0x47:
            green += 10;
            break;
            //b
        case 0x42:
            blue += 10;
            break;
            //0
        case 0x30:
            red = 0;
            blue = 0;
            green = 0;
            break;
        

        }
        break;
        /*
            Write your code here...
        */

        //	Default handling for other messages.
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


//--------------------------------------------------------------------

//	use int main if you want to have a console to print out message
//int main()
//	use WinMain if you don't want the console
                    //ID Nunber,		obs ID number of parent, command line parameter,
int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

    createWindow();
    bool isDirectXCreated = createDirectX();
    

    //TODO
    while (windowIsRunning()&& isDirectXCreated)
    {
        // Do something… 
        //Game->getInput()
        //Game->Physics()
        //Game->render()
        render();
        
    }
    cleanupWindow();
    cleanUpDirectX();



    return 0;
}
//--------------------------------------------------------------------

