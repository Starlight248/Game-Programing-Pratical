#pragma once

#include <Windows.h>
#include "enum.h"
class Texture;
class Sprite{

private:
	SpriteType spriteType;
    Texture* textureAddress;
    RECT spriteRect;
    D3DXVECTOR3 spritePosition;
    int spriteVelocity;
    bool isActive;//default is false, need make into true after create Sprite
public:
    Sprite();
    Sprite(Texture* texture);
    //Sprite(LPDIRECT3DTEXTURE9* textureAddress, std::string path);

	Texture* getTextureAddress() { return this->textureAddress; }

	void setSpriteType(SpriteType spriteType) { this->spriteType = spriteType; }

	SpriteType getSpriteType() { return this->spriteType; }

    void setTextureAddress(Texture* textureAddress) { this->textureAddress = textureAddress; }

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

    int getRectLeft(){return this->spriteRect.left; }

	int getRectRight() { return this->spriteRect.right; }

	int getRectTop() { return this->spriteRect.top; }

	int getRectBottom() { return this->spriteRect.bottom; }
};
