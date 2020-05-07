/* 200410 �л����� ���� �� ������ �Է� �޾�
�հ� �� �����, ������ ���ϴ� ���α׷�
Program made by Park SangMin*/

#include <stdio.h>

int main() {
	int testScore;			// ���� �����Է¹��� ����
	int homeworkScore;	// ���� ���� �Է¹��� ����
	int attendanceScore;	// �⼮ ���� �Է¹��� ����
	int totalScore;			// �հ谪�� ����� ���� ����
	const int NUM = 10;	// �ݺ��� Ƚ���� 10�� ����� ����
	const int ERROR = 3;	// ������ �ִ�Ƚ���� 3�� ����� ����
	double persentage;	// ������� ����� ���� ����
	int persentInt;			// ������� �ݿø��� ���� ����

	// ����� i�� �ʱⰪ�� 0, NUM���� ���� �� ���� i�� ������Ű�� ������ �ݺ��Ѵ�.
	for (int i = 0; i < NUM; i++) {
		int error = 0;		// ���� ��� ���� �ӽ� ����

		while (1) {			// �׻� ������ 1�� �� �̹Ƿ�, �ݺ�
			printf("���� ����: ");
			scanf_s("%d", &testScore);
			printf("���� ����: ");
			scanf_s("%d", &homeworkScore);
			printf("�⼮ ����: ");
			scanf_s("%d", &attendanceScore);

			// ���輺���� 0~100 ����, ���� ������ 0~50����, �⼮ ������ 0~45 ���̸� ������ ��
			if ((testScore >= 0 && testScore <= 100) && (homeworkScore >= 0 &&
				homeworkScore <= 50) && (attendanceScore >= 0 && attendanceScore <= 45)) {
				printf("����: %d ����: %d �⼮: %d\n", testScore, homeworkScore, attendanceScore);
				break; // while���� Ż���մϴ�.
			}
			else {
				printf("���輺���� 0~100, ���������� 0~50, �⼮ ������ 0~45 ������ ������ �Է��ϼ���!\n\n");
				if (++error == ERROR) { // �Ź� ���� Ƚ���� ������Ű��, 3��° ������ ��
					printf("�Էµ� �� ������ ���α׷� ������\n");
					return 0;	// �޽��� ��� �� ���α׷��� ����
				}
			}
		}

		if (attendanceScore < 30) {
			printf("F �����Դϴ�.\n\n");
		}
		else {
			totalScore = testScore + homeworkScore + attendanceScore;	// �� ���� �հ踦 ����
			persentage = totalScore / 195.0 * 100;	// totalScore : persentage = 195 : 100�̹Ƿ�

			/* ������� �Ҽ��� ù°�ڸ����� �ݿø��Ͽ� 0.5�̻��� 1�� ���ؼ� int������ ��ȯ,
			0.5�̸��� �ٷ� int������ ��ȯ�Ͽ� ������ persentInt ������ �־��ش�. */
			persentInt = (int)(persentage * 10) % 10 < 5 ? (int)persentage : (int)(persentage + 1);
			printf("�ۼ�Ʈ : %d\n", persentInt);

			if (persentInt <= 40) {
				printf("F �����Դϴ�.\n\n");	// ������� 40%������ ��� F����
			}
			else if (persentInt > 40 && persentInt <= 50) {
				printf("C �����Դϴ�.\n\n");	// ������� 41%~50%�� ��� C���� 
			}
			else if (persentInt > 50 && persentInt <= 60) {
				printf("C+ �����Դϴ�.\n\n");	// ������� 51%~60%�� ��� C+���� 
			}
			else if (persentInt > 60 && persentInt <= 70) {
				printf("B �����Դϴ�.\n\n");	// ������� 61%~70%�� ��� B���� 
			}
			else if (persentInt > 70 && persentInt <= 80) {
				printf("B+ �����Դϴ�.\n\n");	// ������� 71%~80%�� ��� B+���� 
			}
			else if (persentInt > 80 && persentInt <= 90) {
				printf("A �����Դϴ�.\n\n");	// ������� 81%~90%�� ��� A���� 
			}
			else if (persentInt > 90) {		// ������� 91%�̻��� ��� A+����
				printf("A+ �����Դϴ�.\n\n");
			}
		}
	}
}