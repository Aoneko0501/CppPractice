#pragma once
#include"Actor.h"
#include"Bullet.h"
// Actor�N���X���p������
class Enemy : public Actor{
public:
	Enemy();
	Enemy(int x,int y,int gh);
	~Enemy();
	State All();

	void checkHit(Bullet* b[]);
};