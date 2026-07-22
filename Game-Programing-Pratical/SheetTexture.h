#pragma once
#include <string>
#include "Texture.h"
class Sprite;
class SheetTexture :public Texture

{
	private:
		const int textureRow;
		const int textureColumn;
		//static void changeRectCallMessageBox(std::string message);

	public:
		SheetTexture(LPDIRECT3DTEXTURE9 texture, std::string path, int horizontalPixel, int verticalPixel, int textureRow, int textureColum) : Texture(texture,path,horizontalPixel,verticalPixel), textureRow(textureRow), textureColumn(textureColum) {};
		SheetTexture(LPDIRECT3DTEXTURE9 texture, int horizontalPixel, int verticalPixel, int textureRow, int textureColum) : Texture(texture, horizontalPixel, verticalPixel), textureRow(textureRow), textureColumn(textureColum) {};

		int getTotalSheetNumber() { return this->textureRow * this->textureColumn; };
		
		int getTextureRow() { return this->textureRow; }

		int getTextureColumn() { return this->textureColumn; }

		void selectSheetArea(Sprite* sprite, int selectedAreaNumber) override;


};

