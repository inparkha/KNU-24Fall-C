#include <stdio.h>
#include <math.h>


double quadratic_formula_1(int a, int b, int c, int D) {
	double x1;

	x1 = (-1 * b + sqrt(D)) / (2.0 * a);
	return x1;
}
double quadratic_formula_2(int a, int b, int c, int D) {
	double x2;

	x2 = (-1 * b - sqrt(D)) / (2.0 * a);
	return x2;
}

int main() {
	int a, b, c;
	double D, sun1, sun2;
	
	printf("근의 공식의 a, b, c 값을 차례로 입력하세요: ");
	scanf_s("%d %d %d", &a, &b, &c);
	D = pow(b, 2) - (4 * a * c);

	if (D < 0) {
		printf("허근입니다.");
	}
	else if (D == 0) {
		sun1 = quadratic_formula_1(a, b, c, D);
		printf("중근입니다.\n");
		printf("근의 값은 %.2f입니다.\n", sun1);
	}
	else if (D > 0) {
		sun1 = quadratic_formula_1(a, b, c, D);
		sun2 = quadratic_formula_2(a, b, c, D);
		printf("서로 다른 두 실근입니다.\n");
		printf("근의 값은 %.2f, %.2f입니다.\n", sun1, sun2);
	}
}