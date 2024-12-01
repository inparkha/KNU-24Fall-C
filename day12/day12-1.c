#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_TOPPING 10001 // 토핑 번호의 최대값

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int answer = 0;

    // 각 토핑의 개수를 저장할 배열
    int left_count[MAX_TOPPING] = { 0 };
    int right_count[MAX_TOPPING] = { 0 };

    // 오른쪽 토핑의 종류 수
    int right_unique = 0;

    // 초기 상태: 모든 토핑을 오른쪽에 배치
    for (size_t i = 0; i < topping_len; i++) {
        if (right_count[topping[i]] == 0) {
            right_unique++; // 새로운 토핑 발견
        }
        right_count[topping[i]]++;
    }

    // 슬라이딩 윈도우를 이용하여 왼쪽/오른쪽 토핑 분리
    int left_unique = 0;

    for (size_t i = 0; i < topping_len; i++) {
        // 현재 토핑을 왼쪽으로 이동
        if (left_count[topping[i]] == 0) {
            left_unique++; // 새로운 토핑 발견
        }
        left_count[topping[i]]++;

        // 오른쪽에서 현재 토핑 제거
        right_count[topping[i]]--;
        if (right_count[topping[i]] == 0) {
            right_unique--; // 토핑이 오른쪽에서 없어짐
        }

        // 공평하게 나눌 수 있는지 확인
        if (left_unique == right_unique) {
            answer++;
        }
    }

    return answer;
}

// 테스트 실행 함수
int main() {
    int topping1[] = { 1, 2, 1, 3, 1, 4, 1, 2 };
    size_t topping_len1 = sizeof(topping1) / sizeof(topping1[0]);
    printf("Result: %d\n", solution(topping1, topping_len1)); // 출력: 2

    int topping2[] = { 1, 2, 3, 1, 4 };
    size_t topping_len2 = sizeof(topping2) / sizeof(topping2[0]);
    printf("Result: %d\n", solution(topping2, topping_len2)); // 출력: 0

    return 0;
}
