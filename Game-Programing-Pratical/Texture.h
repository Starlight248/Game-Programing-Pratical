#pragma once
#include <d3dx9.h>
#include <string>
class Texture {
private:
    const LPDIRECT3DTEXTURE9 texture;
    std::string path;
    const int horizontalPixel;
    const int verticalPixel;
    
public:
    Texture(LPDIRECT3DTEXTURE9 texture, std::string path, int horizontalPixel , int verticalPixel);
    Texture(LPDIRECT3DTEXTURE9 texture, int horizontalPixel, int verticalPixel);

    LPDIRECT3DBASETEXTURE9 getTexture() { return this->texture; }

    std::string getPath() { return this->path; }
    
    void setPath(std::string path) {/*only able to set when not path existing*/ if (this->path == "") this->path = path; }
    
    int getHorizontalPixel() { return this->horizontalPixel; }

    int getVerticalPixel() { return this->verticalPixel; }
};
