
#include "enum.h"

LPCSTR getSpriteLocation(SpriteID sprite) {
    switch (sprite) {
    case SpriteID::CHARACTER: return "image/bg1.png";
    case SpriteID::CURSOR: return "image/pointer.png";
    }
}

SpriteID getSpriteEnum(int spriteID) {
    switch (spriteID) {
    case 0: return SpriteID::CHARACTER;
    case 1: return SpriteID::CURSOR;
    }
}

int getSpriteID(SpriteID sprite) {
    switch (sprite) {
    case SpriteID::CHARACTER:return 0;
    case SpriteID::CURSOR: return 1;
    }
}