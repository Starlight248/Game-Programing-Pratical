#include "programDefine.h"
#include "enum.h"
void trackCursorPosition(LPARAM lParam) {
    Sprite* cursor = nullptr;
    //  LPPOINT lpPoint = NULL;

    for (int i = 0; i < sprites.size(); i++) {
        if (sprites[i].getSpriteType() == SpriteType::CURSOR) {
            cursor = &sprites[i];
            break;
        }
    }

    if (cursor == nullptr) return;
    //int x = (short)LOWORD(lParam);
    //int y = (short)HIWORD(lParam);
    tagPOINT maybeIsCursor;
    GetCursorPos(&maybeIsCursor);

    bool temp = ScreenToClient(g_hWnd, &maybeIsCursor);
    //cout << "System Cursor     X: " << CursorPosition.x << ", Y: " << CursorPosition.y<<endl;
    //cout << "Custom Cursor     X: " << cursor->getSpritePosition().x << ", Y: " << cursor->getSpritePosition().y << endl;
    cursor->setPositionX(maybeIsCursor.x);
    cursor->setPositionY(maybeIsCursor.y);
}
