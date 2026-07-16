#include "programDefine.h"

Sprite loopSpriteVector(SpriteType spriteType) {
    Sprite* targetSprite = nullptr;
    //  LPPOINT lpPoint = NULL;

    for (int i = 0; i < sprites.size(); i++) {
        if (sprites[i].getSpriteType() == spriteType) {
            targetSprite = &sprites[i];
            break;
        }
    }

    if (targetSprite == nullptr) return Sprite();
    return *targetSprite;
}