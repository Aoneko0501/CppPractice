/*
プレイヤーのクラスです
@author tukeru
*/
#include "Player.h"
#include "DxLib.h"
// プレイヤーのコンストラクタを作成
Player::Player()
	:life(3)
	, bomb(3)
	, usingBomb(false)
{
	pos = Point2D();
	handle = LoadGraph("sozai/shooterDragon.bmp");
	isDead = false;
}

void Player::Draw() {
	if (!isDead) {
		DrawGraph(pos.x, pos.y, handle, TRUE);
	}
}

void Player::Move() {
	
	bool moveLeft = CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_LEFT);
	bool moveRight = CheckHitKey(KEY_INPUT_A) || CheckHitKey(KEY_INPUT_RIGHT);
	bool moveUp = CheckHitKey(KEY_INPUT_W) || CheckHitKey(KEY_INPUT_UP);
	bool moveDown = CheckHitKey(KEY_INPUT_S) || CheckHitKey(KEY_INPUT_DOWN);

	if (CheckHitKey(KEY_INPUT_C)) {
		moveSpeed = 3.0f;
	}
	else {
		moveSpeed = 6.0f;
	}

	if (moveLeft && pos.x >= 0) {
		pos.x -= moveSpeed;
		if (pos.x < 0) pos.x = 0;
	}
	if (moveRight && pos.x < 640 - 32) {
		pos.x += moveSpeed;
		if (pos.x > 640 - 32) pos.x = 640 - 32;
	}
	if (moveUp && pos.y >= 0) {
		pos.y -= moveSpeed;
		if (pos.y < 0) pos.y = 0;
	}
	if (moveDown && pos.y < 480 - 32) {
		pos.y += moveSpeed;
		if (pos.y > 480 - 32) pos.y = 480 - 32;
	}
}

void Player::All() {
	Draw();
	Move();
}
