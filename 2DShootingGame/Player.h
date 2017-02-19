#pragma once
#include"Actor.h"
#include"Bullet.h"

// Actorクラスを継承する
class Player : public Actor {
public:
	Bullet* bullet[BULLET_MAX];
	int markerHandle; // 当たり判定の画像表示ハンドル
public:
	Player();
	~Player();

	virtual void Draw() override;
	virtual void Shot() override;
	virtual void Move() override;
	virtual State All() override;
};