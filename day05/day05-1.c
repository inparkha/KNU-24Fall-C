#include <stdio.h>
#include <stdlib.h>
int main()
{
	int N;
	int* stud_num;
	char** name;
	int* score;

	printf("학생 수를 입력하세요.: ");
	scanf_s(" %d", &N);

	stud_num = (int*)malloc(sizeof(int) * N);
	score = (int*)malloc(sizeof(int) * N);
	name = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++) {
		name[i] = (char*)malloc(100 * sizeof(char));
	}
	
	for (int i = 0; i < N; i++) {
		printf("학번: ");
		scanf_s("%d", &stud_num[i]);

		printf("이름: ");
		scanf_s("%s", name[i], 100);

		printf("점수: ");
		scanf_s("%d", &score[i]);
	}

	for (int i = 0; i < N; i++) {
		printf("%d %s %d\n", stud_num[i], name[i], score[i]);
	}

	free(stud_num);
	free(name);
	free(score);
}