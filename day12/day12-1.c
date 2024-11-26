#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// topping_len�� �迭 topping�� �����Դϴ�.
int solution(int topping[], size_t topping_len) {
    int max_topping = 0;
    //�ִ����� ��� ���
    for (int i = 0; i < topping_len; i++) {
        if (topping[i] > max_topping) {
            max_topping = topping[i];
        }
    }

    // ���ʰ� �������� ���� ������ ����� �迭 �Ҵ�
    int left_topping[max_topping + 1];
    int right_topping[max_topping + 1];
    for (int i = 0; i <= max_topping; i++) {
        left_topping[i] = 0;
        right_topping[i] = 0;
    }

    // ��� ������ �ʱ⿡�� �����ʿ� �߰�
    for (int i = 0; i < topping_len; i++) {
        right_topping[topping[i]]++;
    }

    // �������� ���� ���� ���� ���
    int left = 0;
    int right = 0;
    for (int i = 1; i <= max_topping; i++) {
        if (right_topping[i] > 0) {
            right++;
        }
    }

    int cut_count = 0;

    // ������ũ�� �ϳ��� �ڸ��� ó��
    for (int i = 0; i < topping_len - 1; i++) {
        int current_topping = topping[i];

        // �������� ���� �߰�
        if (left_topping[current_topping] == 0) {
            left++;
        }
        left_topping[current_topping]++;

        // �����ʿ��� ���� ����
        right_topping[current_topping]--;
        if (right_topping[current_topping] == 0) {
            right--;
        }

        // �����ϰ� ���������� Ȯ��
        if (left == right) {
            cut_count++;
        }
    }

    return cut_count;
}