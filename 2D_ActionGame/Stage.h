#pragma once
#include"GameManager.h"
class Block;
class Enemy;

class Stage {
	Block *b[300];
	Enemy *e[8];

	int score;
public:
	int enemyConter;
public:
	Stage();
	void Draw();
	void AddScore(int score);
	bool isGameEnd();

	Block *GetBlock(int block_ID);
	Enemy *GetEnemy(int enemy_ID);
};
