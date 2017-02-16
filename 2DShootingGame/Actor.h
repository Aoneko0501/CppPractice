#pragma once
#include"GameInfo.h"

enum struct State {
	ALIVE,
	DEAD
};

// �����Ɋւ�����Q
class Actor {
public:
	float x, y; //���W
	int handle; // �摜�i�[�p
	float speed; // �ړ����x

	State state; // �����m�F
	Group group;

public:
	float getX();
	float getY();

	State getState();
	void setState(State s);
	virtual void Draw();
	virtual void Move();
	virtual void Shot();
	virtual State All();
};