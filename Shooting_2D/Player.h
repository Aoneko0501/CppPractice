#pragma once

#include"CreatureParameter.h"

class Player : public CreatureParameter{
private:
	int life;		// �c�@
	int bomb;		// �����{����
	bool usingBomb;	// �{�����g���Ă��邩�ǂ���

private:
	void Move();
	void Draw();
public:
	Player();
	void All();
};