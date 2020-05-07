/* 200410 학생들의 성적 세 가지를 입력 받아
합계 및 백분율, 점수를 구하는 프로그램
Program made by Park SangMin*/

#include <stdio.h>

int main() {
	int testScore;			// 시험 성적입력받을 변수
	int homeworkScore;	// 과제 성적 입력받을 변수
	int attendanceScore;	// 출석 성적 입력받을 변수
	int totalScore;			// 합계값을 계산해 담을 변수
	const int NUM = 10;	// 반복할 횟수인 10을 상수로 선언
	const int ERROR = 3;	// 오류의 최대횟수인 3을 상수로 선언
	double persentage;	// 백분율을 계산해 담을 변수
	int persentInt;			// 백분율을 반올림해 담을 변수

	// 제어변수 i의 초기값은 0, NUM보다 작을 때 까지 i를 증가시키는 연산을 반복한다.
	for (int i = 0; i < NUM; i++) {
		int error = 0;		// 에러 제어를 위한 임시 변수

		while (1) {			// 항상 조건이 1로 참 이므로, 반복
			printf("시험 성적: ");
			scanf_s("%d", &testScore);
			printf("과제 성적: ");
			scanf_s("%d", &homeworkScore);
			printf("출석 성적: ");
			scanf_s("%d", &attendanceScore);

			// 시험성적이 0~100 사이, 과제 성적이 0~50사이, 출석 성적이 0~45 사이를 만족할 때
			if ((testScore >= 0 && testScore <= 100) && (homeworkScore >= 0 &&
				homeworkScore <= 50) && (attendanceScore >= 0 && attendanceScore <= 45)) {
				printf("학점: %d 과제: %d 출석: %d\n", testScore, homeworkScore, attendanceScore);
				break; // while문을 탈출합니다.
			}
			else {
				printf("시험성적은 0~100, 과제성적은 0~50, 출석 성적은 0~45 사이의 정수로 입력하세요!\n\n");
				if (++error == ERROR) { // 매번 에러 횟수를 증가시키고, 3번째 에러일 때
					printf("입력된 값 오류로 프로그램 종료함\n");
					return 0;	// 메시지 출력 후 프로그램을 종료
				}
			}
		}

		if (attendanceScore < 30) {
			printf("F 학점입니다.\n\n");
		}
		else {
			totalScore = testScore + homeworkScore + attendanceScore;	// 세 성적 합계를 구함
			persentage = totalScore / 195.0 * 100;	// totalScore : persentage = 195 : 100이므로

			/* 백분율을 소수점 첫째자리에서 반올림하여 0.5이상은 1을 더해서 int형으로 변환,
			0.5미만은 바로 int형으로 변환하여 정수형 persentInt 변수에 넣어준다. */
			persentInt = (int)(persentage * 10) % 10 < 5 ? (int)persentage : (int)(persentage + 1);
			printf("퍼센트 : %d\n", persentInt);

			if (persentInt <= 40) {
				printf("F 학점입니다.\n\n");	// 백분율이 40%이하인 경우 F학점
			}
			else if (persentInt > 40 && persentInt <= 50) {
				printf("C 학점입니다.\n\n");	// 백분율이 41%~50%인 경우 C학점 
			}
			else if (persentInt > 50 && persentInt <= 60) {
				printf("C+ 학점입니다.\n\n");	// 백분율이 51%~60%인 경우 C+학점 
			}
			else if (persentInt > 60 && persentInt <= 70) {
				printf("B 학점입니다.\n\n");	// 백분율이 61%~70%인 경우 B학점 
			}
			else if (persentInt > 70 && persentInt <= 80) {
				printf("B+ 학점입니다.\n\n");	// 백분율이 71%~80%인 경우 B+학점 
			}
			else if (persentInt > 80 && persentInt <= 90) {
				printf("A 학점입니다.\n\n");	// 백분율이 81%~90%인 경우 A학점 
			}
			else if (persentInt > 90) {		// 백분율이 91%이상인 경우 A+학점
				printf("A+ 학점입니다.\n\n");
			}
		}
	}
}