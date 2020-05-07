/* 200425 �迭�� �̿��� �� �л����� ������ �ʱ�ȭ �� ��,
����� ������� ������ �ű� �� ����ϴ� ���α׷�
Program made by Park SangMin*/

#include <stdio.h>
#include <stdlib.h> // rand() �Լ��� ����ϱ� ���� standard library �������
#define STUDENTS 100	// �л� ���� ��ũ�� ����� ����

// �л����� ������ �迭�� �Է¹޴� �Լ�
void giveStudentsScore(int scores[]) {
	for (int i = 0; i < STUDENTS; i++) {
		scores[i] = rand() % 100 + 1;
	}
}

// �л����� ������ ������������ �����ϴ� �Լ�
void sortStudentsScore(int scores[]) {
	int temp, i, j;

	for (i = 0; i < STUDENTS; i++) {
		for (j = 0; j < STUDENTS - 1 - i; j++) {
			if (scores[j] < scores[j + 1]) {
				temp = scores[j];
				scores[j] = scores[j + 1];
				scores[j + 1] = temp;
			}
		}
	}
}

// �л����� ������ ������ �ο��ϴ� �Լ�
void giveStudentsGrades(int scores[], char grades[]) {
	_Bool isSameValue = 0;
	char gradeList[5] = { 'A', 'B', 'C', 'D', 'F' };
	int i;

	for (i = 0; i < 10; i++) {
		grades[i] = gradeList[0];
	}

	if (grades[9] == grades[10]) {
		isSameValue = 1;
		while (isSameValue) {
			grades[i++] = gradeList[0];
			if (grades[i-1] == grades[i]) {
				isSameValue = 0;
			}
		}
	}

	for (; i < 25; i++) {
		grades[i] = gradeList[1];
	}
	if (grades[24] == grades[25]) {
		isSameValue = 1;
		while (isSameValue) {
			grades[i++] = gradeList[0];
			if (grades[i - 1] == grades[i]) {
				isSameValue = 0;
			}
		}
	}



	for (; i < STUDENTS; i++) {
		if (i <= 10) {
			grades[i] = gradeList[0];
			if (grades[9] == grades[10]) {
				isSameValue = 1;
			}
		}
		else if (i > 10) {
			if (isSameValue) {

			}
			grades[i] = gradeList[1];
		}
		else if (i > 25) {
			grades[i] = gradeList[2];
		}
		else if (i > 50) {
			grades[i] = gradeList[3];
		}
		else if (i > 80) {
			grades[i] = gradeList[4];
		}

	}
}

// �л����� ������ ����ϴ� �Լ�
void showStudentScore(int scores[], char grades[]) {
	for (int i = 0; i < STUDENTS; i++) {
		if (i % 5 == 0) {
			printf("\n");
		}
		printf("[%3d��, %c, %3d��]  ", i + 1, grades[i], scores[i]);
	}
	printf("\n");
}

int main(void) {
	int scores[100];
	char grades[100];

	giveStudentsScore(scores);
	sortStudentsScore(scores);
	giveStudentsGrades(scores, grades);
	showStudentsScore(scores, grades);

	return 0;
}