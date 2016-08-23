#include<stdio.h>
#include<random>
#include<Windows.h>
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

//�����̎��Ɏg�p����
int stage[FIELD_HEIGHT][FIELD_WIDTH];

int fall = 0;
int side = 4;

int counter = 0;
int sleepTime = 16;

int score = 0;

void Field::init()
{
	for (int y = 0; y < FIELD_HEIGHT; y++) {
		for (int x = 0; x < FIELD_WIDTH; x++) {
			if (isWall(x, y)) { stage[y][x] = 9; }
			else { stage[y][x] = 0; }
			field[y][x] = 0;
		}
	}
	blockSelecter();
}

bool Field::isWall(int x, int y) {
	if (y == FIELD_HEIGHT - 1 || x == 0 || x == FIELD_WIDTH - 1) { return true; }
	else { return false; }
}


void Field::draw()
{
	system("cls");

	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		for (int j = 0; j < BLOCK_WIDTH; j++) {
			if (block[i][j] != 0) {
				field[i + fall][j + side] += block[i][j];
			}
		}
	}

	printf("SCORE : %d\n", score);

	for (int y = 0; y < FIELD_HEIGHT; y++) {
		for (int x = 0; x < FIELD_WIDTH; x++) {

			if (isWall(x, y)) { stage[y][x] = 9; }

			field[y][x] += stage[y][x];

			switch (field[y][x]) {
			case 0:
				//��
				printf("�@");
				break;
			case 1:
				//�u���b�N
				printf("��");
				break;
			case 2:
				printf("�~");
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
	printf("%d", fall);

}

void Field::update()
{
	bool underChecker = false;

	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			if (block[y][x] != 0) {
				if (stage[y + fall + 1][x + side] != 0) {
					underChecker = true;
				}
			}
		}
	}

	if (underChecker) {
		for (int i = 0; i < FIELD_HEIGHT; i++) {
			for (int j = 0; j < FIELD_WIDTH; j++) {
				//�t�B�[���h�̏�Ԃ��ꎞ�ۑ��z��֊i�[
				stage[i][j] = field[i][j];
			}
		}
		blockSelecter();
	}
}

void Field::clearField()
{
	for (int y = 0; y < FIELD_HEIGHT; y++) {
		for (int x = 0; x < FIELD_WIDTH; x++) {
			field[y][x] = 0;
		}
	}
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

	//�u���b�N�ʒu������
	fall = 0;
	side = 4;
}

void Field::lineChecker()
{
	//�󔒂�������1��u���b�N�Ŗ��܂��Ă���΁A���̍s������
	int spaceValue = 0;

	for (int y = 0; y < FIELD_HEIGHT - 1; y++) {
		for (int x = 1; x < FIELD_WIDTH - 1; x++) {
			if (field[y][x] == 0) {
				spaceValue++;
			}
		}
		if (spaceValue == 0) {
			score += 10;
			for (int i = 1; i < FIELD_WIDTH - 1; i++) {
				field[y][i] = 0;
			}
			for (int i = y; i > 0; i--) {
				for (int j = 0; j < FIELD_WIDTH; j++) {
					field[i][j] = field[i - 1][j];
				}
			}
		}
		spaceValue = 0;
	}
}

bool Field::isGameOver()
{
	for (int y = 0; y < FIELD_HEIGHT; y++) {
		for (int x = 0; x < FIELD_WIDTH; x++) {
			if (field[y][x] == 2) {
				printf("GameOver!\n");
				return true;
			}
		}
	}
	return false;
}

void Field::gameTimer()
{
	counter++;
	if (counter >= sleepTime)
	{
		fall++;
		counter = 0;
	}
}

void Field::moveBlockLeft()
{
	bool sideWall = false;

	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			if (block[y][x] != 0) {
				if (stage[y + fall][x + side - 1] != 0) {
					sideWall = true;
				}
			}
		}
	}
	if (!sideWall) {
		side--;
	}
}

void Field::moveBlockRight()
{
	bool sideWall = false;

	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			if (block[y][x] != 0) {
				if (stage[y + fall][x + side + 1] != 0) {
					sideWall = true;
				}
			}
		}
	}
	if (!sideWall) {
		side++;
	}
}

void Field::turnLeftBlock()
{
	int newBlock[4][4];
	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			newBlock[y][x] = block[3 - x][y];
		}
	}
	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			block[y][x] = newBlock[y][x];
		}
	}
}

void Field::turnRightBlock()
{
	int newBlock[4][4];
	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			newBlock[y][x] = block[x][3 - y];
		}
	}
	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			block[y][x] = newBlock[y][x];
		}
	}
}

void Field::setKeys()
{
	if (GetAsyncKeyState(VK_LEFT)) {
		moveBlockLeft();
	}
	else if (GetAsyncKeyState(VK_RIGHT)) {
		moveBlockRight();
	}
	else if (GetAsyncKeyState(VK_DOWN)) {
		fall++;
		counter = 0;
	}
	else if(GetAsyncKeyState('Z')){
		turnLeftBlock();
	}
	else if (GetAsyncKeyState('X')) {
		turnRightBlock();
	}
}
