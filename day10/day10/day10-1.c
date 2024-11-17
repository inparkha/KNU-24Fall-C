#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int score;
    struct Student* next;
} Student;

Student* head = NULL;

void addStudent(char* name, int score);
void deleteStudent(char* name);
void printStudents();
void menu();

int main() {
    int choice;
    char name[50];
    int score;

    while (1) {
        menu();
        printf("input : ");
        if (scanf_s("%d", &choice) != 1) {
            printf("�߸��� �Է��Դϴ�. ���ڸ� �Է��ϼ���.\n");
            while (getchar() != '\n'); // �Է� ���� ����
            continue;
        }

        switch (choice) {
        case 1:
            printf("�л� �̸� : ");
            while (getchar() != '\n'); // �Է� ���� ����
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0'; // ���� ���� ����
            printf("%s�� ���� : ", name);
            if (scanf_s("%d", &score) != 1) {
                printf("�߸��� ���� �Է��Դϴ�.\n");
                while (getchar() != '\n'); // �Է� ���� ����
                continue;
            }
            addStudent(name, score);
            break;
        case 2:
            printf("������ �л� �̸� : ");
            while (getchar() != '\n'); // �Է� ���� ����
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0'; // ���� ���� ����
            deleteStudent(name);
            break;
        case 3:
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n");
            break;
        }
        printStudents();
    }
    return 0;
}

void addStudent(char* name, int score) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return;
    }

    strcpy_s(newStudent->name, sizeof(newStudent->name), name); // strcpy_s ���
    newStudent->score = score;
    newStudent->next = NULL;

    // ���� ���� ���� ����
    if (head == NULL || head->score < score) { // �� ��带 �� �տ� ����
        newStudent->next = head;
        head = newStudent;
    }
    else {
        Student* temp = head;
        while (temp->next != NULL && temp->next->score >= score) { // ������ ���� ������ ���� ��ġ ã��
            temp = temp->next;
        }
        newStudent->next = temp->next;
        temp->next = newStudent;
    }
}

void deleteStudent(char* name) {
    Student* temp = head;
    Student* prev = NULL;

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("�л� %s��(��) ã�� �� �����ϴ�.\n", name);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    }
    else {
        prev->next = temp->next;
    }
    free(temp);
    printf("�л� %s�� ������ �����Ǿ����ϴ�.\n", name);
}

void printStudents() {
    if (head == NULL) {
        printf("\n�л� ����� ��� �ֽ��ϴ�.\n");
        return;
    }
    Student* temp = head;
    printf("\n-----------------------------\n");
    while (temp != NULL) {
        printf("%s : %d\n", temp->name, temp->score);
        temp = temp->next;
    }
    printf("-----------------------------\n\n");
}

void menu() {
    printf("1. �л��� ������ �Է�\n");
    printf("2. �л� ���� ����\n");
    printf("3. ���α׷� ����\n");
}
