#include<stdio.h>
#include<random>
#include "Field.h"

//�u���b�N�̏c,��
#define BLOCK_HEIGHT 4
#define BLOCK_WIDTH 4

//�t�B�[���h�̏c,��
#define FIELD_HEIGHT 21
#define FIELD_WIDTH 12

int blocks[7][BLOCK_HEIGHT * BLOCK_WIDTH] = {
	{
		// 0 = �l�p
		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0
	},
	{	// 1 = L��
		0,0,0,0,
		0,1,0,0,
		0,1,0,0,
		0,1,1,0
	},
	{	// 2 = J��
		0,0,0,0,
		0,0,1,0,
		0,0,1,0,
		0,1,1,0
	},
	{	// 3 = T��
		0,0,0,0,
		0,0,1,0,
		0,1,1,1,
		0,0,0,0
	},
	{	// 4 = Z��
		0,0,0,0,
		0,1,1,0,
		0,0,1,1,
		0,0,0,0
	},
	{	// 5 = S��
		0,0,0,0,
		0,1,1,0,
		1,1,0,0,
		0,0,0,0
	},
	{	// 6 = I��
		0,0,1,0,
		0,0,1,0,
		0,0,1,0,
		0,0,1,0
	}
};

//�u���b�N�p�z��̒��g�����ׂ�0�ŏ�����
int block[BLOCK_HEIGHT][BLOCK_WIDTH];

//�t�B�[���h�p�z�񏉊���
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
				//��
				printf("�@");
				break;
			case 1:
				//�u���b�N
				printf("��");
				break;
			case 9:
				//��
				printf("��");
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
	//�����_���Ńu���b�N�̎�ނ��擾

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
