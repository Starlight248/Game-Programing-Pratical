#include "programDefine.h"
void trackCursorPosition(LPARAM lParam) {
    Sprite* cursor;
    //  LPPOINT lpPoint = NULL;
    tagPOINT maybeIsCursor;
    GetCursorPos(&maybeIsCursor);
    bool temp = ScreenToClient(g_hWnd, &maybeIsCursor);
    cursor = &sprites.at(getSpriteID(TextureType::CURSOR));
    //int x = (short)LOWORD(lParam);
    //int y = (short)HIWORD(lParam);


    //cout << "System Cursor     X: " << CursorPosition.x << ", Y: " << CursorPosition.y<<endl;
    //cout << "Custom Cursor     X: " << cursor->getSpritePosition().x << ", Y: " << cursor->getSpritePosition().y << endl;
    cursor->setPositionX(maybeIsCursor.x);
    cursor->setPositionY(maybeIsCursor.y);
}
