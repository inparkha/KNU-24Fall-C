#include <stdio.h>
#include <stdlib.h>

struct Product {
    int id;
    char name[100];
    int price;
};

void printProduct(struct Product p) {
    printf("��ǰ ID: %d\n", p.id);
    printf("��ǰ��: %s\n", p.name);
    printf("����: %d\n", p.price);
}

int main(void) {
    struct Product products[5];
    int count = 0;


    while (count < 5) {
        printf("\n��ǰ ������ �Է��ϼ��� (�Է� �ߴ��� ID�� 0 �Է�)\n");
        printf("��ǰ ID: ");
        scanf_s("%d", &products[count].id);
        getchar();  // ���ۿ� ���� ���� ���ڸ� ����

        if (products[count].id == 0) {
            break;  // ID�� 0�̸� �Է� �ߴ�
        }

        printf("��ǰ��: ");
        scanf_s("%s", products[count].name, (unsigned)_countof(products[count].name));

        printf("����: ");
        scanf_s("%d", &products[count].price);
        getchar();  // �ٽ� �� �� ���� ���ڸ� ����

        count++;
    }

    printf("\n<<�Էµ� ��ǰ ���>>\n");
    for (int i = 0; i < count; i++) {
        printProduct(products[i]);
        printf("\n");
    }

    return 0;
}
