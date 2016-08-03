#include<stdio.h>
#include"BLOCK.h"
#include"Controller.h"
#include"Field.h"

int main() {
	Field *field = new Field();

	while (!field->isGameOver()) {

	}

	delete field;
	return 0;
}