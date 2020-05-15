/* 200515 ���̰� 10 �̻��� ������ ���ڿ��� �Է¹޾� ���ڿ� �迭��
�Է��ϰ�, �� ���ڸ� �Է� �޾� �ش� ���ڸ� ������ ���ڿ��� ���̸�
���ϴ� ���α׷�. ��, �迭 ���� �� �����ͷ� �����ؾ� ��
Program made by Park SangMin */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �̹� string,h�� �����ϴ� strlen�� ����� ���� �Լ��� �����غ�����
int strLen(char* str) {
	int i = 0, len = 0;

	while (*(str + i) != '\0'){	// str�� len��° ���� '\0'�� �ƴ� �� ����
		len++;	// ���̸� ++ �����ش�
		i++;
	}
	return len;
}

// ch�� ������ ���ڿ��� ���̸� ��ȯ�ϴ� �Լ�
int strLenExcept(char* str, char ch) {
	int i = 0, len = 0;

	while (*(str + i) != '\0') { 	// str�� len��° ���� '\0'�� �ƴ� �� ����
		if (ch != *(str + i)) {	// ���� �� ���� ch�� ���� ���� ��쿡�� ++ �����ش�
			len++;
		}
		i++;
	}
	return len;
}

// �ش� ������ ������ ���ڿ����� ã�� ��ȯ�ϴ� �Լ��� �����غ�����
int strCountCh(char* str, char ch) {
	int i = 0, count = 0;

	while (*(str + i) != '\0') { 	// str�� len��° ���� '\0'�� �ƴ� �� ����
		if (ch == *(str + i)) {	// ���� �� ���� ch�� ���� ��쿡�� ++ �����ش�
			count++;
		}
		i++;
	}
	return count;
}

int main(void) {
	char strArray[100];
	char ch;

	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%[^\n]s", strArray);
	// scanf����, �ٹٲ� ������ \n�� ������ �������� ��� ���ڿ��� �о���δٴ� �ǹ�

	printf("Ž���� ���ڸ� �Է��ϼ��� : ");
	ch = getche();	// ���� �ϳ��� �Է� �޾� ���ۿ� �������� �ʰ� �ٷ� ��ȯ�԰� ���ÿ� ȭ�鿡 ���

	printf("\n���ڿ��� ���� : %d\n", strLen(strArray));
	printf("Ž�� �� ���� : %c\n", ch);
	printf("Ž�� ���� ���� ���� ���� : %d\n", strLenExcept(strArray, ch));
	
	/* ������ strCountCh �Լ��� �̿��� ���ڿ��� ���̸� ���� ���� �ִ�.
		strLen(strArray) - strCountCh(strArray, ch)
		�� ������ �����ϸ� �ش� ���ڸ� ������ ���̰� ���´�!
		
		����� ������ �� �� ��, �迭�� �� ���̳� �����Ͽ� ã�� ������
		�� ���� ���ϸ� ���� ���� �� ���� ��ȿ������ ����� �� ����. */
	
	return 0;
}
