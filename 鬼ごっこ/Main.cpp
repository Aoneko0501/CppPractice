//�v���[���[�����^�[���S���瓦�����邩

#include<iostream>
#include<string.h>
#include"Stage.h"
using namespace std;

//#�ǁ@p�v���C���@D�G�@@��Q��

const char gStageData[] = "\
##########\n\
#        #\n\
# @   D  #\n\
#        #\n\
#   p @  #\n\
#        #\n\
##########";

const int gStageWidth = 10;
const int gStageHeight = 7;

enum Object {
	WALL,
	OBSTACLE,
	PLAYER,
	DRAGON,
	SPACE,
	PLAYER_MERGE_DRAGON,

	UNKNOWN
};

//�֐��v���g�^�C�v(������1�����Ȃ͈̂�����炵��)
void initialize(Object* stage, int w, int h, const char* stageData);//������
void draw(Object* stage, int w, int h);//�`��
void update(Object* stage, char input, int w, int h);//��ʍX�V
bool checkClear(const Object* stage, int w, int h);//�N���A�`�F�b�J�[


int main() {
	//��Ԕz��m��
	Object* state = new Object[gStageHeight * gStageWidth];
	//�X�e�[�W������
	initialize(state, gStageWidth, gStageHeight, gStageData);

	//�ϐ�������
	int turn = 0;
	char input;
	bool gameSet = false;
	//���C�����[�v
	while (!gameSet) {
		//�^�[���o��
		turn++;
		//��ʕ\��
		draw(state, gStageWidth, gStageHeight);
		//�������
		cout << "A:Right D:Left W:Up D:Down Command?" << endl;
		cin >> input;

		//��ʍX�V
		update(state, input, gStageWidth, gStageHeight);
		//�p���\���ǂ���
		if (checkClear(state, gStageWidth, gStageHeight)) {
			gameSet = true;
		}
	}
	//���ʔ��\
	cout << "GameOver!\n" << endl;
	cout << "���Ȃ���" << turn << "�^�[�������؂�܂����B" << endl;
	//��n��
	delete[] state;
	state = 0;

	return 0;
}

//�֐���`
void initialize(Object* state, int w, int h, const char* stageData) {
	const char* data = stageData; //�ǂݍ��݃|�C���^
	int x = 0;
	int y = 0;

	while (*data != '\0') {//NULL�����łȂ����ǂ���
		Object t;
		switch (*data) {
		case '#':t = WALL; break;
		case ' ':t = SPACE; break;
		case 'p':t = PLAYER; break;
		case 'D':t = DRAGON; break;
		case 'T':t = PLAYER_MERGE_DRAGON; break;
		case '@':t = OBSTACLE; break;
		case '\n': //���̍s��
			x = 0;
			y++;
			t = UNKNOWN;
			break;
		default:t = UNKNOWN; break;
		}
		data++;//�|�C���^�����̕����̃|�C���^�֐؂�ւ���
		//�m��Ȃ������𖳎�����p
		if (t != UNKNOWN) {
			state[y*w + x] = t;
			x++;
		}
	}
}

void draw(Object* state, int w, int h) {
	//enum�^�̕��тƓ����ɂ���
	const char font[] = { '#','@','p','D',' ','T' };

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			Object o = state[y*w + x];
			cout << font[o];
		}
		cout << endl;
	}
}

void update(Object* stage, char input, int w, int h) {
	Stage* s = new Stage();
	//input��ϊ�
	int dx = 0;
	int dy = 0;
	switch (toupper(input)) {
	case 'A': dx = -1; break; //��
	case 'D': dx = 1; break; //�E
	case 'W': dy = -1; break; //��
	case 'S': dy = 1; break; //��
	}
	//Stage�I�u�W�F�N�g���
	delete s;


}