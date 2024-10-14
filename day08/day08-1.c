#include<stdio.h>

int main(void) {
	char str[100];
	char* end = str;
	char* start = str;

	printf("문자열을 입력하세요 : ");
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

	printf("뒤집어진 문자열 : %s\n", str);

	return 0;
}
