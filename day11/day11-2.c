#include <stdio.h>
#include <math.h>

int main() {
    float start, end; // ���� ���� ���� �� ��
    int n;
    long range;             // ���� ����
    double width;      // �� ���簢���� �ʺ�
    double result = 0.0; // ���� �� (�ʱ�ȭ)
    int i = 1;

    // ����� �Է�
    printf("���� ���� ���� �Է��ϼ���: ");
    scanf_s("%f", &start);
    printf("���� �� ���� �Է��ϼ���: ");
    scanf_s("%f", &end);
    printf("������ ������ �Է��ϼ���(2^n): ");
    scanf_s("%d", &n);

    
    for (i; i <= n; i++){
        range = pow(2, i);//���簢�� ������
        width = (end - start) / range;// ������ �ʺ� ���

        // ���б��������� ���� �� ���
        for (int j = 0; j < range; j++) {
            double x = start + j * width; // ���簢���� x��
            double y = -log10(1 / x) + sin(x); // �Լ��� (����)
            result += y * width;  // ���̸� ����
        }

        printf("���� %d���� ����: %.10lf\n", range, result);

        result = 0;
    }

    return 0;
}