#include"DxLib.h"
#include"GameManager.h"
using namespace std;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); // ウィンドウモード変更、初期化、裏画面設定

	GameManager* gm = new GameManager();
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
		gm->Update();
	}

	DxLib_End();
	return 0;
}