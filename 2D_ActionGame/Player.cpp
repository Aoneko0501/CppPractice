#include "Player.h"
#include<DxLib.h>

void Player::Move()
{

}

void Player::Draw()
{
	DrawGraph(x,y,gh,TRUE);
}

Player::Player(float x,float y)
{
	this->x = x;
	this->y = y;
	this->vecX = 0.0f;
	this->vecY = 0.0f;

	this->gh = LoadGraph("./sozai/Player.png");

	GetGraphSize(gh, &width, &height);

	this->life = 3;
}

void Player::All()
{
	Move();
	Draw();
}
