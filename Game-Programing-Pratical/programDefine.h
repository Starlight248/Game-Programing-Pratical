#pragma once
#include <vector>
#include "Texture.h"
#include <Windows.h>
#include "enum.h"
#include "RGBColor.h"
#include "Sprite.h"
#include "Destroy.h"
#include <string>

extern bool debug;
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
extern LPD3DXLINE line;
extern  std::vector<D3DXVECTOR2>  lineVertices;



void whenKeyPressed(KeyCode pressedKey);


enum class KeyCode;
void trackCursorPosition(LPARAM lParam);
void selectNumberRect(int selected);
Sprite* loopSpriteVector(SpriteType spriteType);
void changeRect(Sprite* sprite, int selectedAreaNumber);
void drawClock();
//will try to became a class
//TextureType getSpriteEnum(int spriteID);
//LPCSTR getSpriteLocation(TextureType sprite);
//int getSpriteID(TextureType sprite);