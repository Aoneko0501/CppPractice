#pragma once

#include<iostream>

class Stage {
	int place = 0;
public:
	Stage();
	~Stage();
	//プレイヤーの座標を返す(つもり)
	int isPlayer();
};