#pragma once
#include <vector>
#include "Texture.h"
#include <Windows.h>
#include "enum.h"
#include "RGBColor.h"
#include "Sprite.h"
#include <map>
#include <string>
#include <dinput.h>

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
extern std::map <TextureType, Texture*>textureType;
extern LPD3DXFONT fontBrush;
extern RECT textRect;
extern std::string font;
extern LPDIRECTINPUT8 dInput;
extern LPDIRECTINPUTDEVICE8  dInputKeyboardDevice;
extern LPDIRECTINPUTDEVICE8  dInputMouseDevice;


bool createDirectX();
void createWindow();
void createSprite();
void createTexture();
void createFont();
void createDinput();



