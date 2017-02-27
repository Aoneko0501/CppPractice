#include "GameInfo.h"

// ƒL[“ü—Í”»’è
int key[256]; // 0:“ü—Í‚³‚ê‚Ä‚¢‚È‚¢, 1:“ü—Í‚³‚ê‚½uŠÔ, 2:“ü—Í‚³‚ê‚Ä‚¢‚é
void InputKey()
{
	static char buf[256];
	GetHitKeyStateAll(buf);
	for (int i = 0; i < 256; i++) {
		if (buf[i]) {
			if (key[i] == 0)key[i] = 1;
			else if (key[i] == 1) key[i] = 2;
		}
		else key[i] = 0;
	}
}


