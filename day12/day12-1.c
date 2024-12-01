#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_TOPPING 10001 // ���� ��ȣ�� �ִ밪

// topping_len�� �迭 topping�� �����Դϴ�.
int solution(int topping[], size_t topping_len) {
    int answer = 0;

    // �� ������ ������ ������ �迭
    int left_count[MAX_TOPPING] = { 0 };
    int right_count[MAX_TOPPING] = { 0 };

    // ������ ������ ���� ��
    int right_unique = 0;

    // �ʱ� ����: ��� ������ �����ʿ� ��ġ
    for (size_t i = 0; i < topping_len; i++) {
        if (right_count[topping[i]] == 0) {
            right_unique++; // ���ο� ���� �߰�
        }
        right_count[topping[i]]++;
    }

    // �����̵� �����츦 �̿��Ͽ� ����/������ ���� �и�
    int left_unique = 0;

    for (size_t i = 0; i < topping_len; i++) {
        // ���� ������ �������� �̵�
        if (left_count[topping[i]] == 0) {
            left_unique++; // ���ο� ���� �߰�
        }
        left_count[topping[i]]++;

        // �����ʿ��� ���� ���� ����
        right_count[topping[i]]--;
        if (right_count[topping[i]] == 0) {
            right_unique--; // ������ �����ʿ��� ������
        }

        // �����ϰ� ���� �� �ִ��� Ȯ��
        if (left_unique == right_unique) {
            answer++;
        }
    }

    return answer;
}

// �׽�Ʈ ���� �Լ�
int main() {
    int topping1[] = { 1, 2, 1, 3, 1, 4, 1, 2 };
    size_t topping_len1 = sizeof(topping1) / sizeof(topping1[0]);
    printf("Result: %d\n", solution(topping1, topping_len1)); // ���: 2

    int topping2[] = { 1, 2, 3, 1, 4 };
    size_t topping_len2 = sizeof(topping2) / sizeof(topping2[0]);
    printf("Result: %d\n", solution(topping2, topping_len2)); // ���: 0

    return 0;
}
