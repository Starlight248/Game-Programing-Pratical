#include "Texture.h"
#include <Windows.h>
using namespace std;

Texture::Texture(LPDIRECT3DTEXTURE9 texture, std::string path, int horizontalPixel, int verticalPixel):texture(texture),path(path),horizontalPixel(horizontalPixel),verticalPixel(verticalPixel)
{
}
Texture::Texture(LPDIRECT3DTEXTURE9 texture, int horizontalPixel, int verticalPixel):texture(texture), path(""), horizontalPixel(horizontalPixel), verticalPixel(verticalPixel)
{
}

//void Texture::setPath(std::string path) {
//	if (this->path == "") this->path = path;
//}

//Texture::Texture(LPDIRECT3DTEXTURE9 texture, std::string path):texture(texture),path(path)
//{
//}
//Texture::Texture(LPDIRECT3DTEXTURE9 texture):texture(texture)
//{
//}

