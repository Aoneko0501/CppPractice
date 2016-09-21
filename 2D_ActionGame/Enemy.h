#pragma once
class Enemy {
	float x, y;
	float vecX, vecY;
	int width, height;

	int gh;

	bool live;

	//倒したときの得点
	int point;
	//移動する向き
	bool vec;

private:
	void Move();
	void Draw();

public:
	Enemy() {};
	Enemy(float x, float y,bool vec);//x座標、y座標,初期位置での向き(true = 右,false = 左)

	void All();
};