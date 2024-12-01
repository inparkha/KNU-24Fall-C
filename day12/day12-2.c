#include <stdio.h>

int solution(int n) {
    int battery_usage = 0;

    // �����̵��� ������ �������� ���
    while (n > 0) {
        if (n % 2 == 0) {
            // ¦���� ���� �����̵� (���͸� �Ҹ� ����)
            n /= 2;
        }
        else {
            // Ȧ���� ���� ���� (���͸� �Ҹ�)
            n -= 1;
            battery_usage++;
        }
    }

    return battery_usage;
}

// �׽�Ʈ ����
int main() {
    printf("Result for 5: %d\n", solution(5));     // ���: 2
    printf("Result for 6: %d\n", solution(6));     // ���: 2
    printf("Result for 5000: %d\n", solution(5000)); // ���: 5
    return 0;
}