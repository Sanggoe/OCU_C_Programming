/* 200402 �ڵ��� ����� ����ϴ� ���α׷�. ��� ������ ������,
������ ��뷮�� ���� ������ �� ���� �÷� �׸��� �������� ����
�÷� �ڵ�� �����ͷ��� �Է��ϸ� �̿� �ݾ��� ����ϴ� ���α׷�
Program made by Park SangMin*/

#include <stdio.h>

const int UNLIMITED_BASIC_FEE = 5000;	// ������ ������� �⺻�Ḧ ������ ���� ���
const int DEALUSED_BASIC_FEE = 6000;		// ������ ������� �⺻�Ḧ ������ ���� ���
const int UNLIMITED_USED_FEE = 50000;	// ������ ������� ���Ḧ ������ ���� ���

int main() {
	int planCode;									// �÷� �ڵ带 ���� ����
	int usedData;									// ����� �����ͷ��� ���� ����
	int tempData;									// ����� �����ͺ� ��� ����� ���� �����ͷ��� ���� �ӽú���
	int usedFee = 0;								// ������ �̿� ����� ����ؼ� ���� ����
	int totalFee = 0;
	// ��ü �̿����� ����ؼ� ���� ����
	int tax = 0;										// ������ ���� ����

	printf("�÷�: ");
	scanf_s("%d", &planCode); // �÷��� Ű����� �Է� �޾� ����

	// �÷��� ���� ���� switch���� case�� ������ ���� ����Ǵ� �ڵ尡 �ٸ���.
	switch (planCode) {

	case 1:	// �÷� ���� 1�� ��, break; �������� �ڵ带 �����Ѵ�.
		tax = (int)((UNLIMITED_BASIC_FEE + UNLIMITED_USED_FEE) * 0.1);	// ���� = (�⺻�� + ����) * 0.1
		totalFee = (UNLIMITED_BASIC_FEE + UNLIMITED_USED_FEE) + tax;	// ��ü �̿�ݾ� = �⺻�� + ���� + ����

		// ������ ������� �� ���� ȭ�鿡 ���
		printf("������ ����� ���:: �⺻��: %d��, ����: %d��, ����: %d��, ����հ�: %d��\n",
			UNLIMITED_BASIC_FEE, UNLIMITED_USED_FEE, tax, totalFee);
		break;		// break������ switch������ ���������� ��ɾ�

	case 2:		// �÷� ���� 2�� ��, break; �������� �ڵ带 �����Ѵ�.
		printf("������ ��뷮: ");
		scanf_s("%d", &usedData);
		tempData = usedData;

		if (tempData > 2000) {						// ����� �����ͷ��� 2000MB(2GB)���� Ŭ �� (int�� �̹Ƿ�, usedData>=2001�� ����)
			usedFee += (tempData - 2000) * 10;	// 2001MB �̻��� ��� �����ͷ��� ����ؼ� �̿� ��� ������ ���Ѵ�.
			tempData = 2000;							// ���� ��� ����� ���� ������ ��뷮�� ����� ���� ������ ������ 2000MB�� �ִ´�.
		}
		if (tempData > 1000) {						// ����� �����ͷ��� 1000MB���� Ŭ ��
			usedFee += (tempData - 1000) * 12;	// 1001MB ~ 2000MB ������ �̿� ����� ����Ѵ�.
			tempData = 1000;							// ���������� ����� ������ ��뷮�� �����ϰ� ������ 1000MB�� ������ �ִ´�.
		}
		if (tempData > 500) {							// ����� ������ ���� 500MB���� Ŭ ��
			usedFee += (tempData - 500) * 15;	// 501MB ~ 1000MB ������ �̿� ����� ����Ѵ�.
			tempData = 500;							// ����� ������ ��뷮�� ������ 500MB�� ����� �����ͷ� ������ �ִ´�.
		}
		usedFee += tempData * 20;				// ����� ������ ���� 500MB ������ ��� ����� ����Ͽ� �̿� ��� ������ ���Ѵ�.

		tax = (int)((usedFee + DEALUSED_BASIC_FEE) * 0.15);	// ���� = (�⺻�� + ����) * 0.15
		totalFee = usedFee + DEALUSED_BASIC_FEE + tax;		// ��ü �̿�ݾ� = (�⺻�� + ����)+ ����

		// ������ ������� �� ���� ȭ�鿡 ���
		printf("������ ���:: �⺻��: %d��, ����(%.1lfGB): %d��, ����: %d��, ����հ�: %d��\n",
			DEALUSED_BASIC_FEE, (double)usedData / (double)1000, usedFee, tax, totalFee);
		break;												// break������ switch������ ���������� ��ɾ�

	default:												// �÷� ���� 1, 2�� ���� �ƴ� ��� �ٸ� ��� ��쿡������ ������ �ڵ带 �����Ѵ�.
		printf("plan�� 1, 2�߿����� ���� �����մϴ�.\n");
		break;												// break������ switch������ ���������� ��ɾ�
	}
	return 0;
}
