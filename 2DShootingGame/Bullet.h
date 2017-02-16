#pragma once
#include"Actor.h"
class Bullet :public Actor{
public:
	Bullet();
	Bullet(float bX, float bY,int gh);

	void setPoint(float bX,float bY);
	bool isDEAD();
	virtual void Move() override;
	virtual void Draw() override;
};