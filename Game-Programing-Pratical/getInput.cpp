#include "getInput.h"
#include "programDefine.h"

void keyPressedWindow(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_KEYDOWN:
        switch (wParam) {

        case 0x01:
            keyPressedWin.push(KeyCodeWindowInput::LEFT_MOUSE_BUTTON);
            break; // VK_LBUTTON: Left mouse button
        case 0x02:
            keyPressedWin.push(KeyCodeWindowInput::RIGHT_MOUSE_BUTTON);
            break; // VK_RBUTTON: Right mouse button
        case 0x03:
            keyPressedWin.push(KeyCodeWindowInput::CONTROL_BREAK);
            break; // VK_CANCEL: Control-break processing
        case 0x04:
            keyPressedWin.push(KeyCodeWindowInput::MIDDLE_MOUSE_BUTTON);
            break; // VK_MBUTTON: Middle mouse button (three-button mouse)
        case 0x05:
            keyPressedWin.push(KeyCodeWindowInput::X1_MOUSE_BUTTON);
            break; // VK_XBUTTON1: X1 mouse button
        case 0x06:
            keyPressedWin.push(KeyCodeWindowInput::X2_MOUSE_BUTTON);
            break; // VK_XBUTTON2: X2 mouse button
        case 0x08:
            keyPressedWin.push(KeyCodeWindowInput::BACKSPACE);
            break; // VK_BACK: BACKSPACE key
        case 0x09:
            keyPressedWin.push(KeyCodeWindowInput::TAB);
            break; // VK_TAB: TAB key
        case 0x0C:
            keyPressedWin.push(KeyCodeWindowInput::CLEAR);
            break; // VK_CLEAR: CLEAR key
        case 0x0D:
            keyPressedWin.push(KeyCodeWindowInput::ENTER);
            break; // VK_RETURN: ENTER key
        case 0x10:
            keyPressedWin.push(KeyCodeWindowInput::SHIFT);
            break; // VK_SHIFT: SHIFT key
        case 0x11:
            keyPressedWin.push(KeyCodeWindowInput::CONTROL);
            break; // VK_CONTROL: CTRL key
        case 0x12:
            keyPressedWin.push(KeyCodeWindowInput::ALT);
            break; // VK_MENU: ALT key
        case 0x13:
            keyPressedWin.push(KeyCodeWindowInput::PAUSE);
            break; // VK_PAUSE: PAUSE key
        case 0x14:
            keyPressedWin.push(KeyCodeWindowInput::CAPS_LOCK);
            break; // VK_CAPITAL: CAPS LOCK key
        case 0x1B:        // VK_ESCAPE: ESC key
            keyPressedWin.push(KeyCodeWindowInput::ESCAPE);
            break;
        case 0x20:
            keyPressedWin.push(KeyCodeWindowInput::SPACE);
            break; // VK_SPACE: SPACEBAR
        case 0x21:
            keyPressedWin.push(KeyCodeWindowInput::PAGE_UP);
            break; // VK_PRIOR: PAGE UP key
        case 0x22:
            keyPressedWin.push(KeyCodeWindowInput::PAGE_DOWN);
            break; // VK_NEXT: PAGE DOWN key
        case 0x23:
            keyPressedWin.push(KeyCodeWindowInput::END);
            break; // VK_END: END key
        case 0x24:
            keyPressedWin.push(KeyCodeWindowInput::HOME);
            break; // VK_HOME: HOME key
        case 0x25:
            keyPressedWin.push(KeyCodeWindowInput::LEFT_ARROW);
            break; // VK_LEFT: LEFT ARROW key
        case 0x26:
            keyPressedWin.push(KeyCodeWindowInput::UP_ARROW);
            break; // VK_UP: UP ARROW key
        case 0x27:
            keyPressedWin.push(KeyCodeWindowInput::RIGHT_ARROW);
            break; // VK_RIGHT: RIGHT ARROW key
        case 0x28:
            keyPressedWin.push(KeyCodeWindowInput::DOWN_ARROW);
            break; // VK_DOWN: DOWN ARROW key
        case 0x29:
            keyPressedWin.push(KeyCodeWindowInput::SELECT);
            break; // VK_SELECT: SELECT key
        case 0x2A:
            keyPressedWin.push(KeyCodeWindowInput::PRINT);
            break; // VK_PRINT: PRINT key
        case 0x2B:
            keyPressedWin.push(KeyCodeWindowInput::EXECUTE);
            break; // VK_EXECUTE: EXECUTE key
        case 0x2C:
            keyPressedWin.push(KeyCodeWindowInput::PRINT_SCREEN);
            break; // VK_SNAPSHOT: PRINT SCREEN key
        case 0x2D:
            keyPressedWin.push(KeyCodeWindowInput::INSERT);
            break; // VK_INSERT: INS key
        case 0x2E:
            keyPressedWin.push(KeyCodeWindowInput::DELETE_KEY) ;
            break; // VK_DELETE: DEL key
        case 0x2F:
            keyPressedWin.push(KeyCodeWindowInput::HELP);
            break; // VK_HELP: HELP key
        case 0x30:
            keyPressedWin.push(KeyCodeWindowInput::KEY_0);
            break;// '0' key 
        case 0x31:
            keyPressedWin.push(KeyCodeWindowInput::KEY_1);
            break; // '1' key
        case 0x32:
            keyPressedWin.push(KeyCodeWindowInput::KEY_2);
            break; // '2' key
        case 0x33:
            keyPressedWin.push(KeyCodeWindowInput::KEY_3);
            break; // '3' key
        case 0x34:
            keyPressedWin.push(KeyCodeWindowInput::KEY_4);
            break; // '4' key
        case 0x35:
            keyPressedWin.push(KeyCodeWindowInput::KEY_5);
            break; // '5' key
        case 0x36:
            keyPressedWin.push(KeyCodeWindowInput::KEY_6);
            break; // '6' key
        case 0x37:
            keyPressedWin.push(KeyCodeWindowInput::KEY_7);
            break; // '7' key
        case 0x38:
            keyPressedWin.push(KeyCodeWindowInput::KEY_8);
            break; // '8' key
        case 0x39:
            keyPressedWin.push(KeyCodeWindowInput::KEY_9);
            break; // '9' key
        case 0x41:
            keyPressedWin.push(KeyCodeWindowInput::KEY_A);
            break; // 'A' key
        case 0x42:        // 'B' key
            keyPressedWin.push(KeyCodeWindowInput::KEY_B);
            break;
        case 0x43:
            keyPressedWin.push(KeyCodeWindowInput::KEY_C);
            break; // 'C' key
        case 0x44:
            keyPressedWin.push(KeyCodeWindowInput::KEY_D);
            break; // 'D' key
        case 0x45:
            keyPressedWin.push(KeyCodeWindowInput::KEY_E);
            break; // 'E' key
        case 0x46:
            keyPressedWin.push(KeyCodeWindowInput::KEY_F);
            break; // 'F' key
        case 0x47:        // 'G' key
            keyPressedWin.push(KeyCodeWindowInput::KEY_G);
            break;
        case 0x48:
            keyPressedWin.push(KeyCodeWindowInput::KEY_H);
            break; // 'H' key
        case 0x49:
            keyPressedWin.push(KeyCodeWindowInput::KEY_I);
            break; // 'I' key
        case 0x4A:
            keyPressedWin.push(KeyCodeWindowInput::KEY_J);
            break; // 'J' key
        case 0x4B:
            keyPressedWin.push(KeyCodeWindowInput::KEY_K);
            break; // 'K' key
        case 0x4C:
            keyPressedWin.push(KeyCodeWindowInput::KEY_L);
            break; // 'L' key
        case 0x4D:
            keyPressedWin.push(KeyCodeWindowInput::KEY_M);
            break; // 'M' key
        case 0x4E:
            keyPressedWin.push(KeyCodeWindowInput::KEY_N);
            break; // 'N' key
        case 0x4F:
            keyPressedWin.push(KeyCodeWindowInput::KEY_O);
            break; // 'O' key
        case 0x50:
            keyPressedWin.push(KeyCodeWindowInput::KEY_P);
            break; // 'P' key
        case 0x51:
            keyPressedWin.push(KeyCodeWindowInput::KEY_Q);
            break; // 'Q' key
        case 0x52:        // 'R' key
            keyPressedWin.push(KeyCodeWindowInput::KEY_R);
            break;
        case 0x53:
            keyPressedWin.push(KeyCodeWindowInput::KEY_S);
            break; // 'S' key
        case 0x54:
            keyPressedWin.push(KeyCodeWindowInput::KEY_T);
            break; // 'T' key
        case 0x55:
            keyPressedWin.push(KeyCodeWindowInput::KEY_U);
            break; // 'U' key
        case 0x56:
            keyPressedWin.push(KeyCodeWindowInput::KEY_V);
            break; // 'V' key
        case 0x57:
            keyPressedWin.push(KeyCodeWindowInput::KEY_W);
            break; // 'W' key
        case 0x58:
            keyPressedWin.push(KeyCodeWindowInput::KEY_X);
            break; // 'X' key
        case 0x59:
            keyPressedWin.push(KeyCodeWindowInput::KEY_Y);
            break; // 'Y' key
        case 0x5A:
            keyPressedWin.push(KeyCodeWindowInput::KEY_Z);
            break; // 'Z' key
        case 0x5B:
            keyPressedWin.push(KeyCodeWindowInput::LEFT_WINDOWS);
            break; // VK_LWIN: Left Windows key
        case 0x5C:
            keyPressedWin.push(KeyCodeWindowInput::RIGHT_WINDOWS);
            break; // VK_RWIN: Right Windows key
        case 0x60:
            keyPressedWin.push(KeyCodeWindowInput::NUMPAD_0);
            break; // VK_NUMPAD0: Numeric keypad 0 key
        case 0x61:
            keyPressedWin.push(KeyCodeWindowInput::NUMPAD_1);
            break; // VK_NUMPAD1: Numeric keypad 1 key
        case 0x62:
            keyPressedWin.push(KeyCodeWindowInput::NUMPAD_2);
            break; // VK_NUMPAD2: Numeric keypad 2 key
        case 0x63:
            keyPressedWin.push(KeyCodeWindowInput::NUMPAD_3);
            break; // VK_NUMPAD3: Numeric keypad 3 key
        case 0x64:
            keyPressedWin.push(KeyCodeWindowInput::NUMPAD_4);
            break; // VK_NUMPAD4: Numeric keypad 4 key
        case 0x65:
            keyPressedWin.push(KeyCodeWindowInput::NUMPAD_5);
            break; // VK_NUMPAD5: Numeric keypad 5 key
        case 0x66:
            keyPressedWin.push(KeyCodeWindowInput::NUMPAD_6);
            break; // VK_NUMPAD6: Numeric keypad 6 key
        case 0x67:
            keyPressedWin.push(KeyCodeWindowInput::NUMPAD_7);
            break; // VK_NUMPAD7: Numeric keypad 7 key
        case 0x68:
            keyPressedWin.push(KeyCodeWindowInput::NUMPAD_8);
            break; // VK_NUMPAD8: Numeric keypad 8 key
        case 0x69:
            keyPressedWin.push(KeyCodeWindowInput::NUMPAD_9);
            break; // VK_NUMPAD9: Numeric keypad 9 key
        case 0x6A:
            keyPressedWin.push(KeyCodeWindowInput::MULTIPLY);
            break; // VK_MULTIPLY: Multiply key (*)
        case 0x6B:
            keyPressedWin.push(KeyCodeWindowInput::ADD_KEY);
            break; // VK_ADD: Add key (+)
        case 0x6C:
            keyPressedWin.push(KeyCodeWindowInput::SEPARATOR);
            break; // VK_SEPARATOR: Separator key
        case 0x6D:
            keyPressedWin.push(KeyCodeWindowInput::SUBTRACT);
            break; // VK_SUBTRACT: Subtract key (-)
        case 0x6E:
            keyPressedWin.push(KeyCodeWindowInput::DECIMAL);
            break; // VK_DECIMAL: Decimal key (.)
        case 0x6F:
            keyPressedWin.push(KeyCodeWindowInput::DIVIDE);
            break; // VK_DIVIDE: Divide key (/)
        case 0x70:
            keyPressedWin.push(KeyCodeWindowInput::F1);
            break; // VK_F1
        case 0x71:
            keyPressedWin.push(KeyCodeWindowInput::F2);
            break; // VK_F2
        case 0x72:
            keyPressedWin.push(KeyCodeWindowInput::F3);
            break; // VK_F3
        case 0x73:
            keyPressedWin.push(KeyCodeWindowInput::F4);
            break; // VK_F4
        case 0x74:
            keyPressedWin.push(KeyCodeWindowInput::F5);
            break; // VK_F5
        case 0x75:
            keyPressedWin.push(KeyCodeWindowInput::F6);
            break; // VK_F6
        case 0x76:
            keyPressedWin.push(KeyCodeWindowInput::F7);
            break; // VK_F7
        case 0x77:
            keyPressedWin.push(KeyCodeWindowInput::F8);
            break; // VK_F8
        case 0x78:
            keyPressedWin.push(KeyCodeWindowInput::F9);
            break; // VK_F9
        case 0x79:
            keyPressedWin.push(KeyCodeWindowInput::F10);
            break; // VK_F10
        case 0x7A:
            keyPressedWin.push(KeyCodeWindowInput::F11);
            break; // VK_F11
        case 0x7B:
            keyPressedWin.push(KeyCodeWindowInput::F12);
            break; // VK_F12
        case 0x90:
            keyPressedWin.push(KeyCodeWindowInput::NUM_LOCK);
            break; // VK_NUMLOCK: NUM LOCK key
        case 0x91:
            keyPressedWin.push(KeyCodeWindowInput::SCROLL_LOCK);
            break; // VK_SCROLL: SCROLL LOCK key
        case 0xA0:
            keyPressedWin.push(KeyCodeWindowInput::LEFT_SHIFT);
            break; // VK_LSHIFT: Left SHIFT key
        case 0xA1:
            keyPressedWin.push(KeyCodeWindowInput::RIGHT_SHIFT);
            break; // VK_RSHIFT: Right SHIFT key
        case 0xA2:
            keyPressedWin.push(KeyCodeWindowInput::LEFT_CONTROL);
            break; // VK_LCONTROL: Left CONTROL key
        case 0xA3:
            keyPressedWin.push(KeyCodeWindowInput::RIGHT_CONTROL);
            break; // VK_RCONTROL: Right CONTROL key
        case 0xA4:
            keyPressedWin.push(KeyCodeWindowInput::LEFT_ALT);
            break; // VK_LMENU: Left ALT key
        case 0xA5:
            keyPressedWin.push(KeyCodeWindowInput::RIGHT_ALT);
            break;// VK_RMENU: Right ALT key
        default:
            return;
        }

        whenKeyPressed(keyPressedWin);

        break;
    case WM_MOUSEMOVE:
        trackCursorPosition(lParam);
        break;
    }
}