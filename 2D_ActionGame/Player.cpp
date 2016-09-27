#include "Player.h"
#include"GameManager.h"
#include<DxLib.h>

static int jumpCounter = 0;
static bool isJump = false;

bool newJumpPush = false;
bool oldJumpPush = false;

void Player::Move()
{
	float accel = 0.5f;
	float g = 0.95;
	float maxSpeed = 10.0f;

	//地面判定
	if (y < WINDOW_Y - height) {
		vecY += g * accel;
	}
	else {
		vecY = 0.0f;
		y = WINDOW_Y - height;
		isJump = false;
	}

	//壁判定
	if (x > WINDOW_X - width) {
		x = WINDOW_X - width;
		vecX = 0.0f;
	}
	else if (x < 0) {
		x = 0.0f;
		vecX = 0.0f;
	}

	newJumpPush = (CheckHitKey(KEY_INPUT_SPACE)) ? true : false;

	//ジャンプ====================================
		if (newJumpPush && !oldJumpPush) {
			if (!isJump && y >= WINDOW_Y - height) {
				JumpStateChanger(true);
				jumpCounter++;
			}
			else if (isJump && y < WINDOW_Y - height) {
				JumpStateChanger(false);
				jumpCounter++;
			}
		}
		//===================================================
		//ジャンプしていないときは左右移動
		//RIGHT==============================================
		if (CheckHitKey(KEY_INPUT_RIGHT)) {

			if (vecX < 0) { vecX += accel * 1.5f; }//先に左側へ走っていた時
			else { vecX += accel; }

			if (vecX >= maxSpeed)vecX = maxSpeed;

			gh = LoadGraph("./sozai/PlayerA.png");
			GetGraphSize(gh, &width, &height);
		}
		//LEFT===============================================
		else if (CheckHitKey(KEY_INPUT_LEFT)) {

			if (vecX > 0) { vecX -= accel * 1.5f; }//先に右側へ走っていた時
			else { vecX -= accel; }

			if (vecX <= -1 * maxSpeed)vecX = -1 * maxSpeed;

			gh = LoadGraph("./sozai/PlayerB.png");
			GetGraphSize(gh, &width, &height);
		}
		else {
			if(y >= WINDOW_Y - height)vecX *= 0.5;
		}
	oldJumpPush = newJumpPush;

	x += vecX;
	y += vecY;


}

void Player::Damage()
{
	life--;
}

void Player::JumpStateChanger(bool b) {
	this->vecY = -17.5f;
	isJump = b;
}

void Player::Draw()
{
	DrawGraph(x, y, gh, TRUE);

	DrawFormatString(0, 0, GetColor(255, 255, 255), "X軸加速度：%f", vecX);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "Y軸加速度：%f", vecY);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "ジャンプ回数：%d", jumpCounter);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "ジャンプ：%s", isJump ? "true" : "false");

}

Player::Player(float x, float y)
{
	this->x = x;
	this->y = y;
	this->vecX = 0.0f;
	this->vecY = 0.0f;

	this->gh = LoadGraph("./sozai/PlayerA.png");
	GetGraphSize(gh, &width, &height);

	this->life = 3;
}

bool Player::isAlive()
{
	if (this->life > 0)return true;
	return false;
}



void Player::All()
{
	Move();
	Draw();
}
