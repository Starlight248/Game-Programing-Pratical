#include "SheetTexture.h"
#include "Sprite.h"
#include "debug.h"

static void changeRectCallMessageBox(std::string message) { callMessageBoxA("changeRect.cpp", message); }

void SheetTexture::changeRect(Sprite* sprite, int selectedAreaNumber)  {

	if (selectedAreaNumber == 0) { changeRectCallMessageBox("The selected Number is 0"); return; };

	int textureRow = this->textureRow;
	int textureColumn = this->textureColumn;

	if (textureRow == 0 || textureColumn == 0) { changeRectCallMessageBox("TextureRow or TextureColumn is 0"); return; }

	int horizontalPixel = this->horizontalPixel;
	int verticalPixel = this->verticalPixel;
	int rowHeight = verticalPixel / textureRow;
	int columnWidth = horizontalPixel / textureColumn;
	int rowPosition = (selectedAreaNumber % textureColumn) == 0 ? selectedAreaNumber / textureColumn : (selectedAreaNumber + textureColumn) / textureColumn;
	int columnPosition = (selectedAreaNumber % textureColumn) == 0 ? textureColumn : (selectedAreaNumber % textureColumn);

	int left = (columnPosition - 1) * columnWidth;
	int right = columnPosition * columnWidth;
	int top = (rowPosition - 1) * rowHeight;
	int bottom = rowPosition * rowHeight;

	(*sprite).setRectLeft(left);
	(*sprite).setRectRight(right);
	(*sprite).setRectTop(top);
	(*sprite).setRectBottom(bottom);
}

