#include "programDefine.h"
#include<d3d9.h>
#include "Sprite.h"
#include "Texture.h"
#include <Windows.h>

void changeRect(Sprite* sprite , int selectedAreaNumber, int textureRow, int textureColumn) {
	
	if (selectedAreaNumber == 0) MessageBox(NULL, "The selected Number is 0", "changeRect.cpp", MB_OK); return;
	Texture texture = *((*sprite).getTextureAddress());

	

	int horizontalPixel = texture.getHorizontalPixel();
	int verticalPixel = texture.getVerticalPixel();
	int rowHeight = verticalPixel / textureRow;
	int columnWidth = horizontalPixel / textureColumn;
	int rowPosition = (selectedAreaNumber % textureColumn) == 0 ? selectedAreaNumber / textureColumn:(selectedAreaNumber + textureColumn) / textureColumn;
	int columnPosition = (selectedAreaNumber % textureColumn)== 0? textureColumn :(selectedAreaNumber % textureColumn);

	int left = (columnPosition - 1) * horizontalPixel;
	int right = columnPosition * horizontalPixel;
	int top = (rowPosition - 1) * verticalPixel;
	int bottom = rowPosition * verticalPixel;

	(*sprite).setRectLeft(left);
	(*sprite).setRectRight(right);
	(*sprite).setRectTop(top);
	(*sprite).setRectBottom(bottom);
}