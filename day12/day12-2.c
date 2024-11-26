int solution(int n) {
    int battery = 0;

    // N�� 0�� �� ������ ó��
    while (n > 0) {
        // ���� ��ġ�� Ȧ���� ��� ���� �ʿ�
        if (n % 2 == 1) {
            battery++;
            n -= 1; // �����Ͽ� 1 ����
        }
        else {
            n /= 2; // �����̵� (������ ��뷮 ���� ����)
        }
    }

    return battery;
}