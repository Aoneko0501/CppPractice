#pragma once
class Field {
public:
	Field() {
		init();
	};
	~Field() {};

	//������
	void init();

	//�ǂ��ǂ���
	//�ǁFtrue�@����ȊO�Ffalse
	bool isWall(int x, int y);

	//�`��
	void draw();

	//�X�V
	void update();

	//�u���b�N�I��
	void blockSelecter();

	//��������
	void lineChecker();

	//�u���b�N����ɋl�݂����������ǂ���
	bool isGameOver();

	//�^�C�}�[
	void gameTimer();
};