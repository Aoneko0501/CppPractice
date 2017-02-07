#pragma once
class Enemy {
	enum State {
		ALIVE,
		DEAD
	};
private:
	int x, y;// 座標
	float speed;	// 移動速度
	int handle;	// 敵ハンドル

	State e_state;
private:
	void Move();
	void Draw();
public:
	Enemy();
	~Enemy();
	void All();
};