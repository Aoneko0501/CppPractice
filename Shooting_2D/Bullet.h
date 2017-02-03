#pragma once
#include"ObjectParameter.h"

class Bullet : public ObjectParameter{
	Point2D targetPos;
private:
	void Draw();
	void Update();
public:
	Bullet(float x,float y);
	void All();
};