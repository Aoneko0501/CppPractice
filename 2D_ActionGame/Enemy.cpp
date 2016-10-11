#include "Enemy.h"
#include<DxLib.h>

// 敵の移動
void Enemy::Move()
{
}

// 敵の描写
void Enemy::Draw()
{
	if (this->live) DrawGraph(x, y, gh, FALSE);
}

// 敵のコンストラクタ
Enemy::Enemy(float x, float y)
{
	this->x = x;		// X座標
	this->y = y;		// Y座標

	this->gh = LoadGraph("./sozai/Enemy/Enemy1A.bmp");	// 画像ハンドルを格納
	GetGraphSize(gh, &width, &height);					// 画像のサイズを各変数に格納

	this->live = true;	// 敵が生きているか(存在しているか)どうか
	this->score = 200;	// 敵を倒したときに得られるスコア
}

// 敵のデストラクタ
Enemy::~Enemy()
{
	delete this;
}

// 敵が踏まれた時
void Enemy::Dead()
{
	this->live = false; // 死 
}

// この敵が持っているスコアを返す
int Enemy::GetScore()
{
	return this->score;
}

// 敵のX軸座標を返す
float Enemy::GetEnemyX()
{
	return this->x;
}

// 敵のY軸座標を返す
float Enemy::GetEnemyY()
{
	return this->y;
}

// 外部から敵が生きているかどうかを確認できるようにするための関数
bool Enemy::isAlive()
{
	return this->live;
}

// 敵の移動と描画を行う
void Enemy::All()
{
	Move();	// 移動
	Draw();	// 描画
}
