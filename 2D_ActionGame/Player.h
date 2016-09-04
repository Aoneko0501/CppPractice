#pragma once
class Player {
private:
	float x, y;//座標
	float vecX, vecY;//移動速度
	int width, height;//画像サイズ
	int gh;//画像格納用ハンドル
public:
	//初期設定
	Player();
	~Player();

	//各パラメータセット関数
	void SetX(float x);
	void SetY(float y);
	void SetGh(int gh);
	void SetVecX(float vx);
	void SetVecY(float vy);
	void SetWidth(int w);
	void SetHeight(int h);

	//各パラメータ値取得関数
	float GetX();
	float GetY();
	int GetGh();
	float GetVecX();
	float GetVecY();
	int GetWidth();
	int GetHeight();

};
