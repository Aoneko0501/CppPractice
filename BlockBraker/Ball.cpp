#include<DxLib.h>
#include "Ball.h"

Ball::Ball() {
	this->x = 300;
	this->y = 300;
	this->r = 7;

	this->vecX = 3;
	this->vecY = 3;
}

Ball::~Ball()
{
	delete this;
}

void Ball::Draw()
{
	DrawCircle(x, y, r, GetColor(255, 255, 255), TRUE);
}

void Ball::Move() {
	x += vecX;
	y += vecY;
}

void Ball::All() {
	Move();
	Draw();
}