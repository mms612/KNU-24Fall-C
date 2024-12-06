#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define HEIGHT 25
#define WIDTH 30
#define MAX_LENGTH 100

int gameover, score;
int snakeX[MAX_LENGTH], snakeY[MAX_LENGTH]; // ������ũ�� ���� ��ǥ
int fruitX, fruitY;
int length = 1; // ������ũ�� �ʱ� ����
int direction; // ���� ����

void setup() {
    gameover = 0;
    direction = 0; // �ʱ� ����: ����
    snakeX[0] = HEIGHT / 2;
    snakeY[0] = WIDTH / 2;

    // ������ �ʱ� ��ġ
    fruitX = rand() % (HEIGHT - 2) + 1;
    fruitY = rand() % (WIDTH - 2) + 1;

    score = 0;
}

void draw() {
    system("cls");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                printf("#");
            }
            else if (i == fruitX && j == fruitY) {
                printf("*");
            }
            else {
                int isBody = 0;
                for (int k = 0; k < length; k++) {
                    if (snakeX[k] == i && snakeY[k] == j) {
                        printf("0");
                        isBody = 1;
                        break;
                    }
                }
                if (!isBody) printf(" ");
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
    printf("Press X to quit the game\n");
}

void input() {
    if (_kbhit()) {
        switch (getch()) {
        case 'a': direction = 1; break; // ����
        case 's': direction = 2; break; // �Ʒ�
        case 'd': direction = 3; break; // ������
        case 'w': direction = 4; break; // ��
        case 'x': gameover = 1; break; // ����
        }
    }
}

void logic() {
    // ���� ��ġ�� ������Ʈ
    for (int i = length - 1; i > 0; i--) {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }

    // �Ӹ� ��ġ�� ������Ʈ
    switch (direction) {
    case 1: snakeY[0]--; break; // ����
    case 2: snakeX[0]++; break; // �Ʒ�
    case 3: snakeY[0]++; break; // ������
    case 4: snakeX[0]--; break; // ��
    }

    // ���� �浹�ϸ� ���� ����
    if (snakeX[0] <= 0 || snakeX[0] >= HEIGHT - 1 || snakeY[0] <= 0 || snakeY[0] >= WIDTH - 1) {
        gameover = 1;
    }

    // �ڽŰ� �浹�ϸ� ���� ����
    for (int i = 1; i < length; i++) {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
            gameover = 1;
        }
    }

    // ������ ������
    if (snakeX[0] == fruitX && snakeY[0] == fruitY) {
        score += 10;
        length++;
        fruitX = rand() % (HEIGHT - 2) + 1;
        fruitY = rand() % (WIDTH - 2) + 1;
    }

    // �ӵ� ����
    Sleep(150);
}

int main() {
    setup();
    while (!gameover) {
        draw();
        input();
        logic();
    }
    printf("��������! ���� ���ھ�: %d\n", score);
    return 0;
}
