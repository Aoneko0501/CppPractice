#pragma once
#include"Actor.h"
#include"Bullet.h"
// Actorクラスを継承する
class Enemy : public Actor{
	// 移動タイプ
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