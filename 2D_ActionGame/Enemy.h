#pragma once
class Enemy {
	float x, y;
	float vecX, vecY;
	int width, height;

	int gh;

	bool live;

	//�|�����Ƃ��̓��_
	int point;
	//�ړ��������
	bool vec;

private:
	void Move();
	void Draw();

public:
	Enemy() {};
	Enemy(float x, float y,bool vec);//x���W�Ay���W,�����ʒu�ł̌���(true = �E,false = ��)

	void All();
};