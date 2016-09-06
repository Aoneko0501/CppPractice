#pragma once
class Player {
private:
	float x, y;//���W
	float vecX, vecY;//�ړ����x
	int width, height;//�摜�T�C�Y
	int gh;//�摜�i�[�p�n���h��

	bool live;//�����Ă��邩�ǂ���
public:
	//�����ݒ�
	Player();
	~Player();

	//�e�p�����[�^�Z�b�g�֐�
	void SetX(float x);
	void SetY(float y);
	void SetGh(int gh);
	void SetVecX(float vx);
	void SetVecY(float vy);


	//�e�p�����[�^�l�擾�֐�
	float GetX();
	float GetY();
	int GetGh();
	float GetVecX();
	float GetVecY();
	int GetWidth();
	int GetHeight();

	//�ړ�
	void Draw();
	bool Move();
	void Jump();
};