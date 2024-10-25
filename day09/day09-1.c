#include <stdio.h>

struct Vector {
    int x;
    int y;
    int z;
};

struct Vector vector_add(struct Vector v1, struct Vector v2) {
    struct Vector result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    return result;
}

struct Vector vector_substract(struct Vector v1, struct Vector v2) {
    struct Vector result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return result;
}

struct Vector vector_cross(struct Vector v1, struct Vector v2) {
    struct Vector result;
    result.x = (v1.y * v2.z) - (v1.z * v2.y);
    result.y = (v1.z * v2.x) - (v1.x * v2.z);
    result.z = (v1.x * v2.y) - (v1.y * v2.x);
    return result;
}

struct Vector vector_dot(struct Vector v1, struct Vector v2) {
    struct Vector result;
    result.x = v1.x * v2.x;
    result.y = v1.y * v2.y;
    result.z = v1.z * v2.z;
    return result;
}

int main() {
    struct Vector v1;
    struct Vector v2;
    struct Vector result;
    int num;
    printf("첫번째 벡터 : ");
    scanf_s("%d %d %d", &v1.x, &v1.y, &v1.z);
    getchar();
    printf("두번째 벡터 : ");
    scanf_s("%d %d %d", &v2.x, &v2.y, &v2.z);
    printf("입력된 첫번째 벡터   %d   %d   %d\n", v1.x, v1.y, v1.z);
    printf("입력된 두번째 벡터   %d   %d   %d\n", v2.x, v2.y, v2.z);
    printf("1. 벡터의 합\n2. 벡터의 차\n3. 벡터의 외적\n4. 벡터의 내적\n5. 종료\n");
    printf("명령 입력 : ");
    scanf_s("%d", &num);

    switch (num) {
        case 1: {
            result = vector_add(v1, v2);
            printf("벡터의 합은 v1 + v2 = (%d, %d, %d)\n", result.x, result.y, result.z);
            break;
        }
        case 2: {
            result = vector_substract(v1, v2);
            printf("벡터의 차는 v1 - v2 = (%d, %d, %d)\n", result.x, result.y, result.z);
            break;
        }
        case 3: {
            result = vector_cross(v1, v2);
            printf("벡터의 외적은 v1 * v2 = (%d, %d, %d)\n", result.x, result.y, result.z);
            break;
        }
        case 4: {
            result = vector_dot(v1, v2);
            printf("벡터의 내적은 v1 ~ v2 = %d\n", (result.x + result.y + result.z));
            break;
        }
    }

    return 0;
}