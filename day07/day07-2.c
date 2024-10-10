#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {

	double x = 0;
	double y = 0;
	double pi;

	int count = 0, circle = 0;

	srand(time(NULL));

	for (int i = 1; i <= 100; i++) {
		while (count < 10000000 * i) {
			x = (double)rand() / (double)RAND_MAX;
			y = (double)rand() / (double)RAND_MAX;
			count++;

			if ((x * x) + (y * y) < 1.0) {
				circle++;
			}

			pi = 4.0 * circle / count;
		}
		printf("%d%% 진행 ... 원주율: %f\n", i, pi);


	}
	

}