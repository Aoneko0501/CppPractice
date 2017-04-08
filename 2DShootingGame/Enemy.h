#pragma once
#include"Actor.h"
#include"Bullet.h"
// ActorÉNÉâÉXÇåpè≥Ç∑ÇÈ
class Enemy : public Actor{
	int e_counter;
public:
	Bullet* bullet[BULLET_MAX];
public:
	Enemy();
	Enemy(float x,float y,int gh);
	virtual void Move() override;
	virtual void Shot() override;
	State All();
};

class NormalEnemy1 : public Enemy {
public:
	NormalEnemy1(float x, float y, int gh) : Enemy(x, y, gh) {};
	virtual void Move() override;
};

class NormalEnemy2 : public Enemy {
public:
	NormalEnemy2(float x, float y, int gh):Enemy(x, y, gh) {};
	virtual void Move() override;
	virtual void Shot() override;
};

class NormalEnemy3 : public Enemy {
public:
	NormalEnemy3(float x, float y, int gh):Enemy(x, y, gh) {};
	virtual void Move() override;
	virtual void Shot() override;
};