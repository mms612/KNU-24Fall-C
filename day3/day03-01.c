#include <stdio.h>

int prime_number(int num);

int main(void) {
	int num;

	printf("�� �Է� : ");
	scanf_s("%d", &num);
	int result = prime_number(num);
	printf("result = %d\n", result);

	return 0;
}

int prime_number(int num) {

	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}