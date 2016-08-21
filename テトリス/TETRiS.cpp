#include<stdio.h>
#include"Field.h"

int main() {
	Field field;

	field.blockSelecter();
	while (field.isGameOver()) {
		field.draw();
		field.lineChecker();
		field.gameTimer();
		printf("\n");
		field.update();
	}
	return 0;
}