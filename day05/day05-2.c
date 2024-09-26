#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int snum;       // �й�
    char name[100]; // �̸�
    int score;     // ����
} Student;

int main(void) {
    int N;
    Student* students;

    printf("�л� �� �Է�: ");
    if (scanf_s("%d", &N) != 1 || N <= 0) {
        fprintf(stderr, "�߸��� �Է�. ���� ������ �Է��ϼ���.\n");
        return 1;
    }

    students = (Student*)malloc(N * sizeof(Student));
    if (!students) {
        fprintf(stderr, "�޸� �Ҵ� ����.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        printf("�й�: ");
        scanf_s("%d", &students[i].snum);
        printf("�̸�: ");
        scanf_s("%99s", students[i].name); // Limit input to avoid buffer overflow
        printf("����: ");
        scanf_s("%d", &students[i].score);
    }

    printf("\n�л� ���:\n");
    for (int i = 0; i < N; i++) {
        printf("%d %s %d\n", students[i].snum, students[i].name, students[i].score);
    }

    free(students); // Free allocated memory

    return 0;
}
