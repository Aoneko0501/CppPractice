#include "Block.h"
#include <DxLib.h>
Block::Block(int x,int y,bool exsit)
{
	this->x = x;
	this->y = y;
	this->gh = LoadGraph("./sozai/RengaBlock.png");
	this->isExsit = exsit;
}

Block::~Block()
{
	delete this;
}

void Block::Draw()
{
	if (isExsit) {
		DrawGraph(x, y, gh, FALSE);
	}
}

int Block::GetBlockX()
{
	return this->x;
}

int Block::GetBlockY()
{
	return this->y;
}
