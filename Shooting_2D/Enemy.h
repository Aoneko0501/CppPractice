#pragma once

#include"CreatureParameter.h"
/*
 �G��\���N���X�ł�
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