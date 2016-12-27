#include<windows.h>
#include<stdio.h>
int main()
{
	while (true) {
		char key = 'A';
		// キー入力を取得
		if (GetAsyncKeyState(key)) {
			printf("%cキーが押された\n", key);
		}

		if (GetAsyncKeyState(VK_LBUTTON)) {
			printf("マウスの左ボタンが押された\n");
		}

		if (GetAsyncKeyState(VK_MBUTTON)) {
			printf("マウスの中ボタンが押された\n");
		}

		if (GetAsyncKeyState(VK_RBUTTON)) {
			printf("マウス右ボタンが押された\n");
		}

		// ESCAPEキーで終了
		if (GetAsyncKeyState(VK_ESCAPE)) {
			break;
		}
	}
	return 0;
}