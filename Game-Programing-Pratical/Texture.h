#pragma once
#include <d3dx9.h>
#include <string>
class Texture {
private:
    LPDIRECT3DTEXTURE9 texture;
    std::string path;
    const int horizontalPixel;//x
    const int verticalPixel;//y
    const int textureRow;
    const int textureColumn;
    
public:
	Texture() : texture(nullptr), path(""), horizontalPixel(0), verticalPixel(0) , textureRow(0), textureColumn(0){}
    Texture(LPDIRECT3DTEXTURE9 texture, std::string path, int horizontalPixel, int verticalPixel, int textureRow, int textureColum) : texture(texture), path(path), horizontalPixel(horizontalPixel), verticalPixel(verticalPixel), textureRow(textureRow), textureColumn(textureColum) {};
    Texture(LPDIRECT3DTEXTURE9 texture, int horizontalPixel, int verticalPixel, int textureRow, int textureColum) :texture(texture), horizontalPixel(horizontalPixel), verticalPixel(verticalPixel), textureRow(textureRow), textureColumn(textureColum) {};
    Texture(LPDIRECT3DTEXTURE9 texture, std::string path, int horizontalPixel, int verticalPixel) :texture(texture), path(path), horizontalPixel(horizontalPixel), verticalPixel(verticalPixel), textureRow(0), textureColumn(0) {};
    Texture(LPDIRECT3DTEXTURE9 texture, int horizontalPixel, int verticalPixel) :texture(texture), path(""), horizontalPixel(horizontalPixel), verticalPixel(verticalPixel), textureRow(0), textureColumn(0) {};


    int getTextureRow() { return this->textureRow; }

    int getTextureColumn() { return this->textureColumn; }

    LPDIRECT3DTEXTURE9 getTexture() { return this->texture; }

    std::string getPath() { return this->path; }
    
    void setPath(std::string path) {/*
        only able to set when not path existing*/if (this->path == "") this->path = path; }
    
    int getHorizontalPixel() { return this->horizontalPixel; }//x

    int getVerticalPixel() { return this->verticalPixel; }//y

    LPCSTR getLocation() const {
        return path.c_str();
    }

    void releaseTexture() {
        if (this->texture != NULL) {
            this->texture->Release();
            this->texture = NULL;
        }
    }

    int getTotalSheetNumber() { return this->textureRow * this->textureColumn; };
};
