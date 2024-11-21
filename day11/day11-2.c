#include <stdio.h>
#include <math.h>

int main() {
    float start, end; // 적분 시작 값과 끝 값
    int n;
    long range;             // 구간 개수
    double width;      // 각 직사각형의 너비
    double result = 0.0; // 적분 값 (초기화)
    int i = 1;

    // 사용자 입력
    printf("적분 시작 값을 입력하세요: ");
    scanf_s("%f", &start);
    printf("적분 끝 값을 입력하세요: ");
    scanf_s("%f", &end);
    printf("구간의 개수를 입력하세요(2^n): ");
    scanf_s("%d", &n);

    
    for (i; i <= n; i++){
        range = pow(2, i);//직사각형 증가값
        width = (end - start) / range;// 구간의 너비 계산

        // 구분구적법으로 적분 값 계산
        for (int j = 0; j < range; j++) {
            double x = start + j * width; // 직사각형의 x값
            double y = -log10(1 / x) + sin(x); // 함수값 (높이)
            result += y * width;  // 넓이를 누적
        }

        printf("구간 %d적분 값은: %.10lf\n", range, result);

        result = 0;
    }

    return 0;
}