#pragma once
#include"GameManager.h"
class Block;
class Enemy;

class Stage {
	Block *b[300];
	Enemy *e[8];

	int score;
public:
	Stage();
	void Draw();

	Block GetBlock(int num);
};