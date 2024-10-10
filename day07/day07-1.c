#include <stdio.h>
int main()
{
	int N;
	printf("N = ");
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-i-1; j++)
		{
			printf(" ");
		}
		
		for(int k = 0; k<i*2+1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}