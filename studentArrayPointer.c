/* 200508 배열을 이용해 반 학생들의 점수를 초기화 한 후,
상대평가 방식으로 성적을 매긴 후 출력하는 프로그램
단, 배열을 매개변수로 넘기거나 접근할 때 포인터로 접근해야 함
Program made by Park SangMin */

#include <stdio.h>
#include <stdlib.h> // rand() 함수를 사용하기 위한 standard library 헤더파일
#include <time.h> // srand() 함수를 사용하기 위한 time 헤더파일
#define STUDENTS 100	// 학생 수를 매크로 상수로 정의

// 학생들의 점수를 배열에 입력받는 함수
void giveStudentsScore(int* scores) {
	for (int i = 0; i < STUDENTS; i++) {
		*(scores + i) = rand() % 101;
		// 100으로 나눈 나머지 + 1 해줌으로, 랜덤 부여 점수는 1~100점 사이
	}
}

// 학생들의 점수를 내림차순으로 정렬하는 함수
void sortStudentsScore(int* scores) {
	int temp, i, j;

	// 버블 정렬을 이용한 정렬
	for (i = 0; i < STUDENTS; i++) {
		for (j = 0; j < STUDENTS - 1 - i; j++) {
			if (*(scores + j) < *(scores + j + 1)) { // 앞의 원소가 뒤의 원소보다 작으면
				// swap 수행해 작은 수를 뒤로 보냄
				temp = *(scores + j);
				*(scores + j) = *(scores + j + 1);
				*(scores + j + 1) = temp;
			}
		}
	}
}

// 학생들의 점수를 출력하는 함수
void showStudentsScore(int* scores) {
	_Bool isSameValue = 0; // 점수가 같은지 체크하는 변수
	_Bool isNextGrade = 0; // 학점이 바뀌는 등수인지 체크하는 변수
	int gradeList[5] = { 'A', 'B', 'C', 'D', 'F' }; // 부여할 학점 배열
	int temp, j = 0;

	for (int i = 0; i < STUDENTS; i++) {
		if (i == 10 || i == 25 || i == 50 || i == 80) { // A,B,C,D,F 학점이 바뀌는 등수일 경우
			isNextGrade = 1; // 부여 학점이 낮아질 것을 체크
		}

		if (*(scores + i - 1) == *(scores + i)) { // 앞 등수와 점수가 같으면
			isSameValue = 1; // 점수가 같다고 체크
			temp = i; // 등수 임시 저장
			while (isSameValue) { // 다음 등수와 동점이 아닐 때 까지
				if (i % 5 == 0) {
					printf("\n");
				}
				printf("[%3d등, %3d점, %c]  ", temp, *(scores + i), *(gradeList + j) ); // 같은 석차 출력
				i++;

				if (i == 10 || i == 25 || i == 50 || i == 80) { // A,B,C,D,F 학점이 바뀌는 등수일 경우
					isNextGrade = 1; // 바뀔 등수라는 것을 체크
				}

				if (*(scores + i - 1) != *(scores + i)) { // 다음 등수와 점수가 다르면
					isSameValue = 0; // while문 탈출 조건
				}
			}
		}

		if (isNextGrade) { // 학점이 바뀔 등수였으면
			j++; // 학점 Down grade
			isNextGrade = 0;
		}

		if (i % 5 == 0) {
			printf("\n");
		}
		printf("[%3d등, %3d점, %c]  ", i + 1, *(scores + i), *(gradeList + j));

	} // scores 배열의 첫행인 등수, 둘째 행인 학점, 셋째 행인 점수를 출력
	printf("\n");
}

int main(void) {
	int scores[100];
	srand((unsigned)time(NULL));

	giveStudentsScore(scores);
	sortStudentsScore(scores);
	showStudentsScore(scores);

	return 0;
}