#include <stdio.h>
#include <math.h>

int main(void) {
	float a, b, c, pl, mi;

	printf("ax^2 + bx + c = 0���� a,b,c�� ���� ä�켼��\n");
	printf("a: ");
	scanf_s("%f", &a);
	printf("b: ");
	scanf_s("%f", &b);
	printf("c: ");
	scanf_s("%f", &c);

	pl = (-b + sqrt(b*b - 4.0 * a * c)) / 2 * a;
	mi = (-b - sqrt(b*b - 4.0 * a * c)) / 2 * a;

	printf("��: ");

	if ((b * b - 4.0 * a * c) == 0) {
		printf("%.2f\n", pl);
	}
	else if ((b * b - 4.0 * a * c) > 0) {
		printf("%.2f %.2f\n", pl, mi);
	}
	else {
		printf("����Դϴ�.\n");
	}

	return 0;
}