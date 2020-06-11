#include <stdio.h>
#include <stdlib.h>
#define SIZE 200
#define LINE 10

char* line; // 전역변수 선언
char* readLine(char*, FILE*);
void show(char**);
void freeMemory(char**);
void (*func[2]) (char**) = {show, freeMemory}; // 함수의 시작주소를 담는 포인터 배열이다.

// line에 동적 메모리 할당 후, 파일로부터 문자열을 한 줄 읽어 저장한 주소를 반환하는 함수
char* readLine(char* line, FILE* fp) {
	line = (char*)malloc(SIZE * sizeof(char));	// (char형 * 200)크기의 메모리를 char형 포인터 형식으로 할당

	if (line != NULL) {			// memory allocate가 성공했을 경우
		fgets(line, SIZE, fp);	// 파일에서 문자열 한 줄(최대 크기 200)을 읽어 line에 저장
		return line;
	}
	else {
		printf("malloc 실패!");
		exit(1);	// 프로그램 종료
	}
}

void show(char** sample) {
	for (int i = 0; i < LINE; i++) {
		printf("%s", sample[i]);
	}
}

void freeMemory(char** sample) {
	for (int i = 0; i < LINE; ++i) {
		free(sample[i]);	// 반환
	}
}
