#include "Destroy.h"
#include<d3d9.h>
#include <Windows.h>
#include "Initialization.h"

void cleanUpDirectX() {
    d3dDevice->Release();//	Release the device when exiting.
    d3dDevice = NULL;//	Reset pointer to NULL, a good practice.
}

void cleanUpWindow() {
    //	Free up the memory.
    UnregisterClass(wndClass.lpszClassName, GetModuleHandle(NULL));
    return;
};


void cleanUpSprite() {
    if (spriteBrush != nullptr) {
        spriteBrush->Release();
        spriteBrush = NULL;
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