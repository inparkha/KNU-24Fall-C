#include <stdio.h>
int main(void)
{
	
	for (int i = 0; i<=99; i++)
	{
		if (i % 12 == 0 || i % 7 == 0)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}