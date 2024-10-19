#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);

int main() {
	int array[SIZE][SIZE];

	fillRandom(array);
	printArray(array);
	movePointer(array);

	return 0;
}

void fillRandom(int array[SIZE][SIZE]) {
	printf("배열 출력 : \n");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			array[i][j] = rand() % 20 + 1;
		}
	}
}

void printArray(int array[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}

void movePointer(void* array) {
	void* target;
	int result;
	int n = 0;

	while (1) {
		target = ((int*)array + n);
		result = *(int*)target;

		printf("현재위치 : (%d, %d), 배열의 값 : %d\n", (n / 10), (n % 10), n);

		n += result;

		if (n >= 100) {
			n -= *(int*)target;
			printf("더 이상 이동할 수 없습니다."
				"\n종료위치: (%d, %d), 배열의 값: %d\n", n / 10, n % 10, result);
			break;
		}
	}
}