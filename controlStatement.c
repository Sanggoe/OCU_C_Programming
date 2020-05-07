/* 200402 핸드폰 요금을 계산하는 프로그램. 요금 고정의 무제한,
데이터 사용량에 따른 종량제 두 가지 플랜 그리고 세금으로 구성
플랜 코드와 데이터량을 입력하면 이용 금액을 출력하는 프로그램
Program made by Park SangMin*/

#include <stdio.h>

const int UNLIMITED_BASIC_FEE = 5000;	// 무제한 요금제의 기본료를 선언해 놓은 상수
const int DEALUSED_BASIC_FEE = 6000;		// 종량제 요금제의 기본료를 선언해 놓은 상수
const int UNLIMITED_USED_FEE = 50000;	// 무제한 요금제의 사용료를 선언해 놓은 상수

int main() {
	int planCode;									// 플랜 코드를 담을 변수
	int usedData;									// 사용한 데이터량을 담을 변수
	int tempData;									// 사용한 데이터별 요금 계산을 위해 데이터량을 담을 임시변수
	int usedFee = 0;								// 종량제 이용 요금을 계산해서 담을 변수
	int totalFee = 0;
	// 전체 이용요금을 계산해서 담을 변수
	int tax = 0;										// 세금을 담을 변수

	printf("플랜: ");
	scanf_s("%d", &planCode); // 플랜을 키보드로 입력 받아 저장

	// 플랜의 값에 따라 switch문의 case로 나뉘어 각각 수행되는 코드가 다르다.
	switch (planCode) {

	case 1:	// 플랜 값이 1일 때, break; 전까지의 코드를 수행한다.
		tax = (int)((UNLIMITED_BASIC_FEE + UNLIMITED_USED_FEE) * 0.1);	// 세금 = (기본료 + 사용료) * 0.1
		totalFee = (UNLIMITED_BASIC_FEE + UNLIMITED_USED_FEE) + tax;	// 전체 이용금액 = 기본료 + 사용료 + 세금

		// 무제한 요금제의 상세 명세를 화면에 출력
		printf("무제한 요금제 요금:: 기본료: %d원, 사용료: %d원, 세금: %d원, 요금합계: %d원\n",
			UNLIMITED_BASIC_FEE, UNLIMITED_USED_FEE, tax, totalFee);
		break;		// break문으로 switch구문을 빠져나가는 명령어

	case 2:		// 플랜 값이 2일 때, break; 전까지의 코드를 수행한다.
		printf("데이터 사용량: ");
		scanf_s("%d", &usedData);
		tempData = usedData;

		if (tempData > 2000) {						// 사용한 데이터량이 2000MB(2GB)보다 클 때 (int형 이므로, usedData>=2001와 같다)
			usedFee += (tempData - 2000) * 10;	// 2001MB 이상의 사용 데이터량을 계산해서 이용 요금 변수에 더한다.
			tempData = 2000;							// 다음 요금 계산을 위해 데이터 사용량은 계산한 값을 제외한 나머지 2000MB를 넣는다.
		}
		if (tempData > 1000) {						// 사용한 데이터량이 1000MB보다 클 때
			usedFee += (tempData - 1000) * 12;	// 1001MB ~ 2000MB 까지의 이용 요금을 계산한다.
			tempData = 1000;							// 마찬가지로 계산한 데이터 사용량은 제외하고 나머지 1000MB를 변수에 넣는다.
		}
		if (tempData > 500) {							// 사용한 데이터 량이 500MB보다 클 때
			usedFee += (tempData - 500) * 15;	// 501MB ~ 1000MB 까지의 이용 요금을 계산한다.
			tempData = 500;							// 계산한 데이터 사용량을 제외한 500MB를 사용한 데이터량 변수에 넣는다.
		}
		usedFee += tempData * 20;				// 사용한 데이터 량이 500MB 이하인 경우 요금을 계산하여 이용 요금 변수에 더한다.

		tax = (int)((usedFee + DEALUSED_BASIC_FEE) * 0.15);	// 세금 = (기본료 + 사용료) * 0.15
		totalFee = usedFee + DEALUSED_BASIC_FEE + tax;		// 전체 이용금액 = (기본료 + 사용료)+ 세금

		// 종량제 요금제의 상세 명세를 화면에 출력
		printf("종량제 요금:: 기본료: %d원, 사용료(%.1lfGB): %d원, 세금: %d원, 요금합계: %d원\n",
			DEALUSED_BASIC_FEE, (double)usedData / (double)1000, usedFee, tax, totalFee);
		break;												// break문으로 switch구문을 빠져나가는 명령어

	default:												// 플랜 값이 1, 2의 값이 아닐 경우 다른 어떠한 경우에서든지 다음의 코드를 수행한다.
		printf("plan은 1, 2중에서만 선택 가능합니다.\n");
		break;												// break문으로 switch구문을 빠져나가는 명령어
	}
	return 0;
}
