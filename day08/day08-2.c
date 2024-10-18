#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);

int main(void) {
	int array[SIZE][SIZE];

	fillRandom(array);
	printArray(array);
	movePointer(array);

	return 0;
}

void fillRandom(int array[SIZE][SIZE]) {
	
	int ran;
	
	srand(time(NULL));

	for (int cnt1 = 0; cnt1 <= 9; cnt1++) {
		for (int cnt2 = 0; cnt2 <= 9; cnt2++) {
			ran = rand() % 20 + 1;
			array[cnt1][cnt2] = ran;
		}
	}
}

void printArray(int array[SIZE][SIZE]) {
	
	printf("배열 출력:\n");
	for (int cnt2 = 0; cnt2 <= 9; cnt2++) {
		for (int cnt3 = 0; cnt3 <= 9; cnt3++) {
			printf("%d\t", array[cnt2][cnt3]);
		}
		printf("\n");
	}
	
}

void movePointer(void* array) {
	int(*arr)[SIZE] = (int(*)[SIZE])array;
	int x = 0, y = 0;
	int value;

	while (1) {
		value = arr[x][y];
		printf("현재 위치 : (%d, %d), 배열의 값 : %d\n", x, y, value);

		int new_x = x;
		int new_y = y + value;

		if (new_y >= 10) {
			new_x = new_x + new_y / 10;
			new_y = new_y % 10;
		}

		if (new_x >= 10) {
			printf("더 이상 이동할 수 없습니다.\n종료 위치: (%d, %d), 배열의 값 : %d\n", x, y, value);
			break;
		}

		x = new_x;
		y = new_y;
	}
}
