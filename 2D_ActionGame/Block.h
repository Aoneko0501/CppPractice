#pragma once
class Block {
	int x, y;
	int gh;
public:
	//�u���b�N�����݂��Ă��邩�ǂ���
	bool isExsit;

	Block(int x,int y,bool exsit);
	~Block();
	void Draw();

	int GetBlockX();
	int GetBlockY();

};
