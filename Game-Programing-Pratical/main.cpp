//	Ask the compiler to include minimal header files for our program.
#define WIN32_LEAN_AND_MEAN
#include<d3d9.h>
#include <Windows.h>
#include<iostream>
#include <d3dx9.h>
#include <vector>
#include <map>

#include "enum.h";
#include "RGBColor.h";
#include "Sprite.h"
#include "Texture.h"
#include "programDefine.h"
#include "windowEvent.h"
#include "Destroy.h"
#include "Initialization.h"
#include "Graphics.h"

using namespace std;

HWND g_hWnd = NULL; //	Window handle
WNDCLASS wndClass;
IDirect3DDevice9* d3dDevice;
LPD3DXSPRITE spriteBrush;
RGBColor rgb = RGBColor();
map<TextureType, Texture> textureType;
vector<Sprite> sprites = {};
vector<Texture> textures = {};
int totalSprites = static_cast<int>(TextureType::COUNT);
POINT CursorPosition;
LPDIRECT3DTEXTURE9 numberTexture;
RECT numberRect;
D3DXVECTOR3 numberPosition;
bool showNumber = false;

//	use int main if you want to have a console to print out message
//int main()
//	use WinMain if you don't want the console
                    //ID Nunber,		obs ID number of parent, command line parameter,
int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

    createWindow();
    bool isDirectXCreated = createDirectX();
    createTexture();
    createSprite();


    //TODO
    while (windowIsRunning() && isDirectXCreated)
    {
        // Do something… 
        //Game->getInput()
        //Game->Physics()
        //Game->render()
        //	Clear and begin scene

  
        
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





