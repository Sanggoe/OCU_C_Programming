/* 200521 3���� ����� ��ǥ�� ����ü�� ǥ���ϰ�,
�������� �Է¹��� �� ���� ��ǥ�� �մ� ���� �밢��
���� �ϴ� ������ü�� ���Ǹ� ���ϴ� ���α׷�
Program made by Park SangMin */

#include <stdio.h>
#include <math.h>
#include <time.h>

// POINT�� type�� �������� ����ü point
typedef struct point {
	int x, y, z;
} POINT;

// CUBE�� type�� �������� ����ü cube
typedef struct cube {
	POINT* point1;	// point ����ü�� �����͸� ������ ������.
	POINT* point2;
} CUBE;

// POINT ����ü�� �����ͷ� �޾� ���� �� ����� �ش� �ּҿ� �������� �־��ִ� �Լ�
void getPoint(POINT* dotPoint) {
	dotPoint->x = rand() % 10 + 1;	// ����ü ������ ���Ŀ��� ����� ������ �� ->�� ����Ѵ�.
	dotPoint->y = rand() % 10 + 1;
	dotPoint->z = rand() % 10 + 1;
}

// �� ���� ���� ���Ͽ� ���� ��ġ�̸� 1, �ƴϸ� 0�� ��ȯ�ϴ� �Լ�
_Bool isSameDot(POINT* dotPoint1, POINT* dotPoint2) {
	if (dotPoint1->x == dotPoint2->x && dotPoint1->y == dotPoint2->y && dotPoint1->z == dotPoint2->z) {
		return 1;
	}
	return 0;

}

// CUBE ����ü�� �����ͷ� �޾� �� ��ǥ ������ �Ÿ�(�밢��)�� ����� ��ȯ�ϴ� �Լ�
double calculateDiagonal(CUBE* cube) {
	return sqrt(	// sqrt(x) : x�� �������� ���� ��ȯ�ϴ� �Լ�
		pow((cube->point1->x - cube->point2->x), 2) +	// pow(x, y) : x�� y���� ���� ��ȯ�ϴ� �Լ�
		pow((cube->point1->y - cube->point2->y), 2) +
		pow((cube->point1->z - cube->point2->z), 2)
	);
}

// �Ÿ��� �޾� �Ÿ��� �밢������ ������ ������ü�� �� ��(�𼭸�)�� ���̸� ��ȯ�ϴ� �Լ�
double calculateEdge(double diagonal) {
	return diagonal * sqrt(3) / 3;	// ������ü�� ��� ���� ���̰� �����Ƿ�
}

/* // �� ���� ���̸� �޾� ������ü�� ���̸� ���ϴ� �Լ�
double calculateDiagonal(double edge) {
	return pow(edge, 3);
} �ǹ� ���� �Լ��� �Ǵ� �� */

// CUBE ����ü �����Ϳ� ���Ǹ� �޾� ����ϴ� �Լ�
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
		getPoint(&dot1); // ����ü ������ '�ּ�'�� �Ű������� �ش�
		getPoint(&dot2);
	} while (isSameDot(&dot1, &dot2));

	diagonal = calculateDiagonal(&cube1);
	edge = calculateEdge(diagonal);
	volume = pow(edge, 3); // �� ���� ���̰� edge�� ������ü�� ����
	// �Լ�ȭ �ϱ⿣ �ʹ� ������ �κ��̱⿡, �ǹ̾��� �Լ�ȭ�� �ٿ���

	showResult(&cube1, volume);

	return 0;
}