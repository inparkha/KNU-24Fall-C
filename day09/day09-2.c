#include <stdio.h>
#include <stdlib.h>

struct Product {
    int id;
    char name[100];
    int price;
};

void printProduct(struct Product p) {
    printf("상품 ID: %d\n", p.id);
    printf("상품명: %s\n", p.name);
    printf("가격: %d\n", p.price);
}

int main(void) {
    struct Product products[5];
    int count = 0;


    while (count < 5) {
        printf("\n상품 정보를 입력하세요 (입력 중단은 ID에 0 입력)\n");
        printf("상품 ID: ");
        scanf_s("%d", &products[count].id);
        getchar();  // 버퍼에 남은 개행 문자를 제거

        if (products[count].id == 0) {
            break;  // ID가 0이면 입력 중단
        }

        printf("상품명: ");
        scanf_s("%s", products[count].name, (unsigned)_countof(products[count].name));

        printf("가격: ");
        scanf_s("%d", &products[count].price);
        getchar();  // 다시 한 번 개행 문자를 제거

        count++;
    }

    printf("\n<<입력된 상품 목록>>\n");
    for (int i = 0; i < count; i++) {
        printProduct(products[i]);
        printf("\n");
    }

    return 0;
}
