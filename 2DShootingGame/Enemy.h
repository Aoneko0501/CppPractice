#pragma once
#include"Actor.h"

// ActorƒNƒ‰ƒX‚ğŒp³‚·‚é
class Enemy : public Actor{
public:
	Enemy();
	Enemy(int x,int y);
	~Enemy();
	State All();
};