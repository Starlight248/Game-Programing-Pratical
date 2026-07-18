#include "programDefine.h"
#include<d3d9.h>
#include "Sprite.h"
#include "Texture.h"	
#include "SheetTexture.h"
#include <Windows.h>
#include "debug.h"
#include <string>


static void changeRectCallMessageBox(std::string message) { callMessageBoxA("changeRect.cpp", message); }

void changeRect(Sprite* sprite , int selectedAreaNumber) {
	
	if (selectedAreaNumber == 0) { changeRectCallMessageBox("The selected Number is 0"); return; };
	Texture* texture = sprite->getTextureAddress();
	SheetTexture*  sheetTexture = dynamic_cast<SheetTexture*>(texture);
	if (sheetTexture == nullptr) { changeRectCallMessageBox("This is not SheetTexture"); return; }
	int textureRow = sheetTexture->getTextureRow();
	int textureColumn = sheetTexture->getTextureColumn();

	if (textureRow == 0 || textureColumn == 0) { changeRectCallMessageBox("TextureRow or TextureColumn is 0"); return; }

	int horizontalPixel = texture->getHorizontalPixel();
	int verticalPixel = texture->getVerticalPixel();
	int rowHeight = verticalPixel / textureRow;
	int columnWidth = horizontalPixel / textureColumn;
	int rowPosition = (selectedAreaNumber % textureColumn) == 0 ? selectedAreaNumber / textureColumn:(selectedAreaNumber + textureColumn) / textureColumn;
	int columnPosition = (selectedAreaNumber % textureColumn)== 0? textureColumn :(selectedAreaNumber % textureColumn);

	int left = (columnPosition - 1) * columnWidth;
	int right = columnPosition * columnWidth;
	int top = (rowPosition - 1) * rowHeight;
	int bottom = rowPosition * rowHeight;

	(*sprite).setRectLeft(left);
	(*sprite).setRectRight(right);
	(*sprite).setRectTop(top);
	(*sprite).setRectBottom(bottom);
}

