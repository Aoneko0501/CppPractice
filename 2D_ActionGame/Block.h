#pragma once
class Block {
	int x, y;
	int gh;
public:
	//ブロックが存在しているかどうか
	bool isExsit;

	Block(int x,int y,bool exsit);
	~Block();
	void Draw();

	int GetBlockX();
	int GetBlockY();

};
