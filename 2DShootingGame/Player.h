#pragma once
#include"Actor.h"
#include"Bullet.h"

// ActorƒNƒ‰ƒX‚ğŒp³‚·‚é
class Player : public Actor {
public:
	Bullet* bullet[BULLET_MAX];

public:
	Player();
	~Player();

	void Shot();
	virtual void Move() override;
	virtual State All() override;
};