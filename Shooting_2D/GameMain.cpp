#include<DxLib.h>
#define WINDOW_X 640
#define WINDOW_Y 320

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	ChangeWindowMode(TRUE);
	SetGraphMode(WINDOW_X, WINDOW_Y, 32);
	if (DxLib_Init() == -1)return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	// ç\ë¢ëÃíËã`

	while (ProcessMessage() != -1) {
		int startTime = GetNowCount();
		ScreenFlip();
		ClearDrawScreen();

		// èàóù

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;
		int endTime = GetNowCount();
		WaitTimer((1000 / 60) - (endTime - startTime));
	}
}