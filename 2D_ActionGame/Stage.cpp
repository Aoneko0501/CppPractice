#include "Stage.h"

Stage::Stage()
{
	this->stage_X = 640;
	this->stage_Y = 480;

	this->ENEMY_SIZE = 10;
}

int Stage::GetEnemySize()
{
	return this->ENEMY_SIZE;
}
