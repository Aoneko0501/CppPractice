/*
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	FILE *fp;

	// �t�@�C���I�[�v��
	if ((fp = fopen("Save.txt", "r")) == NULL) {
		printf("FILE OPEN ERROR\n");
		return 1;
	}

	printf("FILE OPEN!\n");

	char string[64] = "";

	// �t�@�C�����當�����ǂݍ���
	fscanf(fp,"%s",string);

	// �ǂݍ��񂾕������\��
	printf("%s\n", string);

	// �t�@�C���N���[�Y
	if (fclose(fp) == EOF) {
		printf("FILE OPEN ERROR\n");
		return 1;
	}

	printf("FILE CLOSE\n");

	return 0;
}

*/