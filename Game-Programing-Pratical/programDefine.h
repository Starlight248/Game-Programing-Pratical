#pragma once
#include <vector>
#include "Texture.h"
#include <Windows.h>
#include "enum.h"
#include "RGBColor.h"
#include "Sprite.h"
#include "Destroy.h"
#include <string>
#include <queue>

extern const bool debug;
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
extern std::string font;
extern LPD3DXLINE lineBrush;
extern D3DXVECTOR2  lineVertices[];
extern std::queue<KeyCodeWindowInput> keyPressedWin;
extern RECT textRect;
extern std::string font;
extern LPD3DXLINE lineBrush;
//	Define the line vertices.

extern BYTE diMouse[256];


void whenKeyPressed(std::queue<KeyCodeWindowInput> &keyPressedWin);


enum class KeyCodeWindowInput;
void trackCursorPosition(LPARAM lParam);
Sprite* getSpriteFromVector(SpriteType spriteType);
void drawClock(LPD3DXLINE lineBrush, int totalLine);
//will try to became a class
//TextureType getSpriteEnum(int spriteID);
//LPCSTR getSpriteLocation(TextureType sprite);
//int getSpriteID(TextureType sprite);