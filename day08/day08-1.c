#include<stdio.h>

int main(void) {
	char str[100];
	char* end = str;
	char* start = str;

	printf("���ڿ��� �Է��ϼ��� : ");
	scanf_s("%s", str,sizeof(str));

	while (*end != '\0') {
		end++;
	}

	end--;

	while (start < end) {
		char a = *start;
		*start = *end;
		*end = a;
		start++;
		end--;
	}

	printf("�������� ���ڿ� : %s\n", str);

	return 0;
}
