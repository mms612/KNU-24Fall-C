int solution(int n) {
    int battery = 0;

    while (n > 0) {
        // ���� ��ġ�� Ȧ���� ��� ����
        if (n % 2 == 1) {
            battery++;
            n -= 1; // ����
        }
        else {
            n /= 2; // �����̵�
        }
    }

    return battery;
}