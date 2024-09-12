#include <stdio.h>
int main(void) {
	int operation;

	printf("원하는 기능을 입력하시오.\n");
	printf("1.더하기 2.빼기 3.곱하기 4.나누기\n");
	printf("기능 : ");
	scanf_s("%d", &operation);

	double num1, num2;
	printf("첫번째 숫자 : ");
	scanf_s("%lf", &num1);
	printf("두번째 숫자 : ");
	scanf_s("%lf", &num2);


	double result;
	if (operation == 1) {
		result = num1 + num2;
	}
	else if (operation == 2) {
		result = num1 - num2;
	}
	else if (operation == 3) {
		result = num1 * num2;
	}
	else if (operation == 4) {
		result = num1 / num2;
	}
	else {
		printf("잘못 입력하셨습니다.\n");
	}

	printf("result = %lf\n", result);

	return 0;
}