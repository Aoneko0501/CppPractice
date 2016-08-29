#pragma once
class Block {
public:
	int x, y;
	int width, height;
	int gh;
	bool live;
	bool moveCheck;

	Block(int setX, int setY);
	~Block();
	void Draw();
	void Move();
	void All();
};