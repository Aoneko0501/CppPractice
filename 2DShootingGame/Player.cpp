#include"DxLib.h"
#include "Player.h"

// �R���X�g���N�^
Player::Player()
{
	this->x = 0;
	this->y = 0;
	this->handle = LoadGraph("../src/shooterDragon.bmp",true);
}

// �f�X�g���N�^
Player::~Player() {
}

// �ړ��֐�
void Player::Move() {
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		x += 2;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		x -= 2;
	}
	if (CheckHitKey(KEY_INPUT_UP)) {
		y -= 2;
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		y += 2;
	}
	
	if (x < 0) x = 0;
	if (x >= WINDOW_WIDTH - TIP_W) x = WINDOW_WIDTH - TIP_W;
	if (y < 0) y = 0;
	if (y >= WINDOW_HEIGHT - TIP_W) y = WINDOW_HEIGHT - TIP_W;
}


State Player::All() {
	Move();
	Draw();
	
	return State::ALIVE;
}
