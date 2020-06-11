#include <stdio.h>
#include <stdlib.h>
#define SIZE 200
#define LINE 10

char* line; // �������� ����
char* readLine(char*, FILE*);
void show(char**);
void freeMemory(char**);
void (*func[2]) (char**) = {show, freeMemory}; // �Լ��� �����ּҸ� ��� ������ �迭�̴�.

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

void show(char** sample) {
	for (int i = 0; i < LINE; i++) {
		printf("%s", sample[i]);
	}
}

void freeMemory(char** sample) {
	for (int i = 0; i < LINE; ++i) {
		free(sample[i]);	// ��ȯ
	}
}
