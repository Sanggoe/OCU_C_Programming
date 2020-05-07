/* 200501 정수 100개를 rand로 배열에 입력 받아 포인터를 이용하여 함수에
넘겨준 후 최댓값, 최솟값을 찾아 함수의 반환값 없이 main에서 출력하는 프로그램
Program made by Park SangMin*/

#include <stdio.h>
#include <stdlib.h> // rand() 함수를 사용하기 위한 standard library 헤더파일
#include <time.h>
#define NUM 100

// 함수의 매개변수로 배열의 시작주소, 정수형 포인터 변수 두 개를 넘겨준다.
void sum_ave(int arr[], int* min, int* max) {
	for(int i=0; i<NUM; i++) {
		if (arr[i] > * max) 	// max보다 큰 값이 있으면
			*max = arr[i]; 	// max에 더 큰 값을 넣는다.
		if (arr[i] < *min)	// min보다 작은 값이 있으면
			*min = arr[i];	// min에 더 작은 값을 넣는다.
	}
}

int main(void) {
	int arr[100]; // 정수형 변수 100개를 담을 배열
	int min = 10000; // min 값을 초기화
	int max = 0; // max 값을 초기화
	srand((unsigned)time(NULL)); // 컴파일 할 때마다 다른 값을 출력하기 위한 srand 함수

	for (int i = 0; i < NUM; i++) {
		arr[i] = rand() % 10000+1; // 1 ~ 10000 사이의 값을 반환
	}

	// 함수 호출, 매개변수로 배열의 시작주소, 변수의 주소 두 개를 넘겨준다.
	sum_ave(arr, &min, &max); 
	printf("MIN : %d,  MAX : %d\n", min, max);

	return 0;
}
