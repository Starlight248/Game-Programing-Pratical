#pragma once
#include <d3dx9.h>
#include <string>
class Texture {
private:
    LPDIRECT3DTEXTURE9 texture;
    std::string path;
    
public:
    Texture() {}
    Texture(LPDIRECT3DTEXTURE9 texture, std::string path);
    Texture(LPDIRECT3DTEXTURE9 texture);

    LPDIRECT3DBASETEXTURE9 getTexture() { return this->texture; }

    std::string getPath() { return this->path; }

    void setTexture(LPDIRECT3DTEXTURE9 texture) { this->texture = texture; }

    
};
