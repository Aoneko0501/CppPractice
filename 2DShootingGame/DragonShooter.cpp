#include"DxLib.h"
using namespace std;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); // ウィンドウモード変更、初期化、裏画面設定

	int pad; // ジョイパッド
	int pov;

	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {

	}

	DxLib_End();
	return 0;
}