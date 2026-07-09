
#include "Sprite.h"

Sprite::Sprite() :texture(NULL), spriteRect(), spritePosition(), spriteVelocity(0) {

}
Sprite::Sprite(LPDIRECT3DTEXTURE9 texture, LPD3DXSPRITE spriteBrush) :texture(texture), spriteRect(), spritePosition(), spriteVelocity(0) {

}