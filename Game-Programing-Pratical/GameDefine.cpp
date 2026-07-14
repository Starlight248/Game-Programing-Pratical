
#include "enum.h"

LPCSTR getSpriteLocation(TextureType sprite) {
    switch (sprite) {
    case TextureType::CHARACTER: return "image/bg1.png";
    case TextureType::CURSOR: return "image/pointer.png";
    }
}

TextureType getSpriteEnum(int spriteID) {
    switch (spriteID) {
    case 0: return TextureType::CHARACTER;
    case 1: return TextureType::CURSOR;
    }
}

int getSpriteID(TextureType sprite) {
    switch (sprite) {
    case TextureType::CHARACTER:return 0;
    case TextureType::CURSOR: return 1;
    }
}