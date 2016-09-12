#pragma once
class Player {
	enum State;
private:
	float x, y;//���W
	float vecX, vecY;//�ړ����x
	float jumpSpeed;
	int width, height;//�摜�T�C�Y
	int gh;//�摜�i�[�p�n���h��

	float g;

	bool live;//�����Ă��邩�ǂ���
	bool oldJump;
	bool newJump;

	State state;//���
	int jump;
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
	bool isLive();


	//�ړ�
	bool Draw();
	bool Move();
	void Jump();

	//�n�ʂɂ��邩�ǂ����H
	bool onGround();
	//��ʒ[���H
	bool WallChecker();
};
