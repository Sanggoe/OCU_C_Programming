/* 200425 배열을 이용해 반 학생들의 점수를 초기화 한 후,
상대평가 방식으로 성적을 매긴 후 출력하는 프로그램
Program made by Park SangMin*/

#include <stdio.h>
#include <stdlib.h> // rand() 함수를 사용하기 위한 standard library 헤더파일
#define STUDENTS 100	// 학생 수를 매크로 상수로 정의

// 학생들의 점수를 배열에 입력받는 함수
void giveStudentsScore(int scores[]) {
	for (int i = 0; i < STUDENTS; i++) {
		scores[i] = rand() % 100 + 1;
	}
}

// 학생들의 점수를 내림차순으로 정렬하는 함수
void sortStudentsScore(int scores[]) {
	int temp, i, j;

	for (i = 0; i < STUDENTS; i++) {
		for (j = 0; j < STUDENTS - 1 - i; j++) {
			if (scores[j] < scores[j + 1]) {
				temp = scores[j];
				scores[j] = scores[j + 1];
				scores[j + 1] = temp;
			}
		}
	}
}

// 학생들의 점수에 학점을 부여하는 함수
void giveStudentsGrades(int scores[], char grades[]) {
	_Bool isSameValue = 0;
	char gradeList[5] = { 'A', 'B', 'C', 'D', 'F' };
	int i;

	for (i = 0; i < 10; i++) {
		grades[i] = gradeList[0];
	}

	if (grades[9] == grades[10]) {
		isSameValue = 1;
		while (isSameValue) {
			grades[i++] = gradeList[0];
			if (grades[i-1] == grades[i]) {
				isSameValue = 0;
			}
		}
	}

	for (; i < 25; i++) {
		grades[i] = gradeList[1];
	}
	if (grades[24] == grades[25]) {
		isSameValue = 1;
		while (isSameValue) {
			grades[i++] = gradeList[0];
			if (grades[i - 1] == grades[i]) {
				isSameValue = 0;
			}
		}
	}



	for (; i < STUDENTS; i++) {
		if (i <= 10) {
			grades[i] = gradeList[0];
			if (grades[9] == grades[10]) {
				isSameValue = 1;
			}
		}
		else if (i > 10) {
			if (isSameValue) {

			}
			grades[i] = gradeList[1];
		}
		else if (i > 25) {
			grades[i] = gradeList[2];
		}
		else if (i > 50) {
			grades[i] = gradeList[3];
		}
		else if (i > 80) {
			grades[i] = gradeList[4];
		}

	}
}

// 학생들의 점수를 출력하는 함수
void showStudentScore(int scores[], char grades[]) {
	for (int i = 0; i < STUDENTS; i++) {
		if (i % 5 == 0) {
			printf("\n");
		}
		printf("[%3d등, %c, %3d점]  ", i + 1, grades[i], scores[i]);
	}
	printf("\n");
}

int main(void) {
	int scores[100];
	char grades[100];

	giveStudentsScore(scores);
	sortStudentsScore(scores);
	giveStudentsGrades(scores, grades);
	showStudentsScore(scores, grades);

	return 0;
}