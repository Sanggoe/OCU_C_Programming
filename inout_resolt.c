/* 200312 scanf, printf �Լ��� �̿��� ������ �Է¹޾�
ȯ���Ͽ� ����ϴ� ���α׷� Program made by Park.s.m*/

#include<stdio.h>
// standard input output, ǥ�� ����� �������

int main(void) {
	int volume_ml;
	double volume_L;

	// Ű����κ��� ������ �Է¹޾� ml ������ ������ �Է�
	scanf_s("%d", &volume_ml);

	volume_L = volume_ml * 0.001; // ml�� L�� ���� ȯ�� �� ����

	// 1L == 1000ml ���� ���, L�� �Ҽ��� 3°�ڸ����� ���
	printf("%d ml = %.3lf l\n", volume_ml, volume_L);

	return 0;
}