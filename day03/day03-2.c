#include <stdio.h>

int fact(int num)
{
	int res;
	if (num == 0 || num == 1)
	{
		res = 1;
		return res;
	}

	res = num * fact(num - 1);
	return res;
}

int main()
{
	
	int num;
	printf("����� ���丮�� �� �Է� : ");
	scanf_s("%d", &num);
	
	int result = fact(num);
	printf("%d! = %d", num, fact(num));
	return 0;
}

