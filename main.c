/* 200606 ���� ������� Ȱ���Ͽ� txt������ 10���� �� �پ� �� ������ �о�
������ �迭�� ������ ����, �о�� ���ڿ��� ���ʷ� ����ϴ� ���α׷�
Program made by Park SangMin */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LINE 10

// extern Ű���带 �̿��� �ٸ� �ҽ������� ���������� �����Ͽ� �̿�
extern char* line;
extern void (*func[2]) (char*); // �Լ� ������ �迭 Ȱ��

// sample�� ����� ���ڿ��� ����ϰ�, �������� �Ҵ� �ߴ� �޸𸮸� ��ȯ�ϴ� �Լ�
void printAndFree(char** sample) {
	func[0](sample); 
	func[1](sample);
}

int main(void) {
	FILE* fp = NULL;
	char* sample[10];

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

		// �о�� ������ ���ڿ� ��� �� �������� �Ҵ��� �ش� �޸𸮸� ��ȯ�ϴ� ����� ���� �Լ�
		printAndFree(sample);
	}
	fclose(fp); // ���� �ݱ� (���� ������ ��ȯ)

	return 0;
}