#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int snum;       
    char name[100]; 
    int score;     
} Student;

int main(void) {
    int N;
    Student* students;

    printf("학생 수 입력: ");
    

    students = (Student*)malloc(N * sizeof(Student));
    if (!students) {
        fprintf(stderr, "메모리 할당 실패.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        printf("학번: ");
        scanf_s("%d", &students[i].snum);
        printf("이름: ");
        scanf_s("%99s", students[i].name);
        printf("점수: ");
        scanf_s("%d", &students[i].score);
    }

 
    for (int i = 0; i < N; i++) {
        printf("%d %s %d\n", students[i].snum, students[i].name, students[i].score);
    }

    free(students);

    return 0;
}
