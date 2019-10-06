#include <stdio.h>

// #define WIDTH 8
// #define HEIGHT 8

void initData(void); // 初始化数据
void drawMap(void); // 绘制画面
void moveUp(void); // 向上移动
void moveDown(void); // 向下移动
void moveLeft(void); // 向左移动
void moveRight(void); // 向右移动
// void move(char direction); // 移动



int map[8][8] = {
    {0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 4, 1, 0, 0, 0},
    {0, 0, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 3, 0, 3, 4, 1},
    {1, 4, 0, 3, 2, 1, 1, 1},
    {1, 1, 1, 1, 3, 1, 0, 0},
    {0, 0, 0, 1, 4, 1, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0}
}; // 可通过三维数组实现多关卡
/**
 * 0 表示空
 * 1 表示墙
 * 2 表示人
 * 3 表示箱子
 * 4 表示目的地
 * 5 表示已完成的箱子
 */

int x;
int y;

int boxes;

// int course = 1; // 可通过三维数组实现多关卡

// int error = 0;

int main()
{
    char direction;
    initData();
    printf("Press \"w a s d\" to move.\n");
    // printf("Press wasd to move and press r to restart.\n");
    drawMap();
    direction = getch();
    while ( boxes ) {
        move(direction);
    }
    printf("You win!\n");

    return 0;
}


void initData(void)
{

}

void drawMap(void)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int temp = map[i][j];
            switch (temp) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("█");
                    break;
                case 2:
                    printf("☿");
                    break;
                case 3:
                    printf("●");
                    break;
                case 4:
                    printf("☆");
                    break;
                case 5:
                    printf("★");
                    break;
                // default:
                    // printf("Error Happens!\n");
                    // error = 1;
                    // return;
            }
        }
        printf("\n");
    }
} // Tested

void moveUp(void)
{

}
void moveDown(void)
{

}
void moveLeft(void)
{

}
void moveRight(void)
{

}
void move(char direction)
{

}