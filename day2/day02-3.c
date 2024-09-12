#include<stdio.h>

int main() {
	for (int a = 0; a < 100; a++) {
		if ((a % 3 == 0 && a % 4 == 0) || a % 7 == 0) {
			printf("%d  ", a);
		}
	}
	return 0;
}