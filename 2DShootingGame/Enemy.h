#pragma once
#include"Actor.h"
class Enemy : public Actor{
public:
	Enemy();
	Enemy(int x,int y);
	~Enemy();
	State All();
};