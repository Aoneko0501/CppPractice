#pragma once
class Player 
{
	enum PlayerState {
		PLAYER_WAIT,
		PLAYER_WALK,
		PLAYER_JUMP
	};

	float x, y;
	float vecX, vecY;

	float accel;
	
	int gh;
	int width, height;

	int life;

	PlayerState p_State;
private:
	void Move();
	void Draw();

	void Wait();
	void Walk();
	void Jump();

	bool isDead();

public:
	Player();

	void All();
};