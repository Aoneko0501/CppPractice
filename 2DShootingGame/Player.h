#pragma once

class Player {
	enum State{
		ALIVE,
		DEAD
	};
private:
	int x, y;// ���W
	float speed;	// �ړ����x
	int handle;	// �v���C���[�n���h��

	State p_state;
private:
	void Move();
	void Draw();
public:
	Player();
	~Player();
	void All();
};