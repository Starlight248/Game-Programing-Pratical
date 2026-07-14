#pragma once

#include<d3d9.h>
#include <d3dx9.h>
#include "Texture.h"
#include <string>
class Sprite{

private:
    Texture* texture;
    RECT spriteRect;
    D3DXVECTOR3 spritePosition;
    int spriteVelocity;
public:
    Sprite();
    Sprite(Texture* texture);
    //Sprite(LPDIRECT3DTEXTURE9* texture, std::string path);

    RECT getSpriteRect() { return this->spriteRect; }

    D3DXVECTOR3 getSpritePosition() { return this->spritePosition; }

    int getSpriteVelocity() { return this->spriteVelocity; }

    void setSpriteVelocity(int velocity) { this->spriteVelocity = velocity; }

    void setRectLeft(int left) { this->spriteRect.left = left; }

    void setRectRight(int right) { this->spriteRect.right = right; }

    void setRectTop(int top) { this->spriteRect.top = top; }

    void setRectBottom(int bottom) { this->spriteRect.bottom = bottom; }

    void setPositionX(float x) { this->spritePosition.x = x; }

    void increasePositionX(float x) { this->spritePosition.x += x; }

    void decreasePositionX(float x) { this->spritePosition.x -= x; }

    void setPositionY(float y) { this->spritePosition.y = y; }

    void increasePositionY(float y) { this->spritePosition.y += y; }

    void decreasePositionY(float y) { this->spritePosition.y -= y; }

    void setPositionZ(float z) { this->spritePosition.z = z; }

    void increasePositionZ(float z) { this->spritePosition.z += z; }

    void decreasePositionZ(float z) { this->spritePosition.z -= z; }
};
