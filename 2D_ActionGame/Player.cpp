#include "Player.h"
#include"Stage.h"
#include<DxLib.h>
#include<math.h>


Player::Player()
{
	SetX(300.0f);
	SetY(240.0f);
	SetVecX(0.0f);
	SetVecY(0.0f);
	this->gh = LoadGraph("Player.png");
	GetGraphSize(gh, &width, &height);
	this->live = true;
}

Player::~Player() { delete this; }

void Player::SetX(float x) { this->x = x; }
void Player::SetY(float y) { this->y = y; }
void Player::SetGh(int gh) { this->gh = gh; }
void Player::SetVecX(float vx) { this->vecX = vx; }
void Player::SetVecY(float vy) { this->vecY = vy; }

float Player::GetX() { return this->x; }
float Player::GetY() { return this->y; }
int Player::GetGh() { return this->gh; }
float Player::GetVecX() { return this->vecX; }
float Player::GetVecY() { return this->vecY; }
int Player::GetWidth() { return this->width; }
int Player::GetHeight() { return this->height; }

void Player::Draw()
{
	if (!Move()) { delete this; }

	//描画
	DrawGraph((int)x, (int)y, gh, TRUE);

	DrawFormatString(0, 0, GetColor(255, 255, 255), "X1座標:%f", GetX());
	DrawFormatString(0, 20, GetColor(255, 255, 255), "X2座標:%f", GetX() + width);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "Y1座標:%f", GetY());
	DrawFormatString(0, 60, GetColor(255, 255, 255), "Y2座標:%f", GetY() + height);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "X座標加速度:%f", GetVecX());
	DrawFormatString(0, 100, GetColor(255, 255, 255), "Y座標加速度:%f", GetVecY());
}

bool Player::Move()
{

	//重力加速度
	float g = 0.95f;

	//加速度
	float accel = 0.3f;
	//最大スピード
	float maxSpeed = 3.0f;

	//上下の判定
	if (y > (float)Stage::WINDOW_Y - this->height) {
		this->y = Stage::WINDOW_Y - this->height;
		this->vecY = 0.0f;
	}
	else if (y < 0) {
		this->y = 0.0f;
		this->vecY = 0.0f;
	}

	//左右
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		this->vecX += accel;
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) {
		this->vecX -= accel;
	}
	else {
		this->vecX *= accel * 0.5f;
	}

	//ジャンプ
	if (CheckHitKey(KEY_INPUT_SPACE) && GetY() == Stage::WINDOW_Y - height) {
		Jump();
	}
	else {
		this->vecY += g * 0.5f;
	}

	//移動処理
	x += vecX;
	y += vecY;


	return true;
}

void Player::Jump()
{
	float jumpSpeed = 0.0f;

	while (jumpSpeed <= 15.0f) {
		y = jumpSpeed * jumpSpeed - Stage::WINDOW_Y;
		jumpSpeed += 0.05f;
	}
}
