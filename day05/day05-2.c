#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int snum;       // 학번
    char name[100]; // 이름
    int score;     // 점수
} Student;

int main(void) {
    int N;
    Student* students;

    printf("학생 수 입력: ");
    if (scanf_s("%d", &N) != 1 || N <= 0) {
        fprintf(stderr, "잘못된 입력. 양의 정수를 입력하세요.\n");
        return 1;
    }

    students = (Student*)malloc(N * sizeof(Student));
    if (!students) {
        fprintf(stderr, "메모리 할당 실패.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        printf("학번: ");
        scanf_s("%d", &students[i].snum);
        printf("이름: ");
        scanf_s("%99s", students[i].name); // Limit input to avoid buffer overflow
        printf("점수: ");
        scanf_s("%d", &students[i].score);
    }

    printf("\n학생 목록:\n");
    for (int i = 0; i < N; i++) {
        printf("%d %s %d\n", students[i].snum, students[i].name, students[i].score);
    }

    free(students); // Free allocated memory

    return 0;
}
