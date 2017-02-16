#include"GameManager.h"
using namespace std;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); // �E�B���h�E���[�h�ύX�A�������A����ʐݒ�

	GameManager* gm = new GameManager();
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
		gm->Update();

		if (CheckHitKey(KEY_INPUT_ESCAPE))break;
	}

	DxLib_End();
	return 0;
}