#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	
	ChangeWindowMode(TRUE);
	DxLib_Init();

	WaitKey();
	DxLib_End();
	return 0;
}