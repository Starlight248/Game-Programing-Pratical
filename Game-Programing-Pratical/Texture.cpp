#include "Texture.h"
#include <Windows.h>

Texture::Texture(){}
Texture::Texture(LPDIRECT3DTEXTURE9 texture, std::string path):texture(texture),path(path)
{
}

Texture::Texture(LPDIRECT3DTEXTURE9 texture):texture(texture)
{
}
