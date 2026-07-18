#include "debug.h"
#include <string>
#include <Windows.h>
#include "programDefine.h"

void callMessageBoxA(std::string fileName, std::string message)
{
	if (!debug)return;
	MessageBoxA(NULL, message.c_str(), fileName.c_str(), MB_OK);
}
