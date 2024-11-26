int solution(int n) {
    int battery = 0;

    while (n > 0) {
        // 현재 위치가 홀수일 경우 점프
        if (n % 2 == 1) {
            battery++;
            n -= 1; // 점프
        }
        else {
            n /= 2; // 순간이동
        }
    }

    return battery;
}