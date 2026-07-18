#include "programDefine.h"

#include <vector>
#include <Windows.h>

#include "enum.h"
#include "Sprite.h"
#include "RGBColor.h"


void whenKeyPressed(KeyCode pressedKey) {
    Sprite* targetSprite;
    switch (pressedKey) {
    //case KeyCode::ESCAPE:       PostQuitMessage(0);break;
    //case KeyCode::KEY_R:        rgb.changeRed(10);break;
    //case KeyCode::KEY_B:        rgb.changeBlue(10);break;
    //case KeyCode::KEY_G:        rgb.changeGreen(10);break;
    //case KeyCode::UP_ARROW:     targetSprite = &sprites.at(getSpriteID(TextureType::BG1));targetSprite->decreasePositionY(targetSprite->getSpriteVelocity());break;
    //case KeyCode::DOWN_ARROW:   targetSprite = &sprites.at(getSpriteID(TextureType::BG1));targetSprite->increasePositionY(targetSprite->getSpriteVelocity());break;
    //case KeyCode::RIGHT_ARROW:  targetSprite = &sprites.at(getSpriteID(TextureType::BG1));targetSprite->increasePositionX(targetSprite->getSpriteVelocity());break;
    //case KeyCode::LEFT_ARROW:   targetSprite = &sprites.at(getSpriteID(TextureType::BG1));targetSprite->decreasePositionX(targetSprite->getSpriteVelocity());break;
    case KeyCode::KEY_0:        changeRect(loopSpriteVector(SpriteType::NUM), 0, 4, 4); break;
    case KeyCode::KEY_1:        changeRect(loopSpriteVector(SpriteType::NUM), 2, 4, 4); break;
    case KeyCode::KEY_2:        changeRect(loopSpriteVector(SpriteType::NUM), 3, 4, 4); break;
    case KeyCode::KEY_3:        changeRect(loopSpriteVector(SpriteType::NUM), 4, 4, 4); break;
    case KeyCode::KEY_4:        changeRect(loopSpriteVector(SpriteType::NUM), 5, 4, 4); break;
    case KeyCode::KEY_5:        changeRect(loopSpriteVector(SpriteType::NUM), 6, 4, 4); break;
    case KeyCode::KEY_6:        changeRect(loopSpriteVector(SpriteType::NUM), 7, 4, 4); break;
    case KeyCode::KEY_7:        changeRect(loopSpriteVector(SpriteType::NUM), 8, 4, 4); break;
    case KeyCode::KEY_8:        changeRect(loopSpriteVector(SpriteType::NUM), 9, 4, 4); break;
    case KeyCode::KEY_9:        changeRect(loopSpriteVector(SpriteType::NUM), 10, 4, 4); break;

    }

}
