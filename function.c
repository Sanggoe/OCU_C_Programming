/* 200414 주차장의 주차 요금을 계산하는 프로그램
함수를 이용하여 함수화 하도록 프로그래밍 하기
Program made by Park SangMin*/

#include <stdio.h>

int howMuchPrice(int hour, int min);
int raiseUpMinValue(int min);
int calculatePerTenMin(int min);
int calculatePerHour(int hour);

const int THOUSAND = 1000; // 상수 1000


int main(void) {
	int hour;		// 시간
	int min;		// 분
	int totalPrice;	// 총 요금

	for (int i = 0; i < 10; i++) {
		printf("시간: ");
		scanf_s("%d", &hour);
		printf("분  : ");
		scanf_s("%d", &min);

		if (min >= 60) {
			hour += min / 60;
			min %= 60;
		}

		totalPrice = howMuchPrice(hour, min);
		printf("%d시간 %d분 요금은 %d원 입니다.\n\n", hour, min, totalPrice);
	}
}

// calculate all the price.
int howMuchPrice(int hour, int min) {
	int price = 0;

	min = raiseUpMinValue(min);

	while (hour != 0 || min != 0) {  // until both are not 0
		// nomal price
		if (hour < 4 || hour == 4 && min == 0) {  // if less than 4 hours
			price += calculatePerHour(hour) + calculatePerTenMin(min);
			hour = 0;
			min = 0;  // initialize both to '0' after calculate the price.
		}
		// four to day price
		else {  // if more then 4 hours
			price += 25000;
			// if longger than 24 hours
			if (hour >= 24) {
				hour -= 24;  // minus 24 hours after calculate the price.
			}
			// else shorter than 24 hours
			else {
				hour = 0;
				min = 0;  // initialize both to '0' after calculate the price.
			}
		}
	}
	return price;
}

// Raise up minute to 10 digit.
int raiseUpMinValue(int min) {
	return (min + 9) / 10 * 10;
}

// calculate and return the price per ten minute.
int calculatePerTenMin(int min) {
	return (min / 10) * THOUSAND;
}

//calculateand and return the price per hour.
int calculatePerHour(int hour) {
	return hour * 6 * THOUSAND;
}
