#pragma once
class Player {
	enum State;
private:
	float x, y;//座標
	float vecX, vecY;//移動速度
	float jumpSpeed;
	int width, height;//画像サイズ
	int gh;//画像格納用ハンドル

	float g;

	bool live;//生きているかどうか
	bool oldJump;
	bool newJump;

	State state;//状態
	int jump;
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


	//各パラメータ値取得関数
	float GetX();
	float GetY();
	int GetGh();
	float GetVecX();
	float GetVecY();
	int GetWidth();
	int GetHeight();
	bool isLive();


	//移動
	bool Draw();
	bool Move();
	void Jump();

	//地面にいるかどうか？
	bool onGround();
	//画面端か？
	bool WallChecker();
};
