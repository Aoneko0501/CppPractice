#pragma once

class Player {
	enum State{
		ALIVE,
		DEAD
	};
private:
	int x, y;// 座標
	float speed;	// 移動速度
	int handle;	// プレイヤーハンドル

	State p_state;
private:
	void Move();
	void Draw();
public:
	Player();
	~Player();
	void All();
};