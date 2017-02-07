#include"DxLib.h"
#include "Player.h"
#include "GameInfo.h"

// �R���X�g���N�^
Player::Player()
	:x(0), y(0), handle(LoadGraph("../src/shooterDragon.bmp")), p_state(ALIVE)
{
}

// �f�X�g���N�^
Player::~Player() {
	delete this;
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

void Player::Draw()
{
	DrawGraph(x, y, handle, true);
}

void Player::All() {
	Move();
	Draw();
}
