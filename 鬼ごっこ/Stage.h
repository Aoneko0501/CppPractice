#pragma once

#include"Object.h"

const char gStageData[] = "\
##########\n\
#        #\n\
# @   D  #\n\
#        #\n\
#   p @  #\n\
#        #\n\
##########";

const int gStageWidth = 10;
const int gStageHeight = 7;

class Stage {
	int place = 0;
	//#壁　pプレイヤ　D敵　@障害物


public:
	Stage(Object* state, int w, int h, const char* stageData);
	~Stage();
	//プレイヤーの座標を返す(つもり)
	int isPlayer(Object* state);
	int isDragon(Object* state);
	void draw(Object* state, int w, int h);
	void update(Object* stage, char input,int w, int h);
	bool checkClear(const Object* stage, int w, int h);//クリアチェッカー
};