#pragma once

#include"CreatureParameter.h"

class Player : public CreatureParameter{
private:
	int life;		// 残機
	int bomb;		// 所持ボム数
	bool usingBomb;	// ボムを使っているかどうか

private:
	void Move();
	void Draw();
public:
	Player();
	void All();
};