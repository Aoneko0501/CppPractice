#pragma once

#include"ObjectParameter.h"

class Player : public ObjectParameter{
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