/* 200425 배열을 이용해 반 학생들의 점수를 초기화 한 후,
상대평가 방식으로 성적을 매긴 후 출력하는 프로그램
Program made by Park SangMin*/

#include <stdio.h>
#include <stdlib.h> // rand() 함수를 사용하기 위한 standard library 헤더파일
#include <time.h> // srand() 함수를 사용하기 위한 time 헤더파일
#define STUDENTS 100	// 학생 수를 매크로 상수로 정의

// 학생들의 점수를 배열에 입력받는 함수
void giveStudentsScore(int scores[]) {
	for (int i = 0; i < STUDENTS; i++) {
		scores[i] = rand() % 101;
		// 100으로 나눈 나머지 + 1 해줌으로, 랜덤 부여 점수는 1~100점 사이
	}
}

// 학생들의 점수를 내림차순으로 정렬하는 함수
void sortStudentsScore(int scores[]) {
	int temp, i, j;

	// 버블 정렬을 이용한 정렬
	for (i = 0; i < STUDENTS; i++) {
		for (j = 0; j < STUDENTS - 1 - i; j++) {
			if (scores[j] < scores[j + 1]) { // 앞의 원소가 뒤의 원소보다 작으면
				// swap 수행해 작은 수를 뒤로 보냄
				temp = scores[j];
				scores[j] = scores[j + 1];
				scores[j + 1] = temp;
			}
		}
	}
}

// 학생들의 점수에 학점을 부여하는 함수
void giveStudentsGrades(int scores[3][100]) {
	_Bool isSameValue = 0; // 점수가 같은지 체크하는 변수
	_Bool isNextGrade = 0; // 학점이 바뀌는 등수인지 체크하는 변수
	int gradeList[5] = { 'A', 'B', 'C', 'D', 'F' }; // 부여할 학점 배열
	int i = 1, j = 0;

	// 첫 번째 인덱스의 값은 초기화
	scores[0][0] = 1;
	scores[1][0] = 'A';

	for (; i < STUDENTS; i++) { // 학생 수만큼 반복
		if (i == 10 || i == 25 || i == 50 || i == 80) { // A,B,C,D,F 학점이 바뀌는 등수일 경우
			isNextGrade = 1; // 부여 학점이 낮아질 것을 체크
		}

		if (scores[2][i - 1] == scores[2][i]) { // 앞 등수와 점수가 같으면
			isSameValue = 1; // 점수가 같다고 체크
			while (isSameValue) { // 다음 등수와 동점이 아닐 때 까지
				
				scores[0][i] = scores[0][i - 1]; // 같은 석차 기입
				scores[1][i] = scores[1][i - 1]; // 같은 학점 기입
				i++;

				if (i == 10 || i == 25 || i == 50 || i == 80) { // A,B,C,D,F 학점이 바뀌는 등수일 경우
					isNextGrade = 1; // 바뀔 등수라는 것을 체크
				}

				if (scores[2][i - 1] != scores[2][i]) { // 다음 등수와 점수가 다르면
					isSameValue = 0; // while문 탈출 조건
				}
			}
		}
		
		if (isNextGrade) { // 학점이 바뀔 등수였으면
			j++; // 학점 index Down
			isNextGrade = 0;
		}

		scores[0][i] = (i + 1);
		scores[1][i] = gradeList[j]; // 학점 기입
	}
}

// 학생들의 점수를 출력하는 함수
void showStudentsScore(int scores[][100]) {
	for (int i = 0; i < STUDENTS; i++) {
		if (i % 5 == 0) {
			printf("\n");
		}
		printf("[%3d등, %c, %3d점]  ", scores[0][i], scores[1][i], scores[2][i]);
	} // scores 배열의 첫행인 등수, 둘째 행인 학점, 셋째 행인 점수를 출력
	printf("\n");
}

int main(void) {
	int scores[3][100];
	srand(time(NULL));

	giveStudentsScore(scores[2]);
	sortStudentsScore(scores[2]);
	giveStudentsGrades(scores);
	showStudentsScore(scores);

	return 0;
}