#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(float bX, float bY, int gh)
{
	// プレイヤーの真正面から発射
	setPoint(bX, bY);
	this->state = State::DEAD;
	this->speed = 3.0F;
	this->handle = gh;
	this->group = Group::OTHER;
}

// 弾の座標を指定
void Bullet::setPoint(float bX, float bY)
{
	int gX;
	int gY;
	// 弾の画像のサイズを取得
	GetGraphSize(this->handle, &gX, &gY);

	this->x = bX + (TIP_W / 2) - (gX / 2);
	this->y = bY;
}


bool Bullet::isDEAD()
{
	return (this->state == State::DEAD) ? true : false;
}

void Bullet::Move()
{
	// 画面外にはみ出したら消滅させる
	if ((this->y) < -10.0F || (this->y) > (float)WINDOW_HEIGHT + 10.0F
		|| (this->x) > (float)WINDOW_WIDTH + 10.0F || (this->x) < -10.0F 
		|| this->state != State::ALIVE) 
	{
		this->state = State::DEAD;
		this->x = -100.0F;
		this->y = -100.0F;
	}
}

void Bullet::Draw()
{
	if (this->state != State::DEAD) {
		DrawGraph(this->x, this->y, handle, true);
	}
}
