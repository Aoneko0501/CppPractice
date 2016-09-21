#include "Player.h"
#include"pController.h"
#include<DxLib.h>
#include<assert.h>
void Player::Move()
{
	
	switch (p_State) {
	case PLAYER_WAIT:Wait(); break;
	case PLAYER_WALK:Walk(); break;
	case PLAYER_JUMP:Jump(); break;
	default:assert(!"異常なステータスです"); break;
	}

	x += vecX;
	y += vecY;
}

void Player::Draw()
{
	DrawGraph(x, y, gh, TRUE);
}

void Player::Wait()
{
	vecX *= 0.5;
}

void Player::Walk()
{
}

void Player::Jump()
{
}

bool Player::isDead()
{
	return (this->life <= 0) ? true : false;
}

Player::Player()
{
	this->x = 320;
	this->y = 240;
	this->vecX = 0.0f;
	this->vecY = 0.0f;

	this->gh = LoadGraph("Player.png");

	GetGraphSize(gh, &width, &height);

	this->life = 3;

	this->p_State = PLAYER_WAIT;

	this->accel = 0.5f;
}

void Player::All()
{
	Move();
	Draw();
}
