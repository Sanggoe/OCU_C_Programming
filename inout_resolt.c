/* 200312 scanf, printf 함수를 이용해 정수를 입력받아
환산하여 출력하는 프로그램 Program made by Park.s.m*/

#include<stdio.h>
// standard input output, 표준 입출력 헤더파일

int main(void) {
	int volume_ml;
	double volume_L;

	// 키보드로부터 정수를 입력받아 ml 단위를 변수에 입력
	scanf_s("%d", &volume_ml);

	volume_L = volume_ml * 0.001; // ml을 L로 단위 환산 후 저장

	// 1L == 1000ml 임을 고려, L는 소수점 3째자리까지 출력
	printf("%d ml = %.3lf l\n", volume_ml, volume_L);

	return 0;
}