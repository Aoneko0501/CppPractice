#include<DxLib.h>
#include"Block.h"
#include"Player.h"
#include"Stage.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPravInstance, LPSTR lpCmdLine, int nCmdShow) {
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)return -1;

	SetDrawScreen(DX_SCREEN_BACK);
	Stage* stage = new Stage();

	while (ProcessMessage() != -1) {
		int startTime = GetNowCount();
		ScreenFlip();
		ClearDrawScreen();

		stage->GameManager();

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;
		int endTime = GetNowCount();
		WaitTimer(1000 / 60 - (endTime - startTime));
	}

	delete stage;
	DxLib_End();
	return 0;
}

