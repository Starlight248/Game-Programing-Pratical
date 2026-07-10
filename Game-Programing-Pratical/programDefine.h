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
void trackCursorPosition(LPARAM lParam);
void selectNumberRect(int selected);

//will try to became a class
SpriteID getSpriteEnum(int spriteID);
LPCSTR getSpriteLocation(SpriteID sprite);
int getSpriteID(SpriteID sprite);