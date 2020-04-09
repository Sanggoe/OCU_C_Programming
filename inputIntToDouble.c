/* 200316 키보드로 실수를 입력받아 실수형 변수에 저장 후,
정수형 변수에 대입 후 출력하는 프로그램 Program made by Park SangMin*/

#include <stdio.h> // include standard input output header file.

int main(void) {
	double d_value;	// 실수를 담을 double형 변수 선언
	int i_value;		// 정수를 담을 int형 변수 선언

	scanf_s("%lf", &d_value); // d_value의 주소를 참조, 형식제어자 %lf로 실수를 입력받음

	// Warning! double형 -> int형 변환시 데이터가 손실될 수 있습니다.
	i_value = d_value; // int형 변수에 double형 변수의 값을 (int)로 강제 형변환 시켜 대입

	// Warning! %lf에는 double형식의 인수가 필요하지만, int형식 인수가 왔습니다.
	/* printf("double형: %lf, int형: %lf", d_value, i_value); */

	printf("double형: %lf, int형: %d", d_value, i_value);
}