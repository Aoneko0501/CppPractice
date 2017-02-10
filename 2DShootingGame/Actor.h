#pragma once
#include"GameInfo.h"

enum struct State {
	ALIVE,
	DEAD
};

// �����Ɋւ�����Q
class Actor {
protected:
	int x, y; //���W
	int handle; // �摜�i�[�p
	float speed; // �ړ����x

	State state; // �����m�F

public:
	int getX();
	int getY();
	virtual void Draw();
	virtual void Move();
	virtual State All();
};