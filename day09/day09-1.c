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
    printf("ù��° ���� : ");
    scanf_s("%d %d %d", &v1.x, &v1.y, &v1.z);
    getchar();
    printf("�ι�° ���� : ");
    scanf_s("%d %d %d", &v2.x, &v2.y, &v2.z);
    printf("�Էµ� ù��° ����   %d   %d   %d\n", v1.x, v1.y, v1.z);
    printf("�Էµ� �ι�° ����   %d   %d   %d\n", v2.x, v2.y, v2.z);
    printf("1. ������ ��\n2. ������ ��\n3. ������ ����\n4. ������ ����\n5. ����\n");
    printf("��� �Է� : ");
    scanf_s("%d", &num);

    switch (num) {
        case 1: {
            result = vector_add(v1, v2);
            printf("������ ���� v1 + v2 = (%d, %d, %d)\n", result.x, result.y, result.z);
            break;
        }
        case 2: {
            result = vector_substract(v1, v2);
            printf("������ ���� v1 - v2 = (%d, %d, %d)\n", result.x, result.y, result.z);
            break;
        }
        case 3: {
            result = vector_cross(v1, v2);
            printf("������ ������ v1 * v2 = (%d, %d, %d)\n", result.x, result.y, result.z);
            break;
        }
        case 4: {
            result = vector_dot(v1, v2);
            printf("������ ������ v1 ~ v2 = %d\n", (result.x + result.y + result.z));
            break;
        }
    }

    return 0;
}