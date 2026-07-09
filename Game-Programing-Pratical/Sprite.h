#pragma once

#include<d3d9.h>
#include <d3dx9.h>
class Sprite
{

    private:
        LPDIRECT3DTEXTURE9 texture;

        RECT spriteRect;
        D3DXVECTOR3 spritePosition;
        int spriteVelocity;
    public:
        Sprite();
        Sprite(LPDIRECT3DTEXTURE9 texture, LPD3DXSPRITE spriteBrush);

        LPDIRECT3DTEXTURE9 getTexture() {return this->texture;}

        RECT getSpriteRect() {return this->spriteRect;}

        D3DXVECTOR3 getSpritePosition() {return this->spritePosition;}

        int getSpriteVelocity() {return this->spriteVelocity;}

        void setSpriteVelocity(int velocity) {this->spriteVelocity = velocity;}


        void setTexture(LPDIRECT3DTEXTURE9 texture) {this->texture = texture;}

        void setRectLeft(int left) {this->spriteRect.left = left;}

        void setRectRight(int right) {this->spriteRect.right = right;}

        void setRectTop(int top) {this->spriteRect.top = top;}

        void setRectBottom(int bottom) {this->spriteRect.bottom = bottom;}


        void setPositionX(float x) {this->spritePosition.x = x;}

        void increasePositionX(float x) {this->spritePosition.x += x;}

        void decreasePositionX(float x) {this->spritePosition.x -= x;}

        void setPositionY(float y) {this->spritePosition.y = y;}

        void increasePositionY(float y) {this->spritePosition.y += y;}

        void decreasePositionY(float y) {this->spritePosition.y -= y;}

        void setPositionZ(float z) {this->spritePosition.z = z;}

        void increasePositionZ(float z) {this->spritePosition.z += z;}

        void decreasePositionZ(float z) {this->spritePosition.z -= z;}
 };


