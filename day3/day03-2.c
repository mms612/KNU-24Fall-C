#include <stdio.h>

int fac(int num);

int main(void) {
	int num;

	printf("����� ���丮�� �� �Է� : ");
	scanf_s("%d", &num);
	int result = fac(num);
	printf("%d\n", result);

	return 0;
}

int fac(int num) {
	int result = 0;

	if (num == 0 || num == 1) {
		return 1;
	}

	result = num * fac(num - 1);

	return result;
}