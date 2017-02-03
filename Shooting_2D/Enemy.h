#pragma once

#include"ObjectParameter.h"
/*
 “G‚ð•\‚·ƒNƒ‰ƒX‚Å‚·
 */
class Enemy:public ObjectParameter{
	int xFlag;
	int yFlag;
	int oldFlagX;
private:
	void Draw();
	void Move();
	void Update();
public:
	Enemy(float eX,float eY);
	bool All();
};