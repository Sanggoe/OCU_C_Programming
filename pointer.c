/* 200501 ���� 100���� rand�� �迭�� �Է� �޾� �����͸� �̿��Ͽ� �Լ���
�Ѱ��� �� �ִ�, �ּڰ��� ã�� �Լ��� ��ȯ�� ���� main���� ����ϴ� ���α׷�
Program made by Park SangMin*/

#include <stdio.h>
#include <stdlib.h> // rand() �Լ��� ����ϱ� ���� standard library �������
#include <time.h>
#define NUM 100

// �Լ��� �Ű������� �迭�� �����ּ�, ������ ������ ���� �� ���� �Ѱ��ش�.
void sum_ave(int arr[], int* min, int* max) {
	for(int i=0; i<NUM; i++) {
		if (arr[i] > * max) 	// max���� ū ���� ������
			*max = arr[i]; 	// max�� �� ū ���� �ִ´�.
		if (arr[i] < *min)	// min���� ���� ���� ������
			*min = arr[i];	// min�� �� ���� ���� �ִ´�.
	}
}

int main(void) {
	int arr[100]; // ������ ���� 100���� ���� �迭
	int min = 10000; // min ���� �ʱ�ȭ
	int max = 0; // max ���� �ʱ�ȭ
	srand((unsigned)time(NULL)); // ������ �� ������ �ٸ� ���� ����ϱ� ���� srand �Լ�

	for (int i = 0; i < NUM; i++) {
		arr[i] = rand() % 10000+1; // 1 ~ 10000 ������ ���� ��ȯ
	}

	// �Լ� ȣ��, �Ű������� �迭�� �����ּ�, ������ �ּ� �� ���� �Ѱ��ش�.
	sum_ave(arr, &min, &max); 
	printf("MIN : %d,  MAX : %d\n", min, max);

	return 0;
}
