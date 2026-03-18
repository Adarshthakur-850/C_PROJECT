#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 20
#define HEIGHT 20

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

int gameOver;
int score;
int snakeLength;
int snakeX[100], snakeY[100];
int fruitX, fruitY;
char direction;

void setup();
void draw();
void input();
void logic();

int main() {
    gameOver = 0;
    score = 0;
    snakeLength = 1;
    snakeX[0] = WIDTH / 2;
    snakeY[0] = HEIGHT / 2;
    direction = RIGHT;

    setup();

    while (!gameOver) {
        draw();
        input();
        logic();
        usleep(200000);
    }

    printf("\nGame Over!\n");
    printf("Your score: %d\n", score);

    return 0;
}

void setup() {
    srand(time(NULL));

    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
}

void draw() {
    system("cls");

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                printf("#");


            if (i == snakeY[0] && j == snakeX[0])
                printf("O");
            else if (i == fruitY && j == fruitX)
                printf("*");
            else {
                int isSnakeBodyPart = 0;
                for (int k = 1; k < snakeLength; k++) {
                    if (i == snakeY[k] && j == snakeX[k]) {
                        printf("o");
                        isSnakeBodyPart = 1;
                    }
                }
                if (!isSnakeBodyPart)
                    printf(" ");
            }

            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    printf("Score: %d\n", score);
    printf("Press 'X' to quit\n");
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case UP:
                if (direction != DOWN)
                    direction = UP;
                break;
            case DOWN:
                if (direction != UP)
                    direction = DOWN;
                break;
            case LEFT:
                if (direction != RIGHT)
                    direction = LEFT;
                break;
            case RIGHT:
                if (direction != LEFT)
                    direction = RIGHT;
                break;
            case 'x':
            case 'X':
                gameOver = 1;
                break;
        }
    }
}

void logic() {
    for (int i = snakeLength - 1; i > 0; i--) {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }

    switch (direction) {
        case UP:
            snakeY[0]--;
            break;
        case DOWN:
            snakeY[0]++;
            break;
        case LEFT:
            snakeX[0]--;
            break;
        case RIGHT:
            snakeX[0]++;
            break;
    }

    if (snakeX[0] == fruitX && snakeY[0] == fruitY) {
        score += 10;
        snakeLength++;

        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
    }

    if (snakeX[0] >= WIDTH || snakeX[0] < 0 || snakeY[0] >= HEIGHT || snakeY[0] < 0) {
        gameOver = 1;
    }

    for (int i = 1; i < snakeLength; i++) {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
            gameOver = 1;
        }
    }
}
