#pragma once

#include"Block.h"
#include"Ball.h"
#include"Player.h"

class Stage {
public:
	static const int WINDOW_X;
	static const int WINDOW_Y;
	enum { BLOCK_NUM = 24};

	Player* player;
	Ball* ball;
	Block* block[BLOCK_NUM];

	enum State {
		START,
		END
	};

	int blockSum;
	int score;
	State gameState;
	bool resetCheck;
	bool oldButtonPush;
	bool newButtonPush;
	

	//�R���X�g���N�^�ɂ�菉����
	Stage();

	//�Q�[���R���g���[���p
	void GameManager();
	//�Q�[�����
	void Game();

};