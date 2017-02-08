#include"DxLib.h"
#include "Enemy.h"
#include "GameInfo.h"

Enemy::Enemy()
	:handle(LoadGraph("../src/Enemy/Enemy1A.bmp",true))
{
	this->x = 0;
	this->y = 0;
	this->e_state = ALIVE;
}

Enemy::~Enemy()
{
	delete this;
}

void Enemy::Draw() {
	DrawGraph(x, y, handle, true);
}

void Enemy::Move() {
	if (y <= 0) {
		y = WINDOW_HEIGHT;
	}
	else {
		y--;
	}

}

void Enemy::All() {
	Draw();
	Move();
}