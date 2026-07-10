#include "programDefine.h"
#include "windowEvent.h"
#include "enum.h"
#include <Windows.h>

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

    KeyCode pressedKey;

    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_KEYDOWN:
        switch (wParam) {

        case 0x01:
            pressedKey = KeyCode::LEFT_MOUSE_BUTTON;
            break; // VK_LBUTTON: Left mouse button
        case 0x02:
            pressedKey = KeyCode::RIGHT_MOUSE_BUTTON;
            break; // VK_RBUTTON: Right mouse button
        case 0x03:
            pressedKey = KeyCode::CONTROL_BREAK;
            break; // VK_CANCEL: Control-break processing
        case 0x04:
            pressedKey = KeyCode::MIDDLE_MOUSE_BUTTON;
            break; // VK_MBUTTON: Middle mouse button (three-button mouse)
        case 0x05:
            pressedKey = KeyCode::X1_MOUSE_BUTTON;
            break; // VK_XBUTTON1: X1 mouse button
        case 0x06:
            pressedKey = KeyCode::X2_MOUSE_BUTTON;
            break; // VK_XBUTTON2: X2 mouse button
        case 0x08:
            pressedKey = KeyCode::BACKSPACE;
            break; // VK_BACK: BACKSPACE key
        case 0x09:
            pressedKey = KeyCode::TAB;
            break; // VK_TAB: TAB key
        case 0x0C:
            pressedKey = KeyCode::CLEAR;
            break; // VK_CLEAR: CLEAR key
        case 0x0D:
            pressedKey = KeyCode::ENTER;
            break; // VK_RETURN: ENTER key
        case 0x10:
            pressedKey = KeyCode::SHIFT;
            break; // VK_SHIFT: SHIFT key
        case 0x11:
            pressedKey = KeyCode::CONTROL;
            break; // VK_CONTROL: CTRL key
        case 0x12:
            pressedKey = KeyCode::ALT;
            break; // VK_MENU: ALT key
        case 0x13:
            pressedKey = KeyCode::PAUSE;
            break; // VK_PAUSE: PAUSE key
        case 0x14:
            pressedKey = KeyCode::CAPS_LOCK;
            break; // VK_CAPITAL: CAPS LOCK key
        case 0x1B:        // VK_ESCAPE: ESC key
            pressedKey = KeyCode::ESCAPE;
            break;
        case 0x20:
            pressedKey = KeyCode::SPACE;
            break; // VK_SPACE: SPACEBAR
        case 0x21:
            pressedKey = KeyCode::PAGE_UP;
            break; // VK_PRIOR: PAGE UP key
        case 0x22:
            pressedKey = KeyCode::PAGE_DOWN;
            break; // VK_NEXT: PAGE DOWN key
        case 0x23:
            pressedKey = KeyCode::END;
            break; // VK_END: END key
        case 0x24:
            pressedKey = KeyCode::HOME;
            break; // VK_HOME: HOME key
        case 0x25:
            pressedKey = KeyCode::LEFT_ARROW;
            break; // VK_LEFT: LEFT ARROW key
        case 0x26:
            pressedKey = KeyCode::UP_ARROW;
            break; // VK_UP: UP ARROW key
        case 0x27:
            pressedKey = KeyCode::RIGHT_ARROW;
            break; // VK_RIGHT: RIGHT ARROW key
        case 0x28:
            pressedKey = KeyCode::DOWN_ARROW;
            break; // VK_DOWN: DOWN ARROW key
        case 0x29:
            pressedKey = KeyCode::SELECT;
            break; // VK_SELECT: SELECT key
        case 0x2A:
            pressedKey = KeyCode::PRINT;
            break; // VK_PRINT: PRINT key
        case 0x2B:
            pressedKey = KeyCode::EXECUTE;
            break; // VK_EXECUTE: EXECUTE key
        case 0x2C:
            pressedKey = KeyCode::PRINT_SCREEN;
            break; // VK_SNAPSHOT: PRINT SCREEN key
        case 0x2D:
            pressedKey = KeyCode::INSERT;
            break; // VK_INSERT: INS key
        case 0x2E:
            pressedKey = KeyCode::DELETE_KEY;
            break; // VK_DELETE: DEL key
        case 0x2F:
            pressedKey = KeyCode::HELP;
            break; // VK_HELP: HELP key
        case 0x30:
            pressedKey = KeyCode::KEY_0;
            break;// '0' key 
        case 0x31:
            pressedKey = KeyCode::KEY_1;
            break; // '1' key
        case 0x32:
            pressedKey = KeyCode::KEY_2;
            break; // '2' key
        case 0x33:
            pressedKey = KeyCode::KEY_3;
            break; // '3' key
        case 0x34:
            pressedKey = KeyCode::KEY_4;
            break; // '4' key
        case 0x35:
            pressedKey = KeyCode::KEY_5;
            break; // '5' key
        case 0x36:
            pressedKey = KeyCode::KEY_6;
            break; // '6' key
        case 0x37:
            pressedKey = KeyCode::KEY_7;
            break; // '7' key
        case 0x38:
            pressedKey = KeyCode::KEY_8;
            break; // '8' key
        case 0x39:
            pressedKey = KeyCode::KEY_9;
            break; // '9' key
        case 0x41:
            pressedKey = KeyCode::KEY_A;
            break; // 'A' key
        case 0x42:        // 'B' key
            pressedKey = KeyCode::KEY_B;
            break;
        case 0x43:
            pressedKey = KeyCode::KEY_C;
            break; // 'C' key
        case 0x44:
            pressedKey = KeyCode::KEY_D;
            break; // 'D' key
        case 0x45:
            pressedKey = KeyCode::KEY_E;
            break; // 'E' key
        case 0x46:
            pressedKey = KeyCode::KEY_F;
            break; // 'F' key
        case 0x47:        // 'G' key
            pressedKey = KeyCode::KEY_G;
            break;
        case 0x48:
            pressedKey = KeyCode::KEY_H;
            break; // 'H' key
        case 0x49:
            pressedKey = KeyCode::KEY_I;
            break; // 'I' key
        case 0x4A:
            pressedKey = KeyCode::KEY_J;
            break; // 'J' key
        case 0x4B:
            pressedKey = KeyCode::KEY_K;
            break; // 'K' key
        case 0x4C:
            pressedKey = KeyCode::KEY_L;
            break; // 'L' key
        case 0x4D:
            pressedKey = KeyCode::KEY_M;
            break; // 'M' key
        case 0x4E:
            pressedKey = KeyCode::KEY_N;
            break; // 'N' key
        case 0x4F:
            pressedKey = KeyCode::KEY_O;
            break; // 'O' key
        case 0x50:
            pressedKey = KeyCode::KEY_P;
            break; // 'P' key
        case 0x51:
            pressedKey = KeyCode::KEY_Q;
            break; // 'Q' key
        case 0x52:        // 'R' key
            pressedKey = KeyCode::KEY_R;
            break;
        case 0x53:
            pressedKey = KeyCode::KEY_S;
            break; // 'S' key
        case 0x54:
            pressedKey = KeyCode::KEY_T;
            break; // 'T' key
        case 0x55:
            pressedKey = KeyCode::KEY_U;
            break; // 'U' key
        case 0x56:
            pressedKey = KeyCode::KEY_V;
            break; // 'V' key
        case 0x57:
            pressedKey = KeyCode::KEY_W;
            break; // 'W' key
        case 0x58:
            pressedKey = KeyCode::KEY_X;
            break; // 'X' key
        case 0x59:
            pressedKey = KeyCode::KEY_Y;
            break; // 'Y' key
        case 0x5A:
            pressedKey = KeyCode::KEY_Z;
            break; // 'Z' key
        case 0x5B:
            pressedKey = KeyCode::LEFT_WINDOWS;
            break; // VK_LWIN: Left Windows key
        case 0x5C:
            pressedKey = KeyCode::RIGHT_WINDOWS;
            break; // VK_RWIN: Right Windows key
        case 0x60:
            pressedKey = KeyCode::NUMPAD_0;
            break; // VK_NUMPAD0: Numeric keypad 0 key
        case 0x61:
            pressedKey = KeyCode::NUMPAD_1;
            break; // VK_NUMPAD1: Numeric keypad 1 key
        case 0x62:
            pressedKey = KeyCode::NUMPAD_2;
            break; // VK_NUMPAD2: Numeric keypad 2 key
        case 0x63:
            pressedKey = KeyCode::NUMPAD_3;
            break; // VK_NUMPAD3: Numeric keypad 3 key
        case 0x64:
            pressedKey = KeyCode::NUMPAD_4;
            break; // VK_NUMPAD4: Numeric keypad 4 key
        case 0x65:
            pressedKey = KeyCode::NUMPAD_5;
            break; // VK_NUMPAD5: Numeric keypad 5 key
        case 0x66:
            pressedKey = KeyCode::NUMPAD_6;
            break; // VK_NUMPAD6: Numeric keypad 6 key
        case 0x67:
            pressedKey = KeyCode::NUMPAD_7;
            break; // VK_NUMPAD7: Numeric keypad 7 key
        case 0x68:
            pressedKey = KeyCode::NUMPAD_8;
            break; // VK_NUMPAD8: Numeric keypad 8 key
        case 0x69:
            pressedKey = KeyCode::NUMPAD_9;
            break; // VK_NUMPAD9: Numeric keypad 9 key
        case 0x6A:
            pressedKey = KeyCode::MULTIPLY;
            break; // VK_MULTIPLY: Multiply key (*)
        case 0x6B:
            pressedKey = KeyCode::ADD_KEY;
            break; // VK_ADD: Add key (+)
        case 0x6C:
            pressedKey = KeyCode::SEPARATOR;
            break; // VK_SEPARATOR: Separator key
        case 0x6D:
            pressedKey = KeyCode::SUBTRACT;
            break; // VK_SUBTRACT: Subtract key (-)
        case 0x6E:
            pressedKey = KeyCode::DECIMAL;
            break; // VK_DECIMAL: Decimal key (.)
        case 0x6F:
            pressedKey = KeyCode::DIVIDE;
            break; // VK_DIVIDE: Divide key (/)
        case 0x70:
            pressedKey = KeyCode::F1;
            break; // VK_F1
        case 0x71:
            pressedKey = KeyCode::F2;
            break; // VK_F2
        case 0x72:
            pressedKey = KeyCode::F3;
            break; // VK_F3
        case 0x73:
            pressedKey = KeyCode::F4;
            break; // VK_F4
        case 0x74:
            pressedKey = KeyCode::F5;
            break; // VK_F5
        case 0x75:
            pressedKey = KeyCode::F6;
            break; // VK_F6
        case 0x76:
            pressedKey = KeyCode::F7;
            break; // VK_F7
        case 0x77:
            pressedKey = KeyCode::F8;
            break; // VK_F8
        case 0x78:
            pressedKey = KeyCode::F9;
            break; // VK_F9
        case 0x79:
            pressedKey = KeyCode::F10;
            break; // VK_F10
        case 0x7A:
            pressedKey = KeyCode::F11;
            break; // VK_F11
        case 0x7B:
            pressedKey = KeyCode::F12;
            break; // VK_F12
        case 0x90:
            pressedKey = KeyCode::NUM_LOCK;
            break; // VK_NUMLOCK: NUM LOCK key
        case 0x91:
            pressedKey = KeyCode::SCROLL_LOCK;
            break; // VK_SCROLL: SCROLL LOCK key
        case 0xA0:
            pressedKey = KeyCode::LEFT_SHIFT;
            break; // VK_LSHIFT: Left SHIFT key
        case 0xA1:
            pressedKey = KeyCode::RIGHT_SHIFT;
            break; // VK_RSHIFT: Right SHIFT key
        case 0xA2:
            pressedKey = KeyCode::LEFT_CONTROL;
            break; // VK_LCONTROL: Left CONTROL key
        case 0xA3:
            pressedKey = KeyCode::RIGHT_CONTROL;
            break; // VK_RCONTROL: Right CONTROL key
        case 0xA4:
            pressedKey = KeyCode::LEFT_ALT;
            break; // VK_LMENU: Left ALT key
        case 0xA5:
            pressedKey = KeyCode::RIGHT_ALT;
            break;// VK_RMENU: Right ALT key
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }

        whenKeyPressed(pressedKey);

        break;
    case WM_MOUSEMOVE:
        trackCursorPosition(lParam);
        break;
    default:

        return DefWindowProc(hWnd, message, wParam, lParam);
    }



    return 0;
}
