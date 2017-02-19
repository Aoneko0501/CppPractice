#pragma once
#include"Actor.h"
#include"Bullet.h"

// Actor�N���X���p������
class Player : public Actor {
public:
	Bullet* bullet[BULLET_MAX];
	int markerHandle; // �����蔻��̉摜�\���n���h��
public:
	Player();
	~Player();

	virtual void Draw() override;
	virtual void Shot() override;
	virtual void Move() override;
	virtual State All() override;
};