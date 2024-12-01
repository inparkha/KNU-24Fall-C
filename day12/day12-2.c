#include <stdio.h>

int solution(int n) {
    int battery_usage = 0;

    // 순간이동과 점프를 역순으로 계산
    while (n > 0) {
        if (n % 2 == 0) {
            // 짝수일 때는 순간이동 (배터리 소모 없음)
            n /= 2;
        }
        else {
            // 홀수일 때는 점프 (배터리 소모)
            n -= 1;
            battery_usage++;
        }
    }

    return battery_usage;
}

// 테스트 실행
int main() {
    printf("Result for 5: %d\n", solution(5));     // 출력: 2
    printf("Result for 6: %d\n", solution(6));     // 출력: 2
    printf("Result for 5000: %d\n", solution(5000)); // 출력: 5
    return 0;
}
