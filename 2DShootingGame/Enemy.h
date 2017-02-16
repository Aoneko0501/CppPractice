#pragma once
#include"Actor.h"
#include"Bullet.h"
// Actor�N���X���p������
class Enemy : public Actor{
	// �ړ��^�C�v
	int type;
	int e_counter;
public:
	Bullet* bullet[BULLET_MAX];
	int rebornCounter;
public:
	Enemy();
	Enemy(float x,float y,int gh,int type);
	~Enemy();
	virtual void Move() override;
	virtual void Shot() override;
	State All();
};