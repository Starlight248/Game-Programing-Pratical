//	Ask the compiler to include minimal header files for our program.
#define WIN32_LEAN_AND_MEAN
#include<d3d9.h>
#include <Windows.h>
#include<iostream>
#include <d3dx9.h>
#include <vector>
#include <map>
#include <queue>
#include <dinput.h>

#include "enum.h";
#include "RGBColor.h";
#include "Sprite.h"
#include "Texture.h"
#include "programDefine.h"
#include "windowEvent.h"
#include "Destroy.h"
#include "Initialization.h"
#include "Graphics.h"
#include <string>
#include "debug.h"

#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")

using namespace std;

const bool debug = true;

LPD3DXSPRITE spriteBrush;
LPD3DXFONT fontBrush = NULL;

HWND g_hWnd = NULL; //	Window handle
WNDCLASS wndClass;
IDirect3DDevice9* d3dDevice;

RGBColor rgb = RGBColor();
map<TextureType, Texture*> textureType;
vector<Sprite> sprites = {};
queue<KeyCodeWindowInput> keyPressedWin = {};
//vector<Texture> textures = {};
int totalSprites = static_cast<int>(TextureType::COUNT);
POINT CursorPosition;
LPDIRECT3DTEXTURE9 numberTexture;
RECT numberRect;
D3DXVECTOR3 numberPosition;
bool showNumber = false;


    RECT textRect;
    std::string font = "";
    LPD3DXLINE lineBrush = NULL;
    //	Define the line vertices.
    D3DXVECTOR2 lineVertices[2];
    LPDIRECTINPUT8 dInput;
    LPDIRECTINPUTDEVICE8  dInputKeyboardDevice;
    LPDIRECTINPUTDEVICE8  dInputMouseDevice;
    //	Key input buffer
    BYTE  diKeys[256];
    BYTE  diMouse[256];


//	use int main if you want to have a console to print out message
//int main()
//	use WINAPI WinMain if you don't want the console
                    //ID Nunber,		obs ID number of parent, command line parameter,
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

    createWindow();
    bool isDirectXCreated = createDirectX();
    createTexture();
    createSprite();
    createFont();
    createDinput();

    {
        textRect.left = 0;
        textRect.top = 0;
        textRect.right = 500;
        textRect.bottom = 500;
    }
    



    //TODO
    while (windowIsRunning() && isDirectXCreated)
    {
        // Do something… 
        //Game->getInput()
        //Game->Physics()
        //Game->render()
        //	Clear and begin scene
                //	Get immediate Keyboard Data.
        dInputKeyboardDevice->GetDeviceState(256, diKeys);
        dInputMouseDevice->GetDeviceState(256, diMouse);
        if (diKeys[DIK_UP] & 0x80)
        {
            if (diKeys[DIK_UP] & 0x80);
            callMessageBoxA("main.cpp", "clicked UP");
            
        }

  
        
        //	End and present scene
        render();

    }
    cleanUpSprite();
    cleanUpTextures();
    cleanUpWindow();
    cleanUpDirectX();
    cleanUpDinput();
    //
    {
        fontBrush->Release();
        fontBrush = NULL;
    }
    //	Release and clean up everything





    return 0;
}
//--------------------------------------------------------------------





