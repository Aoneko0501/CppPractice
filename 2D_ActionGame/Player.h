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
private:
	void Move();
	void Draw();
	void JumpStateChanger(bool b);

public:
	float GetX();
	float GetY();


	void SetOnBlock(bool b);
	void Damage();
	Player(float x,float y);
	bool isAlive();
	void All();
};