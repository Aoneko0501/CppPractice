//�v���[���[�����^�[���S���瓦�����邩

#include<iostream>
#include<string.h>
#include"Stage.h"
using namespace std;



int main() {
	//��Ԕz��m��
	Object* state = new Object[gStageHeight * gStageWidth];
	//�X�e�[�W������
	Stage* sg = new Stage(state, gStageWidth, gStageHeight, gStageData);

	//�ϐ�������
	int turn = 0;
	char input;
	bool gameSet = false;

	//���C�����[�v
	while (!gameSet) {
		//�^�[���o��
		turn++;
		//��ʕ\��
		sg->draw(state, gStageWidth, gStageHeight);
		//�������
		cout << "A:Right D:Left W:Up S:Down Command?" << endl;
		cin >> input;

		//��ʍX�V
		sg->update(state, input, gStageWidth, gStageHeight);
		//�p���\���ǂ���
		if (sg->checkClear(state, gStageWidth, gStageHeight)) {
			gameSet = true;
		}
	}
	//���ʔ��\
	sg->draw(state, gStageWidth, gStageHeight);
	cout << "GameOver!\n" << endl;
	cout << "���Ȃ���" << turn << "�^�[�������؂�܂����B" << endl;
	//��n��
	delete[] state;
	delete sg;
	state = 0;

	return 0;
}