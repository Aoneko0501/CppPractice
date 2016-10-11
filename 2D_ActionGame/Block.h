#pragma once
class Block {
	int x, y;
	int gh;
public:
	//ƒuƒƒbƒN‚ª‘¶İ‚µ‚Ä‚¢‚é‚©‚Ç‚¤‚©
	bool isExsit;

	Block(int x,int y,bool exsit);
	~Block();
	void Draw();

	int GetBlockX();
	int GetBlockY();

};
