#pragma once

#include"CreatureParameter.h"
/*
 “G‚ð•\‚·ƒNƒ‰ƒX‚Å‚·
 */
class Enemy:public CreatureParameter{
private:
	void Draw();
	void Move();
	void Update();
public:
	Enemy(float eX,float eY);
	bool All();
};