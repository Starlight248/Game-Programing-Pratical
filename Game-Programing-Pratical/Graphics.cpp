#include "Graphics.h"
#include "Initialization.h"
#include "programDefine.h"

void render()
{
    //	Clear the back buffer.
    d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(rgb.getRedValue(), rgb.getGreenValue(), rgb.getBlueValue()), 1.0f, 0);

    //	Begin the scene
    d3dDevice->BeginScene();
    int totalSprites = static_cast<int>(TextureType::COUNT);
    spriteBrush->Begin(D3DXSPRITE_ALPHABLEND);
    for (int i = 0;i < totalSprites;i++)
        //	Specify alpha blend will ensure that the spriteBrush will render the background with alpha.
    {
        Sprite currentSprite = sprites.at(i);
        RECT spriteRect = currentSprite.getSpriteRect();
        LPDIRECT3DTEXTURE9 texture = (*currentSprite.getTextureAddress()).getTexture();
        D3DXVECTOR3 spritePosition = currentSprite.getSpritePosition();



        //	Sprite rendering. Study the documentation.
        spriteBrush->Draw(texture, &spriteRect, NULL, &spritePosition, D3DCOLOR_XRGB(255, 255, 255));
        //spriteBrush->Draw(Texture, &spriteRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
        //spriteBrush->Draw(Texture, &spriteRect, NULL, &D3DXVECTOR3(32, 32, 0), D3DCOLOR_XRGB(255, 255, 255));
       fontBrush->DrawText(spriteBrush, font.c_str(), font.size(), &textRect, 0, D3DCOLOR_XRGB(255, 255, 255));
       
        //	End spriteBrush drawing

    }
    spriteBrush->Draw(numberTexture, &numberRect, NULL, &numberPosition, D3DCOLOR_XRGB(255, 255, 255));
    spriteBrush->End();

    {
      
        //	Begin to draw the lines.
        line->Begin();
        
            line->Draw(lineVertices.data(), 2, D3DCOLOR_XRGB(255, 255, 255));
        
       
        line->End();
    }

    //	End the scene
    d3dDevice->EndScene();

    //	Present the back buffer to screen
    d3dDevice->Present(NULL, NULL, NULL, NULL);
}
