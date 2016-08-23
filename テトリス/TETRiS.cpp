#include<stdio.h>
#include<Windows.h>
#include"Field.h"

int main() {
	Field field;
	bool isGameEnd = false;

	while (!isGameEnd) {

		field.draw();
		printf("\n");
		
		field.lineChecker();

		isGameEnd = field.isGameOver();
		field.lineChecker();
		field.update();
		field.setKeys();
		field.clearField();
		field.gameTimer();
	}
	return 0;
}