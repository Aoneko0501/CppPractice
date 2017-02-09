#pragma once
#include"Actor.h"
class Bullet :public Actor{
public:
	Bullet();
	Bullet(int bX, int bY);

	void setPoint(int bX,int bY);
	bool isDEAD();
	virtual void Move() override;
	virtual void Draw() override;
};