#pragma once
#include"GameManager.h"
class Block;

class Stage {
	Block *b[300];
	int score;
public:
	Stage();
	void Draw();

	Block GetBlock(int num);
};