#include<stdio.h>
#include<Windows.h>
#include"Field.h"

int main() {
	Field field;
	bool isGameEnd = false;
	long long int c = 0;

	while (!isGameEnd) {
		if ((c % 3000000) == 0) {
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
		c++;
	}
	return 0;
}