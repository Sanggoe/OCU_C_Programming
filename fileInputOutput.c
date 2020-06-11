/* 200528 ���� ������� Ȱ���Ͽ� txt������ 10���� �� �پ� �� ������ �о�
������ �迭�� ������ ����, �о�� ���ڿ��� ���ʷ� ����ϴ� ���α׷�
Program made by Park SangMin */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 200
#define LINE 10

// line�� ���� �޸� �Ҵ� ��, ���Ϸκ��� ���ڿ��� �� �� �о� ������ �ּҸ� ��ȯ�ϴ� �Լ�
char* readLine(char* line, FILE* fp) {
	line = (char*)malloc(SIZE * sizeof(char));	// (char�� * 200)ũ���� �޸𸮸� char�� ������ �������� �Ҵ�

	if (line != NULL) {			// memory allocate�� �������� ���
		fgets(line, SIZE, fp);	// ���Ͽ��� ���ڿ� �� ��(�ִ� ũ�� 200)�� �о� line�� ����
		return line;
	}
	else {
		printf("malloc ����!");
		exit(1);	// ���α׷� ����
	}
}

// sample�� ����� ���ڿ��� ����ϰ�, �������� �Ҵ� �ߴ� �޸𸮸� ��ȯ�ϴ� �Լ�
void printAndFree(char* sample) {
	printf("%s", sample);
	free(sample);	// ��ȯ
}

int main(void) {
	FILE* fp = NULL;
	char* sample[10];
	char* line = NULL;

	fp = fopen("sample.txt", "r");	// sample.txt �̸��� ������ �б� �������� ���� ���� �����͸� ��ȯ�Ѵ�.

	if (fp == NULL) {	// ���� open ���� ��
		printf("���� ���� ����\n");
		exit(1);
	}
	else {	// ���� open ���� ��
		printf("���� ���� ����\n");

		for (int i = 0; i < LINE; i++) {
			// ���� �޸� �Ҵ� �� ���Ͽ��� ���ڿ� �� �� �о�� ������ �ּҸ� ��ȯ�ϴ� ����� ���� �Լ�
			sample[i] = readLine(line, fp);
		}

		for (int i = 0; i < LINE; i++) {
			// �о�� ������ ���ڿ� ��� �� �������� �Ҵ��� �ش� �޸𸮸� ��ȯ�ϴ� ����� ���� �Լ�
			printAndFree(sample[i]);
		}
	}
	fclose(fp); // ���� �ݱ� (���� ������ ��ȯ)

	return 0;
}