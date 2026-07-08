//	Ask the compiler to include minimal header files for our program.
#define WIN32_LEAN_AND_MEAN
#include<d3d9.h>
#include <Windows.h>
#include<iostream>
#include <d3dx9.h>
#include <vector>

using namespace std;
//Class
//--------------------------------------------------------------------

enum class SpriteID {
    CHARACTER,
    CURSOR,

    COUNT, //This must Be last element.

};
enum class KeyCode
{
    LEFT_MOUSE_BUTTON = 0x01,
    RIGHT_MOUSE_BUTTON = 0x02,
    CONTROL_BREAK = 0x03, // Cancel (Ctrl+Pause)
    MIDDLE_MOUSE_BUTTON = 0x04,
    X1_MOUSE_BUTTON = 0x05,
    X2_MOUSE_BUTTON = 0x06,
    BACKSPACE = 0x08,
    TAB = 0x09,
    CLEAR = 0x0C,
    ENTER = 0x0D, // Return
    SHIFT = 0x10,
    CONTROL = 0x11, // Ctrl
    ALT = 0x12, // Menu
    PAUSE = 0x13,
    CAPS_LOCK = 0x14,
    ESCAPE = 0x1B, // Esc
    SPACE = 0x20,
    PAGE_UP = 0x21,
    PAGE_DOWN = 0x22,
    END = 0x23,
    HOME = 0x24,
    LEFT_ARROW = 0x25,
    UP_ARROW = 0x26,
    RIGHT_ARROW = 0x27,
    DOWN_ARROW = 0x28,
    SELECT = 0x29,
    PRINT = 0x2A,
    EXECUTE = 0x2B,
    PRINT_SCREEN = 0x2C,
    INSERT = 0x2D,
    DELETE_KEY = 0x2E,
    HELP = 0x2F,
    KEY_0 = 0x30,
    KEY_1 = 0x31,
    KEY_2 = 0x32,
    KEY_3 = 0x33,
    KEY_4 = 0x34,
    KEY_5 = 0x35,
    KEY_6 = 0x36,
    KEY_7 = 0x37,
    KEY_8 = 0x38,
    KEY_9 = 0x39,
    KEY_A = 0x41,
    KEY_B = 0x42,
    KEY_C = 0x43,
    KEY_D = 0x44,
    KEY_E = 0x45,
    KEY_F = 0x46,
    KEY_G = 0x47,
    KEY_H = 0x48,
    KEY_I = 0x49,
    KEY_J = 0x4A,
    KEY_K = 0x4B,
    KEY_L = 0x4C,
    KEY_M = 0x4D,
    KEY_N = 0x4E,
    KEY_O = 0x4F,
    KEY_P = 0x50,
    KEY_Q = 0x51,
    KEY_R = 0x52,
    KEY_S = 0x53,
    KEY_T = 0x54,
    KEY_U = 0x55,
    KEY_V = 0x56,
    KEY_W = 0x57,
    KEY_X = 0x58,
    KEY_Y = 0x59,
    KEY_Z = 0x5A,
    LEFT_WINDOWS = 0x5B,
    RIGHT_WINDOWS = 0x5C,
    NUMPAD_0 = 0x60,
    NUMPAD_1 = 0x61,
    NUMPAD_2 = 0x62,
    NUMPAD_3 = 0x63,
    NUMPAD_4 = 0x64,
    NUMPAD_5 = 0x65,
    NUMPAD_6 = 0x66,
    NUMPAD_7 = 0x67,
    NUMPAD_8 = 0x68,
    NUMPAD_9 = 0x69,
    MULTIPLY = 0x6A, // *
    ADD_KEY = 0x6B, // +
    SEPARATOR = 0x6C,
    SUBTRACT = 0x6D, // -
    DECIMAL = 0x6E, // .
    DIVIDE = 0x6F, // /
    F1 = 0x70,
    F2 = 0x71,
    F3 = 0x72,
    F4 = 0x73,
    F5 = 0x74,
    F6 = 0x75,
    F7 = 0x76,
    F8 = 0x77,
    F9 = 0x78,
    F10 = 0x79,
    F11 = 0x7A,
    F12 = 0x7B,
    NUM_LOCK = 0x90,
    SCROLL_LOCK = 0x91,
    LEFT_SHIFT = 0xA0,
    RIGHT_SHIFT = 0xA1,
    LEFT_CONTROL = 0xA2,
    RIGHT_CONTROL = 0xA3,
    LEFT_ALT = 0xA4,
    RIGHT_ALT = 0xA5
};
class RGBColor {
private:
    int red;
    int green;
    int blue;
    int last_red;
    int last_blue;
    int last_green;

public:
    RGBColor() :red(0), blue(0), green(0), last_red(-1), last_blue(-1), last_green(-1) {
    }
    RGBColor(int r, int g, int b) : red(r), green(g), blue(b), last_red(-1), last_blue(-1), last_green(-1) {
        checkCrossing(&red);
        checkCrossing(&blue);
        checkCrossing(&green);
    }

    int getRedValue() const {
        return this->red;

    }

    int getBlueValue() const {
        return this->blue;
    }

    int getGreenValue() const {
        return this->green;
    }

    void setRed(int red) {
        this->red = red;
        checkCrossing(&red);
    }

    void setBlue(int blue) {
        this->blue = blue;
        checkCrossing(&blue);
    }

    void setGreen(int green) {
        this->green = green;
        checkCrossing(&green);
    }
    void increaseColorValue(int* color_address, int* last_color_address, int value) {
        *last_color_address = *color_address;
        *color_address += value;
        checkCrossing(color_address);
    }

    void decreaseColorValue(int* color_address, int* last_color_address, int value) {
        *last_color_address = *color_address;
        *color_address -= value;
        checkCrossing(color_address);
    }


    void changeGreen(int value) {
        bool increase = checkIncreasement(&(this->green), value);
        if (increase) increaseColorValue(&(this->green), &(this->last_green), value);
        else if (!increase) decreaseColorValue(&(this->green), &(this->last_green), value);
    }

    void changeRed(int value) {
        bool increase = checkIncreasement(&(this->red), value);
        if (increase) increaseColorValue(&(this->red), &(this->last_red), value);
        else if (!increase) decreaseColorValue(&(this->red), &(this->last_red), value);
    }

    void changeBlue(int value) {
        bool increase = checkIncreasement(&(this->blue), value);
        if (increase) increaseColorValue(&(this->blue), &(this->last_blue), value);
        else if (!increase) decreaseColorValue(&(this->blue), &(this->last_blue), value);
    }

    int* getLastColorAddress(int* color_address) {
        if (color_address == &(this->red)) return &(this->last_red);
        else if (color_address == &(this->blue)) return &(this->last_blue);
        else if (color_address == &(this->green)) return &(this->last_green);

    }

    void checkCrossing(int* color_address) {
        int* last_color_address = getLastColorAddress(color_address);
        if (*color_address < 0) {
            *color_address = 0;
            *last_color_address = -1;
        }
        else if (*color_address > 255) {
            *color_address = 255;
            *last_color_address = 256;
        }
    }

    /*
    return True if next change is increase
    *
    */
    bool checkIncreasement(int* color_address, int value) {
        int* last_color_address = getLastColorAddress(color_address);
        if (*color_address > *last_color_address) return true;
        else if (*color_address < *last_color_address) return false;
    }






};
class Sprite {
private:
    LPDIRECT3DTEXTURE9 texture;

    RECT spriteRect;
    D3DXVECTOR3 spritePosition;
    int spriteVelocity;
public:
    Sprite() :texture(NULL) ,spriteRect(), spritePosition(), spriteVelocity(0) {

    }
    Sprite(LPDIRECT3DTEXTURE9 texture, LPD3DXSPRITE spriteBrush) :texture(texture), spriteRect(), spritePosition(), spriteVelocity(0) {

    }

    LPDIRECT3DTEXTURE9 getTexture() {
        return this->texture;
    }

    RECT getSpriteRect() {
        return this->spriteRect;
    }

    D3DXVECTOR3 getSpritePosition() {
        return this->spritePosition;
    }

    int getSpriteVelocity() {
        return this->spriteVelocity;
    }

    void setSpriteVelocity(int velocity) {
        this->spriteVelocity = velocity;
    }


    void setTexture(LPDIRECT3DTEXTURE9 texture) {
        this->texture = texture;
    }

    void setRectLeft(int left) {
        this->spriteRect.left = left;
    }

	void setRectRight(int right) {
		this->spriteRect.right = right;
	}

	void setRectTop(int top) {
		this->spriteRect.top = top;
	}

	void setRectBottom(int bottom) {
		this->spriteRect.bottom = bottom;
	}


	void setPositionX(float x) {
		this->spritePosition.x = x;
	}

	void increasePositionX(float x) {
		this->spritePosition.x += x;
	}

	void decreasePositionX(float x) {
		this->spritePosition.x -= x;
	}

    void setPositionY(float y) {
        this->spritePosition.y = y;
    }

	void increasePositionY(float y) {
		this->spritePosition.y += y;
	}

	void decreasePositionY(float y) {
		this->spritePosition.y -= y;
	}



	void setPositionZ(float z) {
		this->spritePosition.z = z;
	}

	void increasePositionZ(float z) {
		this->spritePosition.z += z;
	}

    void decreasePositionZ(float z) {
        this->spritePosition.z -= z;
    }
};
//class ProgramObject {
//
//};
//Global Var
//--------------------------------------------------------------------

HWND g_hWnd = NULL; //	Window handle
WNDCLASS wndClass;
IDirect3DDevice9* d3dDevice;
LPD3DXSPRITE spriteBrush;
RGBColor rgb = RGBColor();
vector<Sprite> sprites = {};
int totalSprites = static_cast<int>(SpriteID::COUNT);
POINT CursorPosition;

//--------------------------------------------------------------------
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
bool createDirectX();
void createWindow();
void cleanUpDirectX();
void cleanUpWindow();
void render();
bool windowIsRunning();
void whenKeyPressed(KeyCode pressedKey);
void cleanUpSprite();
void createSprite();
enum class KeyCode;
void trackCursorPosition();

//will try to became a class
SpriteID getSpriteEnum(int spriteID);
LPCSTR getSpriteLocation(SpriteID sprite);
int getSpriteID(SpriteID sprite);
//--------------------------------------------------------------------



void whenKeyPressed(KeyCode pressedKey) {
    Sprite* targetSprite;
    switch (pressedKey) {
    case KeyCode::ESCAPE:       PostQuitMessage(0);break;
    case KeyCode::KEY_R:        rgb.changeRed(10);break;
    case KeyCode::KEY_B:        rgb.changeBlue(10);break;
    case KeyCode::KEY_G:        rgb.changeGreen(10);break;
    case KeyCode::UP_ARROW:     targetSprite = &sprites.at(getSpriteID(SpriteID::CHARACTER));targetSprite->decreasePositionY(targetSprite->getSpriteVelocity());break;
    case KeyCode::DOWN_ARROW:   targetSprite = &sprites.at(getSpriteID(SpriteID::CHARACTER));targetSprite->increasePositionY(targetSprite->getSpriteVelocity());break;
    case KeyCode::RIGHT_ARROW:  targetSprite = &sprites.at(getSpriteID(SpriteID::CHARACTER));targetSprite->increasePositionX(targetSprite->getSpriteVelocity());break;
    case KeyCode::LEFT_ARROW:   targetSprite = &sprites.at(getSpriteID(SpriteID::CHARACTER));targetSprite->decreasePositionX(targetSprite->getSpriteVelocity());break;
    }

}

//	Window Procedure, for event handling


//--------------------------------------------------------------------
void createSprite() {
    //	Create spriteBrush. Study the documentation. 
    HRESULT hr = D3DXCreateSprite(d3dDevice, &spriteBrush);
    if (FAILED(hr)) {
        cout << "Error sprite" << endl;
    }

    for (int i = 0; i < totalSprites;i++) {
        Sprite newSprite = Sprite();
        SpriteID sprite = getSpriteEnum(i);
        LPDIRECT3DTEXTURE9 tempTexture = NULL;
        LPCSTR location = getSpriteLocation(sprite);


        //	Create texture. Study the documentation.
        hr = D3DXCreateTextureFromFile(d3dDevice, location, &tempTexture);
        //hr = D3DXCreateTextureFromFileEx(/* Your Direct3D device */, "01.bmp", D3DX_DEFAULT, D3DX_DEFAULT, 
        //									D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, 
        //									D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255), 
        //									NULL, NULL, &texture);

        //	Specify the "	" rectangle.
        newSprite.setTexture(tempTexture);
        if(getSpriteID(SpriteID::CHARACTER)==i)
        {
            newSprite.setRectLeft(44);
            newSprite.setRectRight(107);
            newSprite.setRectTop(157);
            newSprite.setRectBottom(201);

            newSprite.setPositionX(100);
            newSprite.setPositionY(100);
            newSprite.setPositionZ(0);

            newSprite.setSpriteVelocity(5);
        }
        else if (getSpriteID(SpriteID::CURSOR) == i) {
            newSprite.setRectLeft(0);
            newSprite.setRectRight(24);
            newSprite.setRectTop(0);
            newSprite.setRectBottom(24);

            newSprite.setPositionX(100);
            newSprite.setPositionY(100);
            newSprite.setPositionZ(0);
        }
		sprites.push_back(newSprite);
        
    }
    


}

void cleanUpSprite() {
    if (spriteBrush != nullptr) {
        spriteBrush->Release();
        spriteBrush=NULL;
    }
    while (sprites.size() > 0) {
        Sprite sprite = sprites.back();


        if (sprite.getTexture() != nullptr) {
            sprite.getTexture()->Release();
            sprite.setTexture(NULL);
        }
        sprites.pop_back();
    }
}
//	use int main if you want to have a console to print out message
//int main()
//	use WinMain if you don't want the console
                    //ID Nunber,		obs ID number of parent, command line parameter,
int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

    createWindow();
    bool isDirectXCreated = createDirectX();
    createSprite();


    //TODO
    while (windowIsRunning() && isDirectXCreated)
    {
        // Do something… 
        //Game->getInput()
        //Game->Physics()
        //Game->render()
                //	Clear and begin scene

  
        trackCursorPosition();
        //	End and present scene
        render();

    }
    cleanUpSprite();
    cleanUpWindow();
    cleanUpDirectX();
    //	Release and clean up everything





    return 0;
}
//--------------------------------------------------------------------


void render() {
    //	Clear the back buffer.
    d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(rgb.getRedValue(), rgb.getGreenValue(), rgb.getBlueValue()), 1.0f, 0);

    //	Begin the scene
    d3dDevice->BeginScene();
    int totalSprites = static_cast<int>(SpriteID::COUNT);
    spriteBrush->Begin(D3DXSPRITE_ALPHABLEND);
    for(int i =0;i< totalSprites;i++)
    //	Specify alpha blend will ensure that the spriteBrush will render the background with alpha.
    {
        Sprite currentSprite = sprites.at(i);
        RECT spriteRect = currentSprite.getSpriteRect();
        LPDIRECT3DTEXTURE9 texture = currentSprite.getTexture();
        D3DXVECTOR3 spritePosition =currentSprite.getSpritePosition();



        //	Sprite rendering. Study the documentation.
        spriteBrush->Draw(texture, &spriteRect, NULL, &spritePosition, D3DCOLOR_XRGB(255, 255, 255));
        //spriteBrush->Draw(texture, &spriteRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
        //spriteBrush->Draw(texture, &spriteRect, NULL, &D3DXVECTOR3(32, 32, 0), D3DCOLOR_XRGB(255, 255, 255));

        //	End spriteBrush drawing

    }
    spriteBrush->End();

    //	End the scene
    d3dDevice->EndScene();

    //	Present the back buffer to screen
    d3dDevice->Present(NULL, NULL, NULL, NULL);

}



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
    d3dPP.BackBufferWidth = 1280;
    d3dPP.BackBufferHeight = 960;
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

    Sprite* cursor;
    cursor = &sprites.at(getSpriteID(SpriteID::CURSOR));
    GetCursorPos(&CursorPosition);
    cursor->setPositionX(CursorPosition.x);
    cursor->setPositionY(CursorPosition.y);
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
    g_hWnd = CreateWindowEx(0, wndClass.lpszClassName, "???", WS_OVERLAPPEDWINDOW, 0, 100, 900, 600, NULL, NULL, GetModuleHandle(NULL), NULL);
    ShowWindow(g_hWnd, 1);

    //	Some interesting function to try out.
    	ShowCursor(false);
        //	Free up the memory.
    UnregisterClass(wndClass.lpszClassName, GetModuleHandle(NULL));




    return;

}

void cleanUpDirectX() {
    d3dDevice->Release();//	Release the device when exiting.
    d3dDevice = NULL;//	Reset pointer to NULL, a good practice.
}

void cleanUpWindow() {
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


        }

        whenKeyPressed(pressedKey);

        break;

    default:

        return DefWindowProc(hWnd, message, wParam, lParam);
    }



    return 0;
}

LPCSTR getSpriteLocation(SpriteID sprite) {
    switch (sprite) {
    case SpriteID::CHARACTER: return "image/bg1.png";
    case SpriteID::CURSOR: return "image/pointer.png";
    }
}

SpriteID getSpriteEnum(int spriteID) {
    switch (spriteID) {
    case 0: return SpriteID::CHARACTER;
    case 1: return SpriteID::CURSOR;
    }
}

int getSpriteID(SpriteID sprite) {
    switch (sprite) {
    case SpriteID::CHARACTER:return 0;
    case SpriteID::CURSOR: return 1;
    }
}

