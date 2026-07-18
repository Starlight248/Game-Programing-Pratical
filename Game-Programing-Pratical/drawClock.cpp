#include "programDefine.h"
#include <string>
#include <Windows.h>

void drawClock() {
	//{ D3DXVECTOR2(0, 200), D3DXVECTOR2(200, 400) };
	lineVertices.push_back(D3DXVECTOR2(0, 600));
	lineVertices.push_back(D3DXVECTOR2(400, 600));
}

//LPSTR translareString(std::string& font) {
//	return const_cast<char*>(font.c_str());
//}