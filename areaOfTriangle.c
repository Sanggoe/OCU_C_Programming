/* 200325 키보드로 실수를 입력받아 실수형 변수에 저장한 후,
그 수를 한 변으로 하는 정삼각형의 넓이를 구해 출력하는 프로그램
Program made by Park SangMin*/

#include <stdio.h>
#include <math.h> // 수학식과 관련된 함수를 제공하는 헤더파일

int main(void) {
	double length;		// 키보드로 입력 받을 정삼각형의 한 변의 길이를 담을 변수
	double height;		// 정삼각형의 높이를 구해 담을 변수
	double heightMult;	// 높이의 제곱을 담을 변수
	double area;			// 정삼각형의 넓이를 구해 담을 변수

	printf("정삼각형의 한 변의 길이(실수)를 입력하세요. : ");	// 안내 문구 출력하는 함수
	scanf_s("%lf", &length);		// 키보드로 실수를 입력받아 정삼각형 한 변의 길이를 저장

	heightMult = pow(length, 2) - pow(length / 2, 2); // 피타고라스 정리를 이용해 (높이 제곱)값을 구하는 식
																// 밑변과 빗변의 제곱 값을 각각 pow함수로 계산
	height = sqrt(heightMult);	// (높이제곱)의 제곱근 값을 sqrt함수를 이용해 계산

	area = height * length / 2;	// 정삼각형의 넓이를 구하는 공식, 계산 값

	// 각각 소수점 둘째 자리까지 출력
	printf("한 변의 길이 : %.2lf\n", length);
	printf("정삼각형의 높이 : %.2lf\n", height);
	printf("정삼각형의 넓이 : %.2lf\n", area);
}
