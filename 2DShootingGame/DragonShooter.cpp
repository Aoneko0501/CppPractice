#include"DxLib.h"
using namespace std;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); // �E�B���h�E���[�h�ύX�A�������A����ʐݒ�

	int pad; // �W���C�p�b�h
	int pov;

	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {

	}

	DxLib_End();
	return 0;
}