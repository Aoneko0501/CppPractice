#include"Stage.h"
#include<iostream>
#include<time.h>

using namespace std;

void InitRand() {
	srand((unsigned int)time(NULL));
}

Stage::Stage(Object* state, int w, int h, const char* stageData) {
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

Stage::~Stage() {
	cout << endl;
}

int Stage::isPlayer(Object* state) {
	Object t;
	for (int py = 0; py <= gStageHeight; py++) {
		for (int px = 0; px <= gStageWidth; px++) {
			if (state[py * gStageHeight + px] == PLAYER)
			{
				return py * gStageHeight + px;
			}
		}
	}
	return -1;
}

int Stage::isDragon(Object* state) {
	Object t;
	for (int py = 0; py <= gStageHeight; py++) {
		for (int px = 0; px <= gStageWidth; px++) {
			if (state[py * gStageHeight + px] == DRAGON)
			{
				return py * gStageHeight + px;
			}
		}
	}
	return -1;
}

void Stage::draw(Object* state, int w, int h) {
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

void Stage::update(Object* state, char input, int w, int h) {
	//����������
	InitRand();

	//input��ϊ�
	int dx = 0;
	int dy = 0;
	switch (toupper(input)) {
	case 'A': dx = -1; break; //��
	case 'D': dx = 1; break; //�E
	case 'W': dy = -1; break; //��
	case 'S': dy = 1; break; //��
	}

	int p = Stage::isPlayer(state);//�v���C���ʒu
	int x = p % w;
	int y = p / w;
	//�ړ����W
	int moveX = x + dx;
	int moveY = y + dy;
	int movePlayer = moveY * w + moveX;
	if (moveX < 0 || moveY < 0 || moveX >= w || moveY >= h || state[movePlayer] == OBSTACLE) {
		return;
	}
	if (state[movePlayer] == SPACE || state[movePlayer] == DRAGON) {
		state[movePlayer] = (state[movePlayer] == DRAGON) ? PLAYER_MERGE_DRAGON : PLAYER;
		state[p] = SPACE;
	}

	int dxD = 0;
	int dyD = 0;

	//�h���S���̈ړ��������_���Ō��߂�
	switch (rand() % 4) {
	case 0: dxD = -1; break; //��
	case 1: dxD = 1; break; //�E
	case 2: dyD = -1; break; //��
	case 3: dyD = 1; break; //��
	}

	//�h���S���̈ړ�
	int pD = Stage::isDragon(state);//�h���S���ʒu
	int xD = pD % w;
	int yD = pD / w;
	//�ړ����W
	int moveDX = xD + dxD;
	int moveDY = yD + dyD;
	int moveDragon = moveDY * w + moveDX;
	if (moveDX < 0 || moveDY < 0 || moveDX >= w || moveDY >= h || state[moveDragon] == OBSTACLE) {
		return;
	}
	if (state[moveDragon] == SPACE || state[moveDragon] == PLAYER) {
		state[moveDragon] = (state[moveDragon] == PLAYER) ? PLAYER_MERGE_DRAGON : DRAGON;
		state[pD] = SPACE;
	}
}
	

bool Stage::checkClear(const Object* state, int w, int h) {
	for (int i = 0; i < w*h; i++) {
		if (state[i] == PLAYER_MERGE_DRAGON) {
			return true;
		}
	}
	return false;
}