#include <stdio.h>
#include <math.h>

int main(void) {
	float a, b, c, pl, mi;

	printf("ax^2 + bx + c = 0에서 a,b,c의 값을 채우세요\n");
	printf("a: ");
	scanf_s("%f", &a);
	printf("b: ");
	scanf_s("%f", &b);
	printf("c: ");
	scanf_s("%f", &c);

	pl = (-b + sqrt(b*b - 4.0 * a * c)) / 2 * a;
	mi = (-b - sqrt(b*b - 4.0 * a * c)) / 2 * a;

	printf("근: ");

	if ((b * b - 4.0 * a * c) == 0) {
		printf("%.2f\n", pl);
	}
	else if ((b * b - 4.0 * a * c) > 0) {
		printf("%.2f %.2f\n", pl, mi);
	}
	else {
		printf("허근입니다.\n");
	}

	return 0;
}