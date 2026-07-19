#pragma once
#include <d3dx9.h>
#include <string>
#include <Windows.h>
#include "Sprite.h"

class Sprite;
class Texture {
protected:
    LPDIRECT3DTEXTURE9 texture;
    std::string path;
    const int horizontalPixel;//x
    const int verticalPixel;//y


public:
    virtual ~Texture() = default;
    Texture() : texture(nullptr), path(""), horizontalPixel(0), verticalPixel(0) {}
    Texture(LPDIRECT3DTEXTURE9 texture, std::string path, int horizontalPixel, int verticalPixel) :texture(texture), path(path), horizontalPixel(horizontalPixel), verticalPixel(verticalPixel) {};
    Texture(LPDIRECT3DTEXTURE9 texture, int horizontalPixel, int verticalPixel) :texture(texture), path(""), horizontalPixel(horizontalPixel), verticalPixel(verticalPixel) {};

    virtual void changeRect(Sprite* sprite, int selectedAreaNumber) { return; };


    LPDIRECT3DTEXTURE9 getTexture() { return this->texture; }

    std::string getPath() { return this->path; }

    void setPath(std::string path) {/*
        only able to set when not path existing*/if (this->path == "") this->path = path;
    }

    int getHorizontalPixel() { return this->horizontalPixel; }//x

    int getVerticalPixel() { return this->verticalPixel; }//y

    LPCSTR getLocation() const {
        return path.c_str();
    }

    void releaseTexture() {
        if (this->texture != nullptr) {
            this->texture->Release();
            this->texture = nullptr;
        }
    }
};
