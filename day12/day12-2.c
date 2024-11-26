int solution(int n) {
    int battery = 0;

    // N이 0이 될 때까지 처리
    while (n > 0) {
        // 현재 위치가 홀수일 경우 점프 필요
        if (n % 2 == 1) {
            battery++;
            n -= 1; // 점프하여 1 감소
        }
        else {
            n /= 2; // 순간이동 (건전지 사용량 증가 없음)
        }
    }

    return battery;
}