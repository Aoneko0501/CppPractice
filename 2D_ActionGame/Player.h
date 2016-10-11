#pragma once
class Player {
public:
	float x, y;
	float vecX, vecY;
	int width, height;

	int gh;
	int x_Gh;

	int life;

	bool onGround;
	bool onBlock;

	bool isJump;
private:
	void Move();
	void Draw();
public:
	void JumpStateChanger(bool b);

	float GetX();
	float GetY();

	void Walk();
	void Jump();

	void SetOnBlock(bool b);
	void Damage();
	Player(float x, float y);
	bool isAlive();
	void All();
};
