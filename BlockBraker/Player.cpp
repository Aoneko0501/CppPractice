#include<DxLib.h>
#include "Player.h"

Player::Player()
{
	x = 320;
	y = 400;
	speed = 10;
	gh = LoadGraph("player.png");
	GetGraphSize(gh, &width, &height);
}

Player::~Player()
{
	delete this;
}

void Player::Move()
{
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		if (x < 0)return;
		x -= speed;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT)) {
		if (x > 640 - width) return;
		x += speed;
	}
}

void Player::Draw()
{
	DrawGraph(x, y, gh, TRUE);
}

void Player::All()
{
	Move();
	Draw();
}
