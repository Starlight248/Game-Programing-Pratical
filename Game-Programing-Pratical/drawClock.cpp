#include "programDefine.h"
#include <string>
#include <Windows.h>
#include <d3dx9math.h>

void drawClock(LPD3DXLINE lineBrush, int totalLine) {
	int lineDistance=50;
	int distanceFromCenterPoint=50;
	int centerX, centerY;
	centerX = 450;
	centerY = 300;
	float angleStep = (D3DX_PI * 2.0f) / totalLine;
    for (int i = 0; i < totalLine; i++) {

        //R not degree
        float currentAngle = i * angleStep;

        lineVertices[0].x = centerX + cos(currentAngle) * distanceFromCenterPoint;
        lineVertices[0].y = centerY + sin(currentAngle) * distanceFromCenterPoint;

        lineVertices[1].x = centerX + cos(currentAngle) * (distanceFromCenterPoint + lineDistance);
        lineVertices[1].y = centerY + sin(currentAngle) * (distanceFromCenterPoint + lineDistance);

        lineBrush->Draw(lineVertices, 2, D3DCOLOR_XRGB(255, 255, 255));
    }
 
    SYSTEMTIME time;
    GetLocalTime(&time); 


    float secAngle = (time.wSecond / 60.0f) * (D3DX_PI * 2.0f) - (D3DX_PI / 2.0f);

 
    float minAngle = (time.wMinute / 60.0f) * (D3DX_PI * 2.0f) - (D3DX_PI / 2.0f)
        + (time.wSecond / 60.0f) * ((D3DX_PI * 2.0f) / 60.0f);

    float hourAngle = ((time.wHour % 12) / 12.0f) * (D3DX_PI * 2.0f) - (D3DX_PI / 2.0f)
        + (time.wMinute / 60.0f) * ((D3DX_PI * 2.0f) / 12.0f);

    float hourDis = 45.0f; 
    float minDis = 65.0f;  
    float secDis = 85.0f; 

    lineVertices[0].x = centerX;
    lineVertices[0].y = centerY;

    lineVertices[1].x = centerX + cos(hourAngle) * hourDis;
    lineVertices[1].y = centerY + sin(hourAngle) * hourDis;
    lineBrush->Draw(lineVertices, 2, D3DCOLOR_XRGB(255, 50, 50));

    lineVertices[1].x = centerX + cos(minAngle) * minDis;
    lineVertices[1].y = centerY + sin(minAngle) * minDis;
    lineBrush->Draw(lineVertices, 2, D3DCOLOR_XRGB(50, 255, 50));

    lineVertices[1].x = centerX + cos(secAngle) * secDis;
    lineVertices[1].y = centerY + sin(secAngle) * secDis;
    lineBrush->Draw(lineVertices, 2, D3DCOLOR_XRGB(50, 50, 255));

}

//LPSTR translareString(std::string& font) {
//return const_cast<char*>(font.c_str());
//}

