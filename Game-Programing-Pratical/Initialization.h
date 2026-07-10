#pragma once
#include <vector>
#include "Texture.h"
#include <Windows.h>
#include "enum.h"
#include "RGBColor.h"
#include "Sprite.h"

extern HWND g_hWnd;
extern WNDCLASS wndClass;
extern IDirect3DDevice9* d3dDevice;
extern LPD3DXSPRITE spriteBrush;
extern RGBColor rgb;
extern std::vector<Sprite> sprites;
extern std::vector<Texture> textures;
extern int totalSprites;
extern POINT CursorPosition;
extern LPDIRECT3DTEXTURE9 numberTexture;
extern RECT numberRect;
extern D3DXVECTOR3 numberPosition;
extern bool showNumber;

class Initialization
{
	bool static createDirectX();
	void static createWindow();
	void static createSprite();
};

