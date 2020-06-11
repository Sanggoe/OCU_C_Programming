/* 200606 파일 입출력을 활용하여 txt파일을 10줄을 한 줄씩 줄 단위로 읽어
포인터 배열에 저장한 다음, 읽어온 문자열을 차례로 출력하는 프로그램
Program made by Park SangMin */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LINE 10

// extern 키워드를 이용해 다른 소스파일의 전역변수를 참조하여 이용
extern char* line;
extern void (*func[2]) (char*); // 함수 포인터 배열 활용

// sample에 저장된 문자열을 출력하고, 동적으로 할당 했던 메모리를 반환하는 함수
void printAndFree(char** sample) {
	func[0](sample); 
	func[1](sample);
}

int main(void) {
	FILE* fp = NULL;
	char* sample[10];

	fp = fopen("sample.txt", "r");	// sample.txt 이름의 파일을 읽기 전용으로 열고 파일 포인터를 반환한다.

	if (fp == NULL) {	// 파일 open 실패 시
		printf("파일 열기 실패\n");
		exit(1);
	}
	else {	// 파일 open 성공 시
		printf("파일 열기 성공\n");

		for (int i = 0; i < LINE; i++) {
			// 동적 메모리 할당 및 파일에서 문자열 한 줄 읽어와 저장한 주소를 반환하는 사용자 지정 함수
			sample[i] = readLine(line, fp);
		}

		// 읽어와 저장한 문자열 출력 및 동적으로 할당한 해당 메모리를 반환하는 사용자 지정 함수
		printAndFree(sample);
	}
	fclose(fp); // 파일 닫기 (파일 포인터 반환)

	return 0;
}