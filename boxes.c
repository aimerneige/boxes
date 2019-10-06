/**Something need to add
 * Only Win Permitted 
 * Can't Restart
 * Don't have more level/course
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Can't use on Linux and some other device

// #define WIDTH 8
// #define HEIGHT 8

// void initData(void); // 锟斤拷始锟斤拷锟斤拷锟斤拷
// void drawMap(void); // 锟斤拷锟狡伙拷锟斤拷
// void moveUp(void); // 锟斤拷锟斤拷锟狡讹拷
// void moveDown(void); // 锟斤拷锟斤拷锟狡讹拷
// void moveLeft(void); // 锟斤拷锟斤拷锟狡讹拷
// void moveRight(void); // 锟斤拷锟斤拷锟狡讹拷
// void move(char direction); // 锟狡讹拷
// just for remind an accident

void initData(void); // 初始化数据
void drawMap(void); // 绘制画面
void moveUp(void); // 向上移动
void moveDown(void); // 向下移动
void moveLeft(void); // 向左移动
void moveRight(void); // 向右移动
void move(char direction); // 移动
void mapRec(int x, int y); // 复原

const int recMAP[8][8] = {
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 4, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 3, 0, 3, 4, 1},
        {1, 4, 0, 3, 2, 1, 1, 1},
        {1, 1, 1, 1, 3, 1, 0, 0},
        {0, 0, 0, 1, 4, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0}
}; // 地图的恢复，用于函数

const int recMAP[8][8] = {
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 4, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 3, 0, 3, 4, 1},
        {1, 4, 0, 3, 2, 1, 1, 1},
        {1, 1, 1, 1, 3, 1, 0, 0},
        {0, 0, 0, 1, 4, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0}
}; // 地图的恢复，用于重启

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

int x = 0;
int y = 0;

int boxes = 0;

// int course = 1; // 可通过三维数组实现多关卡

// int error = 0;

int main()
{
    char direction;
    initData();
    printf("Press \"w a s d\" to move.\n");
    // printf("Press \"w a s d\" to move and press r to restart.\n");
    drawMap();
    direction = getch();
    while ( boxes ) {
        move(direction);
        system("cls");
        drawMap();
        direction = getch();
    }
    printf("You win!\n");

    return 0;
}


void initData(void)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ( map[i][j] == 2 ) {
                x = i;
                y = j;
            } else if ( map [i][j] == 3) {
                boxes++;
            }
        }
    }
}

void drawMap(void)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int temp = map[i][j];
            switch (temp) {
                case 0:
                    printf("  ");
                    break;
                case 1:
                    printf("■");
                    break;
                case 2:
                    printf("♀");
                    break;
                case 3:
                    printf("◆");
                    break;
                case 4:
                    printf("●");
                    break;
                case 5:
                    printf("★");
                    break;
                default:
                    printf("That's impossible to print this.\nIf you see this, I's mean that there have some error happens.\nYou can connect me on GitHub.\n@ aimerneige");
            }
        }
        printf("\n");
    }
} // Tested

void move(char direction)
{
    switch (direction) {
        case 'w':
            moveUp();
            break;
        case 'a':
            moveLeft();
            break;
        case 's':
            moveDown();
            break;
        case 'd':
            moveRight();
            break;
        default:
            direction = getch();
            move(direction);
    }
}

/**前面可能出现的情况
 * 前面是空白（0）
 * 前面是墙（1）
 * 前面是箱子（3）
    * 箱子前面可能出现的情况
        * '空白' （0）
        * '墙' （1）
        * '箱子' （3）
        * '目的地' （4）
        * '已完成的箱子' （5）
 * 前面是目的地（4）
 * 前面是已完成的箱子（5）
 */

void moveUp(void)
{
    if (x == 0) {
        return;
    }
    int tx, ty;
    tx = x - 1;
    ty = y;
    if ( map[tx][ty] == 0 ) {
        map[tx][ty] = 2;
        map[x][y] = 0;
    } else if ( map[tx][ty] == 1 ) {
        return;
    } else if ( map[tx][ty] == 3 ) {
        if ( tx == 0 ) {
            return;
        }
        int ttx, tty;
        ttx = tx - 1;
        tty = ty;
        if ( map[ttx][tty] == 0 ) {
            map[ttx][tty] = 3;
            map[tx][ty] = 2;
            map[x][y] = 0;
        } else if ( map[ttx][tty] == 1 ) {
            return;
        } else if ( map[ttx][tty] == 3 ) {
            return;
        } else if ( map[ttx][tty] == 4 ) {
            map[ttx][tty] = 5;
            map[tx][ty] = 2;
            map[x][y] = 0;
            boxes--;
            // 锟斤拷位指锟斤拷锟?
        } else if ( map[ttx][tty] == 5 ) {
            return;
        }
    } else if ( map[tx][ty] == 4 ) {

    } else if ( map[tx][ty] == 5 ) {

    }


}

//void moveDown(void)
{

}

//void moveLeft(void)
{

}

//void moveRight(void)
{

}

void mapRec(int x, int y)
{
    map[x][y] = recMAP[x][y];
}