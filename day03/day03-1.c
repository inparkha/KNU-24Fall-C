#include <stdio.h>

int is_prime_number(int num)
{
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int num;
	printf("���ڸ� �Է��ϼ��� : ");
	scanf_s("%d", &num);
	int result = is_prime_number(num);

	printf("%d\n", result);
	
}

