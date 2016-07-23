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
	//#�ǁ@p�v���C���@D�G�@@��Q��


public:
	Stage(Object* state, int w, int h, const char* stageData);
	~Stage();
	//�v���C���[�̍��W��Ԃ�(����)
	int isPlayer(Object* state);
	int isDragon(Object* state);
	void draw(Object* state, int w, int h);
	void update(Object* stage, char input,int w, int h);
	bool checkClear(const Object* stage, int w, int h);//�N���A�`�F�b�J�[
};