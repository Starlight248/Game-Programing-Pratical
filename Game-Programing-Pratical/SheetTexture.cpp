#include "SheetTexture.h"
#include "Sprite.h"
#include "debug.h"
#include <string>

void changeRectCallMessageBox(std::string message) { callMessageBoxA("changeRect.cpp", message); }




void SheetTexture::selectSheetArea(Sprite* sprite, int selectedArea)  {

	if (selectedArea < 0 || selectedArea > this->getTotalSheetNumber()) { changeRectCallMessageBox("The selected Number didn't in range"); return; };

	int textureRow = this->textureRow;
	int textureColumn = this->textureColumn;

	if (textureRow == 0 || textureColumn == 0) { changeRectCallMessageBox("TextureRow or TextureColumn is 0"); return; }

	int horizontalPixel = this->horizontalPixel;
	int verticalPixel = this->verticalPixel;
	int rowHeight = verticalPixel / textureRow;
	int columnWidth = horizontalPixel / textureColumn;
	int rowPosition = selectedArea / textureColumn;
	int columnPosition = selectedArea % textureColumn;

	int left = columnPosition * columnWidth;
	int right = (columnPosition + 1) * columnWidth;
	int top = rowPosition * rowHeight;
	int bottom = (rowPosition+1)*rowHeight;

	//int horizontalPixel = this->horizontalPixel;
	//int verticalPixel = this->verticalPixel;
	//int rowHeight = verticalPixel / textureRow;
	//int columnWidth = horizontalPixel / textureColumn;
	//int rowPosition = (selectedArea % textureColumn) == 0 ? selectedArea / textureColumn : (selectedArea + textureColumn) / textureColumn;
	//int columnPosition = (selectedArea % textureColumn) == 0 ? textureColumn : (selectedArea % textureColumn);

	//int left = (columnPosition - 1) * columnWidth;
	//int right = columnPosition * columnWidth;
	//int top = (rowPosition - 1) * rowHeight;
	//int bottom = rowPosition * rowHeight;

	(*sprite).setRectLeft(left);
	(*sprite).setRectRight(right);
	(*sprite).setRectTop(top);
	(*sprite).setRectBottom(bottom);
}

