#include<stdio.h>

int main() {
	int op;
	double num1, num2;
	double result = 0;

	printf("���ϴ� ����� �Է��Ͻÿ�.\n");
	printf("1.���ϱ� 2.���� 3.���ϱ� 4.������\n");
	printf("��� : ");

	scanf_s("%d", &op);

	printf("ù ��° �� : ");
	scanf_s("%lf", &num1);
	printf("�� ��° �� : ");
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
		printf("�߸��� ��\n");
		return 0;
	}

	printf(" �� : %lf", result);

	return 0;
}