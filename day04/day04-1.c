#include <stdio.h>
#include <stdlib.h>

int* ptr1;
int* ptr2;

void swap(int* ptr1, int* ptr2) {
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

int main() {
	int a = 10;
	int b = 20;


	printf("%d\n", a);
	printf("%d\n", b);

	ptr1 = &a;
	ptr2 = &b;
	swap(&a, &b);

	printf("%d\n", a);
	printf("%d\n", b);

	return 0;
}