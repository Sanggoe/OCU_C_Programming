/* 200508 �迭�� �̿��� �� �л����� ������ �ʱ�ȭ �� ��,
����� ������� ������ �ű� �� ����ϴ� ���α׷�
��, �迭�� �Ű������� �ѱ�ų� ������ �� �����ͷ� �����ؾ� ��
Program made by Park SangMin */

#include <stdio.h>
#include <stdlib.h> // rand() �Լ��� ����ϱ� ���� standard library �������
#include <time.h> // srand() �Լ��� ����ϱ� ���� time �������
#define STUDENTS 100	// �л� ���� ��ũ�� ����� ����

// �л����� ������ �迭�� �Է¹޴� �Լ�
void giveStudentsScore(int* scores) {
	for (int i = 0; i < STUDENTS; i++) {
		*(scores + i) = rand() % 101;
		// 100���� ���� ������ + 1 ��������, ���� �ο� ������ 1~100�� ����
	}
}

// �л����� ������ ������������ �����ϴ� �Լ�
void sortStudentsScore(int* scores) {
	int temp, i, j;

	// ���� ������ �̿��� ����
	for (i = 0; i < STUDENTS; i++) {
		for (j = 0; j < STUDENTS - 1 - i; j++) {
			if (*(scores + j) < *(scores + j + 1)) { // ���� ���Ұ� ���� ���Һ��� ������
				// swap ������ ���� ���� �ڷ� ����
				temp = *(scores + j);
				*(scores + j) = *(scores + j + 1);
				*(scores + j + 1) = temp;
			}
		}
	}
}

// �л����� ������ ����ϴ� �Լ�
void showStudentsScore(int* scores) {
	_Bool isSameValue = 0; // ������ ������ üũ�ϴ� ����
	_Bool isNextGrade = 0; // ������ �ٲ�� ������� üũ�ϴ� ����
	int gradeList[5] = { 'A', 'B', 'C', 'D', 'F' }; // �ο��� ���� �迭
	int temp, j = 0;

	for (int i = 0; i < STUDENTS; i++) {
		if (i == 10 || i == 25 || i == 50 || i == 80) { // A,B,C,D,F ������ �ٲ�� ����� ���
			isNextGrade = 1; // �ο� ������ ������ ���� üũ
		}

		if (*(scores + i - 1) == *(scores + i)) { // �� ����� ������ ������
			isSameValue = 1; // ������ ���ٰ� üũ
			temp = i; // ��� �ӽ� ����
			while (isSameValue) { // ���� ����� ������ �ƴ� �� ����
				if (i % 5 == 0) {
					printf("\n");
				}
				printf("[%3d��, %3d��, %c]  ", temp, *(scores + i), *(gradeList + j) ); // ���� ���� ���
				i++;

				if (i == 10 || i == 25 || i == 50 || i == 80) { // A,B,C,D,F ������ �ٲ�� ����� ���
					isNextGrade = 1; // �ٲ� ������ ���� üũ
				}

				if (*(scores + i - 1) != *(scores + i)) { // ���� ����� ������ �ٸ���
					isSameValue = 0; // while�� Ż�� ����
				}
			}
		}

		if (isNextGrade) { // ������ �ٲ� ���������
			j++; // ���� Down grade
			isNextGrade = 0;
		}

		if (i % 5 == 0) {
			printf("\n");
		}
		printf("[%3d��, %3d��, %c]  ", i + 1, *(scores + i), *(gradeList + j));

	} // scores �迭�� ù���� ���, ��° ���� ����, ��° ���� ������ ���
	printf("\n");
}

int main(void) {
	int scores[100];
	srand((unsigned)time(NULL));

	giveStudentsScore(scores);
	sortStudentsScore(scores);
	showStudentsScore(scores);

	return 0;
}