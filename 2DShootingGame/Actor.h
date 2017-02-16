#pragma once
#include"GameInfo.h"

enum struct State {
	ALIVE,
	DEAD
};

// 生物に関する情報群
class Actor {
public:
	float x, y; //座標
	int handle; // 画像格納用
	float speed; // 移動速度

	State state; // 生存確認
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