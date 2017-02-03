#pragma once

#include"ObjectParameter.h"

class Player : public ObjectParameter{
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