#include "Sprite.h"
#include "Texture.h"
#include <string>

Sprite::Sprite() :texture(), spriteRect(), spritePosition(), spriteVelocity(0) {
}

Sprite::Sprite(Texture* texture) 
:texture(texture), spriteRect(), spritePosition(), spriteVelocity(0)
{
}

//Sprite::Sprite(LPDIRECT3DTEXTURE9* texture, std::string path)
//	:texture(*texture), spriteRect(), spritePosition(), spriteVelocity(0)
//{
//}
