#include<windows.h>
#include<stdio.h>
int main()
{
	while (true) {
		char key = 'A';
		// �L�[���͂��擾
		if (GetAsyncKeyState(key)) {
			printf("%c�L�[�������ꂽ\n", key);
		}

		if (GetAsyncKeyState(VK_LBUTTON)) {
			printf("�}�E�X�̍��{�^���������ꂽ\n");
		}

		if (GetAsyncKeyState(VK_MBUTTON)) {
			printf("�}�E�X�̒��{�^���������ꂽ\n");
		}

		if (GetAsyncKeyState(VK_RBUTTON)) {
			printf("�}�E�X�E�{�^���������ꂽ\n");
		}

		// ESCAPE�L�[�ŏI��
		if (GetAsyncKeyState(VK_ESCAPE)) {
			break;
		}
	}
	return 0;
}