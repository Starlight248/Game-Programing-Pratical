#include "programDefine.h"

#include <vector>
#include <Windows.h>

#include "enum.h"
#include "Sprite.h"
#include "RGBColor.h"
#include <queue>


void whenKeyPressed(std::queue<KeyCodeWindowInput> &keyPressedWin) {
    while(!keyPressedWin.empty()) {
        switch (keyPressedWin.front()) {
            //case KeyCodeWindowInput::ESCAPE:       PostQuitMessage(0);break;
            //case KeyCodeWindowInput::KEY_R:        rgb.changeRed(10);break;
            //case KeyCodeWindowInput::KEY_B:        rgb.changeBlue(10);break;
            //case KeyCodeWindowInput::KEY_G:        rgb.changeGreen(10);break;
            //case KeyCodeWindowInput::UP_ARROW:     targetSprite = &sprites.at(getSpriteID(TextureType::BG1));targetSprite->decreasePositionY(targetSprite->getSpriteVelocity());break;
            //case KeyCodeWindowInput::DOWN_ARROW:   targetSprite = &sprites.at(getSpriteID(TextureType::BG1));targetSprite->increasePositionY(targetSprite->getSpriteVelocity());break;
            //case KeyCodeWindowInput::RIGHT_ARROW:  targetSprite = &sprites.at(getSpriteID(TextureType::BG1));targetSprite->increasePositionX(targetSprite->getSpriteVelocity());break;
            //case KeyCodeWindowInput::LEFT_ARROW:   targetSprite = &sprites.at(getSpriteID(TextureType::BG1));targetSprite->decreasePositionX(targetSprite->getSpriteVelocity());break;
        case KeyCodeWindowInput::KEY_0:        getSpriteFromVector(SpriteType::NUM)->getTextureAddress()->selectSheetArea(getSpriteFromVector(SpriteType::NUM), 0); break;
        case KeyCodeWindowInput::KEY_1:         getSpriteFromVector(SpriteType::NUM)->getTextureAddress()->selectSheetArea(getSpriteFromVector(SpriteType::NUM), 1); break;
        case KeyCodeWindowInput::KEY_2:         getSpriteFromVector(SpriteType::NUM)->getTextureAddress()->selectSheetArea(getSpriteFromVector(SpriteType::NUM), 2); break;
            //case KeyCodeWindowInput::KEY_3:        selectSheetArea(getSpriteFromVector(SpriteType::NUM), 4); break;
            //case KeyCodeWindowInput::KEY_4:        selectSheetArea(getSpriteFromVector(SpriteType::NUM), 5); break;
            //case KeyCodeWindowInput::KEY_5:        selectSheetArea(getSpriteFromVector(SpriteType::NUM), 6); break;
            //case KeyCodeWindowInput::KEY_6:        selectSheetArea(getSpriteFromVector(SpriteType::NUM), 7); break;
            //case KeyCodeWindowInput::KEY_7:        selectSheetArea(getSpriteFromVector(SpriteType::NUM), 8); break;
            //case KeyCodeWindowInput::KEY_8:        selectSheetArea(getSpriteFromVector(SpriteType::NUM), 9); break;
            //case KeyCodeWindowInput::KEY_9:        selectSheetArea(getSpriteFromVector(SpriteType::NUM), 10); break;

        }
        keyPressedWin.pop();
        
    }
}
