#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(int bX, int bY,int gh)
{
	// プレイヤーの真正面から発射
	setPoint(bX, bY);
	this->state = State::DEAD;
	this->speed = 5.0;
	this->handle = gh;
}

// 弾の座標を指定
void Bullet::setPoint(int bX, int bY)
{
	int gX;
	int gY;
	// 弾の画像のサイズを取得
	GetGraphSize(this->handle, &gX, &gY);

	this->x = bX + (TIP_W / 2) - (gX / 2);
	this->y = bY;
}

void Bullet::setState(State s)
{
	this->state = s;
}

bool Bullet::isDEAD()
{
	return (this->state == State::DEAD) ? true : false;
}

void Bullet::Move()
{

	// 画面外にはみ出したら消滅させる
	if ((this->y) < -10) { 
		this->state = State::DEAD;
		this->x = -10;
		this->y = -10;
	}
	else if(this->state == State::ALIVE){
		// 真上にまっすぐ発射される
		y -= (int)(this->speed) * 2.0;
	}
}

void Bullet::Draw()
{
	if (this->state != State::DEAD) {
		DrawGraph(this->x, this->y, handle, true);
	}
}
