/* 200316 Ű����� �Ǽ��� �Է¹޾� �Ǽ��� ������ ���� ��,
������ ������ ���� �� ����ϴ� ���α׷� Program made by Park SangMin*/

#include <stdio.h> // include standard input output header file.

int main(void) {
	double d_value;	// �Ǽ��� ���� double�� ���� ����
	int i_value;		// ������ ���� int�� ���� ����

	scanf_s("%lf", &d_value); // d_value�� �ּҸ� ����, ���������� %lf�� �Ǽ��� �Է¹���

	// Warning! double�� -> int�� ��ȯ�� �����Ͱ� �սǵ� �� �ֽ��ϴ�.
	i_value = d_value; // int�� ������ double�� ������ ���� (int)�� ���� ����ȯ ���� ����

	// Warning! %lf���� double������ �μ��� �ʿ�������, int���� �μ��� �Խ��ϴ�.
	/* printf("double��: %lf, int��: %lf", d_value, i_value); */

	printf("double��: %lf, int��: %d", d_value, i_value);
}