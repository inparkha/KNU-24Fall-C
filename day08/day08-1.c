#include <stdio.h>
#include <string.h>

int main()
{

	char str[20];
	char* ptr;
	int i,cnt = 0;

	printf("문자열을 입력하세요: ");
	scanf_s("%19s", str, (unsigned int)sizeof(str));

	while (str[cnt] != NULL)
	{
		cnt++;
	}

	ptr = &str[cnt];

	for (i = 0; i <= cnt; i++)
	{
		printf("%c ", *(ptr - i));
	}
	printf("\n");

	return 0;
}