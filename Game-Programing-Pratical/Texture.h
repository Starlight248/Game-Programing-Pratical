#pragma once
#include <d3dx9.h>
class Texture {

    LPDIRECT3DTEXTURE9 texture;

    Texture();
    Texture(LPDIRECT3DTEXTURE9 texture);
};
