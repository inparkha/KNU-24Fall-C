#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �� ��� (�켱���� ����)
typedef enum {
    GOLD = 1,
    SILVER,
    BRONZE
} Rank;

// �� ����ü ����
typedef struct Customer {
    char* customerName;     // �� �̸�
    Rank rank;              // �� ���
    int order_amount;       // �� �ֹ���
    int point;              // ����Ʈ
    struct Customer* next;  // ���� ���
} Customer;

// ���� ����Ʈ�� ���� ���
Customer* head = NULL;

// �켱���� �� �Լ�
int comparePriority(Customer* a, Customer* b) {
    if (a->rank != b->rank)
        return a->rank - b->rank; // ��� �켱
    if (a->order_amount != b->order_amount)
        return b->order_amount - a->order_amount; // �ֹ���
    return b->point - a->point; // ����Ʈ
}

// �� �߰� �Լ�
void addCustomer(const char* name, Rank rank, int order_amount, int point) {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    newCustomer->customerName = _strdup(name); // strdup ��� _strdup ���
    newCustomer->rank = rank;
    newCustomer->order_amount = order_amount;
    newCustomer->point = point;
    newCustomer->next = NULL;

    // ����Ʈ�� ��� �ִ� ���
    if (head == NULL || comparePriority(newCustomer, head) < 0) {
        newCustomer->next = head;
        head = newCustomer;
        return;
    }

    // ������ ��ġ�� ����
    Customer* current = head;
    while (current->next != NULL && comparePriority(newCustomer, current->next) >= 0) {
        current = current->next;
    }
    newCustomer->next = current->next;
    current->next = newCustomer;
}

// ��ü ����Ʈ ��� �Լ�
void printCustomers() {
    Customer* current = head;
    printf("=== �� ����Ʈ ===\n");
    while (current != NULL) {
        printf("�̸�: %s, ���: %d, �ֹ���: %d, ����Ʈ: %d\n",
            current->customerName, current->rank, current->order_amount, current->point);
        current = current->next;
    }
    printf("=====================\n");
}

// ���� �Լ�
int main() {
    int choice;

    while (1) {
        printf("\n=== �� ���� �ý��� ===\n");
        printf("1. �� �߰�\n");
        printf("2. ��ü �� ����Ʈ ���\n");
        printf("3. ���α׷� ����\n");
        printf("���ϴ� �۾��� �����ϼ���: ");
        scanf_s("%d", &choice);

        if (choice == 1) {
            char name[100];
            int rank, order_amount, point;

            printf("�� �̸��� �Է��ϼ���: ");
            // fgets ����Ͽ� ���� ������ �̸� �Է� ó��
            getchar();  // �����ִ� newline ���� ����
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0; // �Է��� �̸����� �� �� ���� ����

            printf("�� ����� �Է��ϼ��� (1: GOLD, 2: SILVER, 3: BRONZE): ");
            scanf_s("%d", &rank);
            printf("�� �ֹ����� �Է��ϼ���: ");
            scanf_s("%d", &order_amount);
            printf("����Ʈ�� �Է��ϼ���: ");
            scanf_s("%d", &point);

            if (rank < 1 || rank > 3) {
                printf("�߸��� ����Դϴ�! �ùٸ� ����� �Է��ϼ��� (1: GOLD, 2: SILVER, 3: BRONZE).\n");
            }
            else {
                addCustomer(name, (Rank)rank, order_amount, point);
                printf("�� '%s' �߰��� �Ϸ�Ǿ����ϴ�.\n", name);
            }
        }
        else if (choice == 2) {
            printCustomers();
        }
        else if (choice == 3) {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }
        else {
            printf("�߸��� �����Դϴ�! �ٽ� �õ��ϼ���.\n");
        }
    }

    return 0;
}
