//	Ask the compiler to include minimal header files for our program.
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include<iostream>

using namespace std;
//--------------------------------------------------------------------

//	Window handle
HWND g_hWnd = NULL;
WNDCLASS wndClass;
//--------------------------------------------------------------------

void createWindow() {
    /*
    Step 1
    Define and Register a Window.
*/

//	Window's structure
    
    //	Sset all members in wndClass to 0.
    ZeroMemory(&wndClass, sizeof(wndClass));

    //	Filling wndClass. You are to refer to MSDN for each of the members details.
    //	These are the fundamental structure members to be specify, in order to create your window.
    wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hInstance = GetModuleHandle(NULL);	//	GetModuleHandle(NULL);
    wndClass.lpfnWndProc = WindowProcedure;
    wndClass.lpszClassName = "My Window";
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
void cleanupWindow() {
    //	Free up the memory.
    UnregisterClass(wndClass.lpszClassName, GetModuleHandle(NULL));
    return;
};

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
//--------------------------------------------------------------------

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
        }
        /*
            Write your code here...
        */

        //	Default handling for other messages.
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


//	use int main if you want to have a console to print out message
//int main()

//	use WinMain if you don't want the console
                    //ID Nunber,		obs ID number of parent, command line parameter,
int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

    createWindow();


    //TODO
    while (windowIsRunning())
    {
        // Do something… 
        //Game->getInput()
        //Game->Physics()
        //Game->render()
        
    }
    cleanupWindow();



    return 0;
}
//--------------------------------------------------------------------

