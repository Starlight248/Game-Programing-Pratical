#include "Initialization.h"
#include "windowEvent.h"
#include <iostream>
#include "SheetTexture.h"
#include "Texture.h"
#include "programDefine.h"

static void storeTexture(TextureType enumTextureType, std::string location, int width, int height);
static void storeSheetTexture(TextureType enumTextureType, std::string location, int width, int height, int rowNumber, int columnNumber);

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
    d3dPP.BackBufferWidth = 900;
    d3dPP.BackBufferHeight = 600;
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

struct SpriteConfig
{
    int rectLeft = 0, rectTop = 0, rectRight = 0, rectBottom = 0;
    int posX = 0, posY = 0, posZ = 0;
    int speed = 0;
};

void loadSprite(
    SpriteType spriteType,TextureType enumTextureType,
    int rectLeft = 0, int rectRight = 0, int rectTop = 0, int rectBottom = 0,
    int positionX = 0, int positionY = 0, int positionZ = 0,
    int spriteVelocity = 0,
    int RGB_R = 255, int RGB_G = 255, int RGB_B = 255
) {
    Sprite newSprite = Sprite();

	newSprite.setSpriteType(spriteType);
    
    newSprite.setTextureAddress((textureType[enumTextureType]));

    newSprite.setRectLeft(rectLeft);
    newSprite.setRectRight(rectRight);
    newSprite.setRectTop(rectTop);
    newSprite.setRectBottom(rectBottom);

	newSprite.setPositionX(positionX);
	newSprite.setPositionY(positionY);
	newSprite.setPositionZ(positionZ);

	newSprite.setPositionX(0);
	newSprite.setPositionY(0);
	newSprite.setPositionZ(0);
	

	newSprite.setSpriteVelocity(spriteVelocity);

    sprites.push_back(newSprite);
}

void createSprite() {
    HRESULT hr = D3DXCreateSprite(d3dDevice, &spriteBrush);
    if (FAILED(hr)) {
        std::cout << "Error sprite" << std::endl;
    }
	SpriteConfig config;
    loadSprite(SpriteType::CHARACTER,TextureType::CURSOR, 44,107,157,201,100,100,0,5);
	loadSprite(SpriteType::CURSOR, TextureType::CURSOR, 0, 24, 0, 24, 100, 100, 0, 0);
	loadSprite(SpriteType::NUM, TextureType::NUMBER, 0, 32, 0, 32, 300, 400, 0, 0);

    //for (int i = 0; i < totalSprites;i++) {
        //Sprite newSprite = Sprite();
        //TextureType sprite = getSpriteEnum(i);
        //LPDIRECT3DTEXTURE9 tempTexture = NULL;
        //LPCSTR location = getSpriteLocation(sprite);
        ////	Create Texture. Study the documentation.
        //hr = D3DXCreateTextureFromFile(d3dDevice, location, &tempTexture);
        ////hr = D3DXCreateTextureFromFileEx(/* Your Direct3D device */, "01.bmp", D3DX_DEFAULT, D3DX_DEFAULT, 
        ////									D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, 
        ////									D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255), 
        ////									NULL, NULL, &Texture);
        ////	Specify the "	" rectangle.
        //newSprite.setTexture(tempTexture);
        //if (getSpriteID(TextureType::BG1) == i)
        //{
        //    newSprite.setRectLeft(44);
        //    newSprite.setRectRight(107);
        //    newSprite.setRectTop(157);
        //    newSprite.setRectBottom(201);
        //    newSprite.setPositionX(100);
        //    newSprite.setPositionY(100);
        //    newSprite.setPositionZ(0);
        //    newSprite.setSpriteVelocity(5);
        //}
        //else if (getSpriteID(TextureType::CURSOR) == i) {
        //    newSprite.setRectLeft(0);
        //    newSprite.setRectRight(24);
        //    newSprite.setRectTop(0);
        //    newSprite.setRectBottom(24);
        //    newSprite.setPositionX(100);
        //    newSprite.setPositionY(100);
        //    newSprite.setPositionZ(0);
        //}
        //sprites.push_back(newSprite);
    ////}
    //hr = D3DXCreateTextureFromFile(d3dDevice, "image/numbers.bmp", &numberTexture);
    //numberPosition.x = 300;
    //numberPosition.y = 400;
    //numberRect.left = numberRect.right = numberRect.top = numberRect.bottom = 0;

}



void createTexture()
{
    storeTexture(TextureType::BG1, "image/bg1.png", 512, 512);
    storeTexture(TextureType::CURSOR, "image/pointer.png", 32, 32);
	storeSheetTexture(TextureType::NUMBER, "image/numbers.bmp", 128, 128,4,4);
    
}

static void storeTexture(TextureType enumTextureType, std::string location, int width, int height) {
    LPDIRECT3DTEXTURE9 tempTexture = nullptr;
    HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, location.c_str(), &tempTexture);
    //hr = D3DXCreateTextureFromFileEx(/* Your Direct3D device */, "01.bmp", D3DX_DEFAULT, D3DX_DEFAULT, 
    //									D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, 
    //									D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255), 
    //									NULL, NULL, &texture);
    if (SUCCEEDED(hr)) {
        Texture* tempOfTexture =new Texture(tempTexture, location, width, height);
        textureType.insert({ enumTextureType ,tempOfTexture });
    }
    else {
        std::cout << "Failed to load texture: " << location << std::endl;
    }
}


static void storeSheetTexture(TextureType enumTextureType, std::string location, int width, int height, int rowNumber, int columnNumber) {
    LPDIRECT3DTEXTURE9 tempTexture = nullptr;
    HRESULT hr = D3DXCreateTextureFromFile(d3dDevice, location.c_str(), &tempTexture);
    //hr = D3DXCreateTextureFromFileEx(/* Your Direct3D device */, "01.bmp", D3DX_DEFAULT, D3DX_DEFAULT, 
    //									D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, 
    //									D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255), 
    //									NULL, NULL, &texture);
    if (SUCCEEDED(hr)) {
        SheetTexture* tempOfTexture = new SheetTexture(tempTexture, location,width,height,rowNumber,columnNumber);
        textureType.insert({ enumTextureType ,tempOfTexture });
    }
    else {
        std::cout << "Failed to load texture: " << location << std::endl;
    }
}

void createFont() {
    {
        //	Create font. Study the documentation.
        HRESULT hr = D3DXCreateFont(d3dDevice, 25, 0, 0, 1, false,
            DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE, "Arial", &fontBrush);
        //	Create lineBrush
        hr = D3DXCreateLine(d3dDevice, &lineBrush);
        
    }

}