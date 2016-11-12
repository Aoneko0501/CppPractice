/*
#include<stdio.h>

void main()
{
	// ファイルポインタを宣言
	FILE *fp;

	fp = fopen("Save.txt", "w");
	if (fp == NULL) {
		printf("FILE OPEN ERROR\n");
		return;
	}

	printf("FILE OPEN!!\n");

	if (fclose(fp) == EOF) {

		printf("FILE CLOSE ERROR!\n");
		return;
	}

	printf("FILE CLOSE!\n");
}
*/