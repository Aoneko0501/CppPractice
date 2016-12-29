#include "Bullet.h"
#include "DxLib.h"
#include <math.h>

// 初期化関数
Bullet::Bullet(float x, float y)
{
	this->pos.x = x;
	this->pos.y = y;
	this->targetPos = targetPos;
	this->handle = LoadGraph("sozai/bullet01.bmp");
}

// 全ての処理を実行
void Bullet::All()
{
	Draw();
	Move();
	Update();
}

void Bullet::Move()
{
	pos.x += 1.02;
	pos.y += 5;

	if (pos.x > 640)pos.x = 1;
	if (pos.y > 480)pos.y = 1;
}

// 描画
void Bullet::Draw() {
	DrawGraph(pos.x, pos.y, handle, TRUE);
}

// 情報更新
void Bullet::Update()
{
}


