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
            printf("잘못된 입력입니다. 숫자를 입력하세요.\n");
            while (getchar() != '\n'); // 입력 버퍼 비우기
            continue;
        }

        switch (choice) {
        case 1:
            printf("학생 이름 : ");
            while (getchar() != '\n'); // 입력 버퍼 비우기
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0'; // 개행 문자 제거
            printf("%s의 성적 : ", name);
            if (scanf_s("%d", &score) != 1) {
                printf("잘못된 성적 입력입니다.\n");
                while (getchar() != '\n'); // 입력 버퍼 비우기
                continue;
            }
            addStudent(name, score);
            break;
        case 2:
            printf("삭제할 학생 이름 : ");
            while (getchar() != '\n'); // 입력 버퍼 비우기
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0'; // 개행 문자 제거
            deleteStudent(name);
            break;
        case 3:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 입력입니다. 다시 선택하세요.\n");
            break;
        }
        printStudents();
    }
    return 0;
}

void addStudent(char* name, int score) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("메모리 할당 실패\n");
        return;
    }

    strcpy_s(newStudent->name, sizeof(newStudent->name), name); // strcpy_s 사용
    newStudent->score = score;
    newStudent->next = NULL;

    // 점수 기준 정렬 삽입
    if (head == NULL || head->score < score) { // 새 노드를 맨 앞에 삽입
        newStudent->next = head;
        head = newStudent;
    }
    else {
        Student* temp = head;
        while (temp->next != NULL && temp->next->score >= score) { // 점수가 높은 순으로 삽입 위치 찾기
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
        printf("학생 %s을(를) 찾을 수 없습니다.\n", name);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    }
    else {
        prev->next = temp->next;
    }
    free(temp);
    printf("학생 %s의 정보가 삭제되었습니다.\n", name);
}

void printStudents() {
    if (head == NULL) {
        printf("\n학생 목록이 비어 있습니다.\n");
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
    printf("1. 학생의 성적을 입력\n");
    printf("2. 학생 정보 제거\n");
    printf("3. 프로그램 종료\n");
}
