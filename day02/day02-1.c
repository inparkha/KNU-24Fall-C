#include <stdio.h>
int main(void) {
	int operation;

	printf("���ϴ� ����� �Է��Ͻÿ�.\n");
	printf("1.���ϱ� 2.���� 3.���ϱ� 4.������\n");
	printf("��� : ");
	scanf_s("%d", &operation);

	double num1, num2;
	printf("ù��° ���� : ");
	scanf_s("%lf", &num1);
	printf("�ι�° ���� : ");
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
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
	}

	printf("result = %lf\n", result);

	return 0;
}