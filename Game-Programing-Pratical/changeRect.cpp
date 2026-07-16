#include "programDefine.h"
#include<d3d9.h>
#include "Sprite.h"
#include "Texture.h"

void changeRect(Sprite sprite , int selectedAreaNumber, int textureRow, int textureColumn) {
	if (selectedAreaNumber == 0)return;
	Texture texture = *(sprite.getTextureAddress());
	int horizontalPixel = texture.getHorizontalPixel();
	int verticalPixel = texture.getVerticalPixel();
	int rowHeight = verticalPixel / textureRow;
	int columnWidth = horizontalPixel / textureColumn;
	int rowPosition = (selectedAreaNumber + textureColumn) / textureColumn;
	int columnPosition = selectedAreaNumber % textureColumn;

	int left = (columnPosition - 1) * horizontalPixel;
	int right = columnPosition * horizontalPixel;
	int top = (rowPosition - 1) * verticalPixel;
	int bottom = rowPosition * verticalPixel;

	sprite.setRectLeft(left);
	sprite.setRectRight(right);
	sprite.setRectTop(top);
	sprite.setRectBottom(bottom);
}