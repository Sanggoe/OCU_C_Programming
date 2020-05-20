/* 200521 3차원 평면의 좌표를 구조체로 표현하고,
랜덤으로 입력받은 두 점의 좌표를 잇는 선을 대각선
으로 하는 정육면체의 부피를 구하는 프로그램
Program made by Park SangMin */

#include <stdio.h>
#include <math.h>
#include <time.h>

// POINT로 type을 정의해준 구조체 point
typedef struct point {
	int x, y, z;
} POINT;

// CUBE로 type을 정의해준 구조체 cube
typedef struct cube {
	POINT* point1;	// point 구조체의 포인터를 변수로 가진다.
	POINT* point2;
} CUBE;

// POINT 구조체를 포인터로 받아 직접 각 멤버의 해당 주소에 랜덤값을 넣어주는 함수
void getPoint(POINT* dotPoint) {
	dotPoint->x = rand() % 10 + 1;	// 구조체 포인터 형식에서 멤버에 접근할 때 ->를 사용한다.
	dotPoint->y = rand() % 10 + 1;
	dotPoint->z = rand() % 10 + 1;
}

// 두 점의 값을 비교하여 같은 위치이면 1, 아니면 0을 반환하는 함수
_Bool isSameDot(POINT* dotPoint1, POINT* dotPoint2) {
	if (dotPoint1->x == dotPoint2->x && dotPoint1->y == dotPoint2->y && dotPoint1->z == dotPoint2->z) {
		return 1;
	}
	return 0;

}

// CUBE 구조체를 포인터로 받아 두 좌표 사이의 거리(대각선)를 계산해 반환하는 함수
double calculateDiagonal(CUBE* cube) {
	return sqrt(	// sqrt(x) : x의 제곱근을 구해 반환하는 함수
		pow((cube->point1->x - cube->point2->x), 2) +	// pow(x, y) : x의 y제곱 값을 반환하는 함수
		pow((cube->point1->y - cube->point2->y), 2) +
		pow((cube->point1->z - cube->point2->z), 2)
	);
}

// 거리를 받아 거리를 대각선으로 가지는 정육면체의 한 변(모서리)의 길이를 반환하는 함수
double calculateEdge(double diagonal) {
	return diagonal * sqrt(3) / 3;	// 정육면체는 모든 변의 길이가 같으므로
}

/* // 한 변의 길이를 받아 정육면체의 넓이를 구하는 함수
double calculateDiagonal(double edge) {
	return pow(edge, 3);
} 의미 없는 함수로 판단 됨 */

// CUBE 구조체 포인터와 부피를 받아 출력하는 함수
void showResult(CUBE* cube, double volume) {
	printf("Dot1 : (%d, %d, %d)\n", cube->point1->x, cube->point1->y, cube->point1->z);
	printf("Dot2 : (%d, %d, %d)\n", cube->point2->x, cube->point2->y, cube->point2->z);
	printf("Volume : %.2lf\n", volume);
}

int main(void) {
	POINT dot1, dot2;
	CUBE cube1 = { &dot1, &dot2 };
	double diagonal;
	double edge;
	double volume;
	srand((unsigned)time(NULL));

	do {
		getPoint(&dot1); // 구조체 변수의 '주소'를 매개변수로 준다
		getPoint(&dot2);
	} while (isSameDot(&dot1, &dot2));

	diagonal = calculateDiagonal(&cube1);
	edge = calculateEdge(diagonal);
	volume = pow(edge, 3); // 한 변의 길이가 edge인 정육면체의 넓이
	// 함수화 하기엔 너무 간단한 부분이기에, 의미없는 함수화를 줄였다

	showResult(&cube1, volume);

	return 0;
}