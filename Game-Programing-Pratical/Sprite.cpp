#include "Sprite.h"
#include "Texture.h"
#include <string>

Sprite::Sprite() :textureAddress(), spriteRect(), spritePosition(), spriteVelocity(0) {
}

Sprite::Sprite(Texture* texture) 
:textureAddress(texture), spriteRect(), spritePosition(), spriteVelocity(0)
{
}

//Sprite::Sprite(LPDIRECT3DTEXTURE9* textureAddress, std::string path)
//	:textureAddress(*textureAddress), spriteRect(), spritePosition(), spriteVelocity(0)
//{
//}
