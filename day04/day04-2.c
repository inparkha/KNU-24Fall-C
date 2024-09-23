#include <stdio.h>

void swap(int* pnum1, int* pnum2)
{
	int temp = *pnum1;
	*pnum1 = *pnum2;
	*pnum2 = temp;

}

int main()
{
	int a = 10, b = 20;
	int* pa;
	pa = &a;

	int* pb;
	pb = &b;

	printf("a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);

	return 0;
}

