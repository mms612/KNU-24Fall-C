#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int N;
	int* snum;
	int* score;
	char** name;

	printf("�л� �� �Է� : ");
	scanf_s("%d", &N);

	snum = (int*)malloc(N * sizeof(int));
	score = (int*)malloc(N * sizeof(int));


	name = (char**)malloc(N * sizeof(char*));
	for (int i = 0; i < N; i++) {
		name[i] = (char*)malloc(100 * sizeof(char));
	}

	for (int i = 0; i < N; i++) {
		printf("�й�: ");
		scanf_s("%d", &snum[i]);
		printf("�̸�: ");
		scanf_s("%s", name[i], 100);
		printf("����: ");
		scanf_s("%d", &score[i]);
	}
	
	for (int i = 0; i < N; i++) {
		printf("%d %s %d\n", snum[i], name[i], score[i]);
	}

	free(snum);
	snum = NULL;
	free(score);
	score = NULL;
	free(name);
	name = NULL;

	return 0;
}