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
}

void cleanUpTextures() {
	for (auto& [textureType, texture] : textureType) {
		texture->releaseTexture();
	}   

}

void cleanUpDinput() {
    //	Release keyboard device.
    dInputKeyboardDevice->Unacquire();
    dInputKeyboardDevice->Release();
    dInputKeyboardDevice = NULL;
    dInputMouseDevice->Unacquire();
    dInputMouseDevice->Release();
    dInputMouseDevice = NULL;
    //	Release DirectInput.
    dInput->Release();
    dInput = NULL;

    

}