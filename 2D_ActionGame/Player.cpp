#include "Player.h"
#include"GameManager.h"
#include<DxLib.h>

static int jumpCounter = 0;

static bool showParam = false;

static float accel = 0.5f;
static float g = 0.95;
static float maxSpeed = 10.0f;

//スペースキーを押したときのみ、処理を行わせる用の変数
bool newJumpPush = false;
bool oldJumpPush = false;

bool newShowState = false;
bool oldShowState = false;

//プレイヤー位置を示すアイコンを
static bool isOutOfWindow = true;

//=============================================
//移動関係
//=============================================
void Player::Move()
{

	//地面判定=================================
	onGround = (y >= WINDOW_Y - height) ? true : false;

	if (onGround) {
		vecY = 0.0f;
		y = WINDOW_Y - height;
		isJump = false;
	}
	else if (!onGround) {
		vecY += g * accel;
	}

	//壁判定====================================
	if (x > WINDOW_X - width) {
		x = WINDOW_X - width;
		vecX = 0.0f;
	}
	else if (x < 0) {
		x = 0.0f;
		vecX = 0.0f;
	}

	Jump();
	Walk();

	//ここで座標を移動させる
	x += vecX;
	y += vecY;

}

void Player::SetOnBlock(bool b)
{
	this->onBlock = b;
}

//ダメージ
void Player::Damage()
{
	life--;
}

//ジャンプしたときに2段ジャンプフラグを変更する
void Player::JumpStateChanger(bool b) {
	this->vecY = -17.5f;
	isJump = b;
}

float Player::GetX()
{
	return this->x;
}

float Player::GetY()
{
	return this->y;
}

void Player::Walk()
{
	//===================================================
	//左右移動
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
		if (onGround || onBlock)vecX *= 0.5;
	}
}

void Player::Jump()
{
	newJumpPush = (CheckHitKey(KEY_INPUT_SPACE)) ? true : false;

	//ジャンプ====================================
	if (newJumpPush && !oldJumpPush) {
		if (!isJump && (onGround || onBlock)) {
			JumpStateChanger(true);
			jumpCounter++;
		}
		else if (isJump && (!onGround||!onBlock)) {
			JumpStateChanger(false);
			jumpCounter++;
		}
	}

	oldJumpPush = newJumpPush;
}


//描画
void Player::Draw()
{
	//位置
	DrawGraph(x, 0, x_Gh, FALSE);
	//キャラ表示
	DrawGraph(x, y, gh, FALSE);

	newShowState = CheckHitKey(KEY_INPUT_D) ? true : false;

	if (newShowState && !oldShowState) {
		showParam = showParam ? false : true;
	}

	if (showParam) {
		//ステータス
		DrawFormatString(0, 0, GetColor(255, 255, 255), "X軸加速度：%f", vecX);
		DrawFormatString(0, 20, GetColor(255, 255, 255), "Y軸加速度：%f", vecY);
		DrawFormatString(0, 40, GetColor(255, 255, 255), "ジャンプ回数：%d", jumpCounter);
		DrawFormatString(0, 60, GetColor(255, 255, 255), "ジャンプ：%s", isJump ? "true" : "false");
		DrawFormatString(0, 80, GetColor(255, 255, 255), "ブロック：%s", onBlock ? "true" : "false");
	}

	oldShowState = newShowState;
}

//初期設定
Player::Player(float x, float y)
{
	this->x = x;
	this->y = y;
	this->vecX = 0.0f;
	this->vecY = 0.0f;

	this->gh = LoadGraph("./sozai/PlayerA.png");
	GetGraphSize(gh, &width, &height);

	this->x_Gh = LoadGraph("./sozai/PlayerXY.bmp");

	this->life = 3;

	this->onGround = false;
	this->onBlock = false;

	this->isJump = false;


}

//生きているかどうか
bool Player::isAlive()
{
	if (this->life > 0)return true;
	return false;
}

//とりあえず回す
void Player::All()
{
	Move();
	Draw();
}
