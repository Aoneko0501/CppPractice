#include<DxLib.h>
#include"GameManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int CmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(WINDOW_X, WINDOW_Y, 32);
	if (DxLib_Init() == -1)return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	//éŒ¾
	GameManager *gm = new GameManager(WINDOW_X, WINDOW_Y);

	while (ProcessMessage() != -1) {
		int startTime = GetNowCount();
		ScreenFlip();
		ClearDrawScreen();

		//ˆ—
		gm->All();

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;
		int endTime = GetNowCount();
		WaitTimer((1000 / 60) - (endTime - startTime));
	}

	delete gm;
	DxLib_End();

	return 0;
}
