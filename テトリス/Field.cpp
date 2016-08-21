#include<stdio.h>
#include<random>
#include "Field.h"

//ブロックの縦,横
#define BLOCK_HEIGHT 4
#define BLOCK_WIDTH 4

//フィールドの縦,横
#define FIELD_HEIGHT 21
#define FIELD_WIDTH 12

int blocks[7][BLOCK_HEIGHT * BLOCK_WIDTH] = {
	{
		// 0 = 四角
		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0
	},
	{	// 1 = L字
		0,0,0,0,
		0,1,0,0,
		0,1,0,0,
		0,1,1,0
	},
	{	// 2 = J字
		0,0,0,0,
		0,0,1,0,
		0,0,1,0,
		0,1,1,0
	},
	{	// 3 = T字
		0,0,0,0,
		0,0,1,0,
		0,1,1,1,
		0,0,0,0
	},
	{	// 4 = Z字
		0,0,0,0,
		0,1,1,0,
		0,0,1,1,
		0,0,0,0
	},
	{	// 5 = S字
		0,0,0,0,
		0,1,1,0,
		1,1,0,0,
		0,0,0,0
	},
	{	// 6 = I字
		0,0,1,0,
		0,0,1,0,
		0,0,1,0,
		0,0,1,0
	}
};

//ブロック用配列の中身をすべて0で初期化
int block[BLOCK_HEIGHT][BLOCK_WIDTH];

//フィールド用配列初期化
int field[FIELD_HEIGHT][FIELD_WIDTH];

int fall = 0;
int side = 4;

void Field::init()
{
	for (int y = 0; y < FIELD_HEIGHT; y++) {
		for (int x = 0; x < FIELD_WIDTH; x++) {
			if (isWall(x, y)) { field[y][x] = 9; }
			else { field[y][x] = 0; }
		}
	}
}

bool Field::isWall(int x, int y) {
	if (y == FIELD_HEIGHT - 1 || x == 0 || x == FIELD_WIDTH - 1) { return true; }
	else { return false; }
}


void Field::draw()
{
	system("cls");
	for (int y = 0; y < FIELD_HEIGHT; y++) {
		for (int x = 0; x < FIELD_WIDTH; x++) {
			switch (field[y][x]) {
			case 0:
				//空白
				printf("　");
				break;
			case 1:
				//ブロック
				printf("■");
				break;
			case 9:
				//壁
				printf("□");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
}

void Field::update()
{
	for (int yy = 0; yy < BLOCK_HEIGHT; yy++) {
		for (int xx = 0; xx < BLOCK_WIDTH; xx++) {
			if (!isWall(xx + side, yy + fall)) {
				field[yy + fall][xx + side] = block[yy][xx];
			}
		}
	}
	fall++;
}

void Field::blockSelecter()
{
	//ランダムでブロックの種類を取得

	std::random_device rd;
	int block_id = rd() % 7;

	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			block[y][x] = blocks[block_id][y * BLOCK_WIDTH + x];
		}
	}
}

void Field::lineChecker()
{
}

bool Field::isGameOver()
{
	if () {
		return true;
	}

	return false;
}

void Field::gameTimer()
{
	_sleep(500);
}
