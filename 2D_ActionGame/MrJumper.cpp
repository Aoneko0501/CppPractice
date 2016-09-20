#include<DxLib.h>
#include"GameManager.h"

static const int WINDOW_X = 640;
static const int WINDOW_Y = 480;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int CmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(WINDOW_X,WINDOW_Y,32);
	if (DxLib_Init() == -1)return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	//éŒ¾
	GameManager *gm = new GameManager();

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

	DxLib_End();

	return 0;
}