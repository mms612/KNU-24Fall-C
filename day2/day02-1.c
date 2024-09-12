#include<stdio.h>

int main() {
	int op;
	double num1, num2;
	double result = 0;

	printf("원하는 기능을 입력하시오.\n");
	printf("1.더하기 2.빼기 3.곱하기 4.나누기\n");
	printf("기능 : ");

	scanf_s("%d", &op);

	printf("첫 번째 수 : ");
	scanf_s("%lf", &num1);
	printf("두 번째 수 : ");
	scanf_s("%lf", &num2);

	if (op == 1) {
		result = num1 + num2;
	}
	else if(op == 2) {
		result = num1 - num2;
	}
	else if (op == 3){
		result = num1 * num2;
	}
	else if (op == 4){
		result = num1 / num2;
	}
	else {
		printf("잘못된 값\n");
		return 0;
	}

	printf(" 값 : %lf", result);

	return 0;
}