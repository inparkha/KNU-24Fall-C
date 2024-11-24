#include <stdio.h>
#include <math.h>

// ������ �Լ� ����
double func(double x) {
    return log10(x) + sin(x);
}

// ���б����� ��� �Լ�
double trapezoidal_rule(int start, int end, int sections) {
    double width = (double)(end - start) / sections;
    double integral = 0.0;

    // ������ ������ ���� ����
    for (int i = 0; i < sections; i++) {
        double x1 = start + i * width;
        double x2 = x1 + width;
        integral += (func(x1) + func(x2)) / 2 * width;
    }
    return integral;
}

int main() {
    int start, end, max;
    printf("������ ���� ���� �Է��ϼ���: ");
    scanf_s("%d", &start);
    printf("������ �� ���� �Է��ϼ���: ");
    scanf_s("%d", &end);
    printf("������ �ִ� ������ �Է��ϼ���(2^n): ");
    scanf_s("%d", &max);

    int sections = 1;
    for (int n = 0; n <= max; n++) {
        double result = trapezoidal_rule(start, end, sections);
        printf("���� %d ���� ���: %.6f\n", sections, result);
        sections *= 2; // ������ 2�辿 ����
    }

    return 0;
}
