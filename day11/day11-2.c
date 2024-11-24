#include <stdio.h>
#include <math.h>

// 적분할 함수 정의
double func(double x) {
    return log10(x) + sin(x);
}

// 구분구적법 계산 함수
double trapezoidal_rule(int start, int end, int sections) {
    double width = (double)(end - start) / sections;
    double integral = 0.0;

    // 구간을 나누어 적분 수행
    for (int i = 0; i < sections; i++) {
        double x1 = start + i * width;
        double x2 = x1 + width;
        integral += (func(x1) + func(x2)) / 2 * width;
    }
    return integral;
}

int main() {
    int start, end, max;
    printf("적분할 시작 값을 입력하세요: ");
    scanf_s("%d", &start);
    printf("적분할 끝 값을 입력하세요: ");
    scanf_s("%d", &end);
    printf("시행할 최대 구간을 입력하세요(2^n): ");
    scanf_s("%d", &max);

    int sections = 1;
    for (int n = 0; n <= max; n++) {
        double result = trapezoidal_rule(start, end, sections);
        printf("구간 %d 적분 결과: %.6f\n", sections, result);
        sections *= 2; // 구간을 2배씩 증가
    }

    return 0;
}
