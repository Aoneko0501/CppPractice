#pragma once
class Enemy {
	enum State {
		ALIVE,
		DEAD
	};
private:
	int x, y;// ���W
	float speed;	// �ړ����x
	int handle;	// �G�n���h��

	State e_state;
private:
	void Move();
	void Draw();
public:
	Enemy();
	~Enemy();
	void All();
};