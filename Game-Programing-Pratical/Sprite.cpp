#include "Sprite.h"
#include "Texture.h"
#include <string>

Sprite::Sprite() :Texture(), spriteRect(), spritePosition(), spriteVelocity(0) {

}

Sprite::Sprite(LPDIRECT3DTEXTURE9 texture) 
:Texture(texture), spriteRect(), spritePosition(), spriteVelocity(0)
{
}

Sprite::Sprite(LPDIRECT3DTEXTURE9 texture, std::string path)
:Texture(texture,path), spriteRect(), spritePosition(), spriteVelocity(0)
{
}
