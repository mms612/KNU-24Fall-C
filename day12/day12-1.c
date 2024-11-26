#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int max_topping = 0;
    //최대토핑 계수 계산
    for (int i = 0; i < topping_len; i++) {
        if (topping[i] > max_topping) {
            max_topping = topping[i];
        }
    }

    // 왼쪽과 오른쪽의 토핑 종류를 기록할 배열 할당
    int left_topping[max_topping + 1];
    int right_topping[max_topping + 1];
    for (int i = 0; i <= max_topping; i++) {
        left_topping[i] = 0;
        right_topping[i] = 0;
    }

    // 모든 토핑을 초기에는 오른쪽에 추가
    for (int i = 0; i < topping_len; i++) {
        right_topping[topping[i]]++;
    }

    // 오른쪽의 고유 토핑 개수 계산
    int left = 0;
    int right = 0;
    for (int i = 1; i <= max_topping; i++) {
        if (right_topping[i] > 0) {
            right++;
        }
    }

    int cut_count = 0;

    // 롤케이크를 하나씩 자르며 처리
    for (int i = 0; i < topping_len - 1; i++) {
        int current_topping = topping[i];

        // 왼쪽으로 토핑 추가
        if (left_topping[current_topping] == 0) {
            left++;
        }
        left_topping[current_topping]++;

        // 오른쪽에서 토핑 제거
        right_topping[current_topping]--;
        if (right_topping[current_topping] == 0) {
            right--;
        }

        // 공평하게 나뉘었는지 확인
        if (left == right) {
            cut_count++;
        }
    }

    return cut_count;
}