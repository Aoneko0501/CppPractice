#pragma once
#include"Controller.h"

#define BLOCK_HEIGHT 4
#define BLOCK_WIDTH 4

#define FIELD_HEIGHT 21
#define FIELD_WIDTH 12

//�u���b�N�̃f�[�^
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
	//���݃A�N�e�B�u�ȃu���b�N
	int block[BLOCK_HEIGHT][BLOCK_WIDTH];
	//���݂̃t�B�[���h�̏��
	int stage[FIELD_HEIGHT][FIELD_WIDTH];
	//��{�̃t�B�[���h�̏��
	int field[FIELD_HEIGHT][FIELD_WIDTH];

public:
	//�R���g���X�^��p���ď������������s��
	Field() {
		init();
	}
	~Field(){}

	//����������
	void init();

	//��ʕ`��
	void draw();

	//��ʍX�V
	void update(Controller c);

	//�u���b�N����񂻂���Ă��邩����
	bool lineCheck();

	//�u���b�N����ԏ�܂Őς݂������Ă��邩�ǂ���
	//true=�l��:false=�܂��Z�[�t
	bool isGameOver();

};