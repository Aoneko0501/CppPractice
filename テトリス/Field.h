#pragma once
#include"Controller.h"

#define BLOCK_HEIGHT 4
#define BLOCK_WIDTH 4

#define FIELD_HEIGHT 21
#define FIELD_WIDTH 12

//ブロックのデータ
int blocks[7][16] = {
	//I
	{
		0,0,1,0,
		0,0,1,0,
		0,0,1,0,
		0,0,1,0
	},
	//O
	{
		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0
	},
	//J
	{
		0,0,0,0,
		0,0,1,0,
		0,0,1,0,
		0,1,1,0
	},
	//L
	{
		0,0,0,0,
		0,1,0,0,
		0,1,0,0,
		0,1,1,0
	},
	//S
	{
		0,0,0,0,
		0,1,1,0,
		1,1,0,0,
		0,0,0,0
	},
	//Z
	{
		0,0,0,0,
		1,1,0,0,
		0,1,1,0,
		0,0,0,0
	},
	//T
	{
		0,0,0,0,
		0,1,1,1,
		0,0,1,0,
		0,0,0,0
	}
};

class Field {
	//現在アクティブなブロック
	int block[BLOCK_HEIGHT][BLOCK_WIDTH];
	//現在のフィールドの状態
	int stage[FIELD_HEIGHT][FIELD_WIDTH];
	//基本のフィールドの状態
	int field[FIELD_HEIGHT][FIELD_WIDTH];

public:
	//コントラスタを用いて初期化処理を行う
	Field() {
		init();
	}
	~Field(){}

	//初期化処理
	void init();

	//画面描写
	void draw();

	//画面更新
	void update(Controller c);

	//ブロックが一列そろっているか判定
	bool lineCheck();

	//ブロックが一番上まで積みあがっているかどうか
	//true=詰み:false=まだセーフ
	bool isGameOver();

};