/*
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	FILE *fp;

	// ファイルオープン
	if ((fp = fopen("Save.txt", "r")) == NULL) {
		printf("FILE OPEN ERROR\n");
		return 1;
	}

	printf("FILE OPEN!\n");

	char string[64] = "";

	// ファイルから文字列を読み込む
	fscanf(fp,"%s",string);

	// 読み込んだ文字列を表示
	printf("%s\n", string);

	// ファイルクローズ
	if (fclose(fp) == EOF) {
		printf("FILE OPEN ERROR\n");
		return 1;
	}

	printf("FILE CLOSE\n");

	return 0;
}

*/