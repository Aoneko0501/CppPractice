#include "Player.h"
#include"Stage.h"
#include<DxLib.h>
#include<math.h>

//enumでstateをつくる
enum State {
	STAND,
	WALK,
	DUSH,
	JUMP,
	NONE
};

Player::Player()
{
	SetX(300.0f);
	SetY(240.0f);
	SetVecX(0.0f);
	SetVecY(0.0f);
	this->gh = LoadGraph("Player.png");
	GetGraphSize(gh, &width, &height);
	this->live = true;
	jumpSpeed = 10.0f;


	//2段ジャンプ用フラグ
	bool oldJump = false;
	bool newJump = false;
	jump = 0;
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

bool Player::isLive() {
	return (this->live ? true : false);
}

bool Player::Draw()
{
	if (!this->live) { return false; }
		//描画
		DrawGraph((int)x, (int)y, gh, TRUE);

		DrawFormatString(0, 0, GetColor(255, 255, 255), "X1座標:%f", GetX());
		DrawFormatString(0, 20, GetColor(255, 255, 255), "X2座標:%f", GetX() + width);
		DrawFormatString(0, 40, GetColor(255, 255, 255), "Y1座標:%f", GetY());
		DrawFormatString(0, 60, GetColor(255, 255, 255), "Y2座標:%f", GetY() + height);
		DrawFormatString(0, 80, GetColor(255, 255, 255), "X座標加速度:%f", GetVecX());
		DrawFormatString(0, 100, GetColor(255, 255, 255), "Y座標加速度:%f", GetVecY());
		DrawFormatString(0, 120, GetColor(255, 255, 255), "ジャンプ回数:%d", jump);

		//移動
		Move();
		return true;
}

bool Player::Move()
{
	if (CheckHitKey(KEY_INPUT_D)) { this->live = false; return false; }

	float winX = Stage::WINDOW_X;
	float winY = Stage::WINDOW_Y;

	//加速度
	float accel = 0.5f;
	//最大スピード
	float maxSpeed = 5.0f;

	//上下の判定
	if (onGround()) {
		this->y = winY - height;
		this->vecY = 0.0f;
		jump = 0;
	}
	else if (y < 0) {
		this->y = 0.0f;
		this->vecY = 0.0f;
	}

	WallChecker();

	//ジャンプ
	//ジャンプした時の加速度を保存する
	//2段ジャンプ
	//落下処理も兼ねている
	Jump();

	//左右
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		//右
		if (vecX < maxSpeed) {
			this->vecX += accel;
		}
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) {
		//左
		if ((GetVecX() * -1) < maxSpeed) {
			this->vecX -= accel;
		}
	}
	else {
		//左右キーが押されていない場合は減速
		if (onGround()) {
			this->vecX *= accel  * 0.99f;
		}
	}
	//移動処理
	x += vecX;
	y += vecY;

	return true;
}

void Player::Jump()
{
	//重力加速度
	float g = 0.95f;

	newJump = CheckHitKey(KEY_INPUT_SPACE) ? true : false;

	if ((!oldJump && newJump) && (jump % 2 == 0) && onGround()) {
		this->vecY -= jumpSpeed;
		jump++;
	}
	else if ((!oldJump && newJump) && (jump % 2 == 1)) {
		SetVecY(0.0f);
		this->vecY -= jumpSpeed;
		jump++;
	}
	else {
		//落下処理も兼ねている
		this->vecY += g * 0.5f;
	}

	//連続でボタン入力が反応することを防止する
	oldJump = newJump;
}

//地面判定
bool Player::onGround() {
	if (y + height >= Stage::WINDOW_Y)return true;
	return false;
}

//壁判定
bool Player::WallChecker()
{
	if (x < 0) { x = 0.0f; vecX = 0.0f; return true; }//左側
	if (x + width > Stage::WINDOW_X) { x = Stage::WINDOW_X - width; vecX = 0.0f; return true; }//右側
	return false;
}
