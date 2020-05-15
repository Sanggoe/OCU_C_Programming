/* 200515 길이가 10 이상인 임의의 문자열을 입력받아 문자열 배열에
입력하고, 한 글자를 입력 받아 해당 글자를 제외한 문자열의 길이를
구하는 프로그램. 단, 배열 접근 시 포인터로 접근해야 함
Program made by Park SangMin */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이미 string,h에 존재하는 strlen을 사용자 정의 함수로 구현해보았음
int strLen(char* str) {
	int i = 0, len = 0;

	while (*(str + i) != '\0'){	// str의 len번째 값이 '\0'이 아닐 때 까지
		len++;	// 길이를 ++ 시켜준다
		i++;
	}
	return len;
}

// ch를 제외한 문자열의 길이를 반환하는 함수
int strLenExcept(char* str, char ch) {
	int i = 0, len = 0;

	while (*(str + i) != '\0') { 	// str의 len번째 값이 '\0'이 아닐 때 까지
		if (ch != *(str + i)) {	// 만약 그 값이 ch와 같지 않을 경우에만 ++ 시켜준다
			len++;
		}
		i++;
	}
	return len;
}

// 해당 문자의 개수를 문자열에서 찾아 반환하는 함수를 구현해보았음
int strCountCh(char* str, char ch) {
	int i = 0, count = 0;

	while (*(str + i) != '\0') { 	// str의 len번째 값이 '\0'이 아닐 때 까지
		if (ch == *(str + i)) {	// 만약 그 값이 ch와 같을 경우에만 ++ 시켜준다
			count++;
		}
		i++;
	}
	return count;
}

int main(void) {
	char strArray[100];
	char ch;

	printf("문자열을 입력하세요 : ");
	scanf("%[^\n]s", strArray);
	// scanf에서, 줄바꿈 문자인 \n가 나오기 전까지의 모든 문자열을 읽어들인다는 의미

	printf("탐색할 문자를 입력하세요 : ");
	ch = getche();	// 문자 하나를 입력 받아 버퍼에 저장하지 않고 바로 반환함과 동시에 화면에 출력

	printf("\n문자열의 개수 : %d\n", strLen(strArray));
	printf("탐색 된 문자 : %c\n", ch);
	printf("탐색 문자 제외 문자 개수 : %d\n", strLenExcept(strArray, ch));
	
	/* 구현한 strCountCh 함수를 이용해 문자열의 길이를 구할 수도 있다.
		strLen(strArray) - strCountCh(strArray, ch)
		위 연산을 수행하면 해당 문자를 제외한 길이가 나온다!
		
		방법을 생각해 본 것 뿐, 배열을 두 번이나 참조하여 찾기 때문에
		한 번에 비교하며 수를 세는 것 보다 비효율적인 방법인 것 같다. */
	
	return 0;
}
