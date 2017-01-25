#include "Bullet.h"
#include "DxLib.h"
#include <math.h>

// 初期化関数
Bullet::Bullet(float x, float y)
{
	this->pos = Point2D(x, y);
	this->targetPos = targetPos;
	this->handle = LoadGraph("sozai/bullet01.bmp");
	this->isDead = false;
}

// 全ての処理を実行
void Bullet::All()
{
	Update();
	if (!this->isDead) {
		Draw();
	}
}


// 描画
void Bullet::Draw() {
	DrawGraph(pos.x, pos.y, handle, TRUE);
}

// 情報更新
void Bullet::Update()
{
}


