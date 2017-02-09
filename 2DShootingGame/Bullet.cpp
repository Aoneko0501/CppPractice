#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(int bX, int bY)
{
	// プレイヤーの真正面から発射
	setPoint(bX, bY);
	this->state = State::DEAD;
	this->speed = 5.0;
}

// 弾の座標を指定
void Bullet::setPoint(int bX, int bY)
{
	this->x = bX + (TIP_W / 2) - 4;
	this->y = bY;
}

bool Bullet::isDEAD()
{
	return (this->state == State::DEAD) ? true : false;
}

void Bullet::Move()
{
	// 真上にまっすぐ発射される
	y -= (this->speed) * 2.0;

	// 画面外にはみ出したら消滅させる
	if (this->y < -10)this->state = State::DEAD;
}

void Bullet::Draw()
{
	if (this->state != State::DEAD) {
		DrawGraph(this->x, this->y, handle, true);
	}
}
