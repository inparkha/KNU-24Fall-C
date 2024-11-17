#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 고객 등급 (우선순위 기준)
typedef enum {
    GOLD = 1,
    SILVER,
    BRONZE
} Rank;

// 고객 구조체 정의
typedef struct Customer {
    char* customerName;     // 고객 이름
    Rank rank;              // 고객 등급
    int order_amount;       // 총 주문량
    int point;              // 포인트
    struct Customer* next;  // 다음 노드
} Customer;

// 연결 리스트의 시작 노드
Customer* head = NULL;

// 우선순위 비교 함수
int comparePriority(Customer* a, Customer* b) {
    if (a->rank != b->rank)
        return a->rank - b->rank; // 등급 우선
    if (a->order_amount != b->order_amount)
        return b->order_amount - a->order_amount; // 주문량
    return b->point - a->point; // 포인트
}

// 고객 추가 함수
void addCustomer(const char* name, Rank rank, int order_amount, int point) {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    newCustomer->customerName = _strdup(name); // strdup 대신 _strdup 사용
    newCustomer->rank = rank;
    newCustomer->order_amount = order_amount;
    newCustomer->point = point;
    newCustomer->next = NULL;

    // 리스트가 비어 있는 경우
    if (head == NULL || comparePriority(newCustomer, head) < 0) {
        newCustomer->next = head;
        head = newCustomer;
        return;
    }

    // 적절한 위치에 삽입
    Customer* current = head;
    while (current->next != NULL && comparePriority(newCustomer, current->next) >= 0) {
        current = current->next;
    }
    newCustomer->next = current->next;
    current->next = newCustomer;
}

// 전체 리스트 출력 함수
void printCustomers() {
    Customer* current = head;
    printf("=== 고객 리스트 ===\n");
    while (current != NULL) {
        printf("이름: %s, 등급: %d, 주문량: %d, 포인트: %d\n",
            current->customerName, current->rank, current->order_amount, current->point);
        current = current->next;
    }
    printf("=====================\n");
}

// 메인 함수
int main() {
    int choice;

    while (1) {
        printf("\n=== 고객 관리 시스템 ===\n");
        printf("1. 고객 추가\n");
        printf("2. 전체 고객 리스트 출력\n");
        printf("3. 프로그램 종료\n");
        printf("원하는 작업을 선택하세요: ");
        scanf_s("%d", &choice);

        if (choice == 1) {
            char name[100];
            int rank, order_amount, point;

            printf("고객 이름을 입력하세요: ");
            // fgets 사용하여 공백 포함한 이름 입력 처리
            getchar();  // 남아있는 newline 문자 제거
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0; // 입력한 이름에서 새 줄 문자 제거

            printf("고객 등급을 입력하세요 (1: GOLD, 2: SILVER, 3: BRONZE): ");
            scanf_s("%d", &rank);
            printf("총 주문량을 입력하세요: ");
            scanf_s("%d", &order_amount);
            printf("포인트를 입력하세요: ");
            scanf_s("%d", &point);

            if (rank < 1 || rank > 3) {
                printf("잘못된 등급입니다! 올바른 등급을 입력하세요 (1: GOLD, 2: SILVER, 3: BRONZE).\n");
            }
            else {
                addCustomer(name, (Rank)rank, order_amount, point);
                printf("고객 '%s' 추가가 완료되었습니다.\n", name);
            }
        }
        else if (choice == 2) {
            printCustomers();
        }
        else if (choice == 3) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("잘못된 선택입니다! 다시 시도하세요.\n");
        }
    }

    return 0;
}
