#include<DxLib.h>
#include "Block.h"

Block::Block(int setX, int setY)
{
	this->x = setX;
	this->y = setY;
	gh = LoadGraph("block.png");
	GetGraphSize(gh, &width, &height); //�摜�̃T�C�Y���擾
	live = true;
	moveCheck = true;
}

Block::~Block()
{
	delete[] this;
}

//�u���b�N��\��
void Block::Draw()
{
	if (live) {
		DrawGraph(x, y, gh, TRUE);
	}
}

void Block::Move()
{
	if (moveCheck) {
		x -= 10;
		if (x < 0) moveCheck = false;
	}
	else {
		x += 10;
		if (x > 640 - width) moveCheck = true;
	}

}

void Block::All()
{
	//Move();
	Draw();
}
