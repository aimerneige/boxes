/************
测试环境：VS2019专业版
************/

/***********
1. 三维数组  --> 形式太复杂
2. 结构     -->  实现关卡切换太麻烦  -->  链表
***********/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

const int recoveryMAP[8][8] = {
		{0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 1, 4, 1, 0, 0, 0},
		{0, 0, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 4, 1},
		{1, 4, 0, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 0, 0},
		{0, 0, 0, 1, 4, 1, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0}
}; // 地图的恢复，用于函数

const int restartMAP[8][8] = {
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
}; // 用于更改及输出的动态地图
// 可通过三维数组实现多关卡

/**
 * 0 表示空
 * 1 表示墙
 * 2 表示人
 * 3 表示箱子
 * 4 表示目的地
 * 5 表示已完成的箱子
 */

int x;
int y; // 坐标

int tx, ty;
int ttx, tty; // 次坐标

int boxes = 0; // 盒子数

char direction; // 方向

void initData(void);         // 初始化数据     // Done
void drawMap(void);          // 绘制画面       // Done
void moveUp(void);           // 向上移动       // Done
void moveDown(void);         // 向下移动       // Done        
void moveLeft(void);         // 向左移动       // Done         
void moveRight(void);        // 向右移动       // Done
void restart(void);          // 重启          // Done
void mapRec(int x, int y);   // 复原          // Done
int initStatus(void);        // 确定状态       // Done
void move(int stu);          // 移动          // Done

int main(void)
{
	initData(); // 初始化数据
	drawMap(); // 绘制地图
	do {
		direction = _getch(); // VS2019下使用（_getch();），其他编译器清使用（getch();）
		switch (direction) {
		case 'w':
		case 'W':
			moveUp();
			break;
		case 'a':
		case 'A':
			moveLeft();
			break;
		case 's':
		case 'S':
			moveDown();
			break;
		case 'd':
		case 'D':
			moveRight();
			break;
		case 'r':
		case 'R':
			restart();
			break;
		case 'q':
		case 'Q':
			return 0;
		default:
			;
		}
		drawMap();
	} while (boxes); // 当盒子数不为0时循环
	printf("You win!\n");

	return 0;
}

void initData(void)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (map[i][j] == 2) {
				x = i;
				y = j;
			}
			if (map[i][j] == 3) {
				boxes++;
			}
		}
	}
} // Done

void drawMap(void)
{
	system("cls");
	printf("Press \"w a s d\" to move.\nPress \"r\" to restart game.\nPress \"q\" to exit.\n");
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			switch (map[i][j]) {
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
				printf("error!");
			}
		}
		printf("\n");
	}
} // Done

void moveUp(void)
{
	tx = x - 1;
	ty = y;
	ttx = tx - 1;
	tty = ty;
	move(initStatus());
} // Done

void moveDown(void)
{
	tx = x + 1;
	ty = y;
	ttx = tx + 1;
	tty = ty;
	move(initStatus());
} // Done

void moveLeft(void)
{
	tx = x;
	ty = y - 1;
	ttx = tx;
	tty = ty - 1;
	move(initStatus());
} // Done

void moveRight(void)
{
	tx = x;
	ty = y + 1;
	ttx = tx;
	tty = ty + 1;
	move(initStatus());
} // Done

void restart(void)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			map[i][j] = restartMAP[i][j];
		}
	}
	initData();
} // Done

/**前面可能出现的情况
 * '地图边缘' (-1)                   1
 * '空白'（0）                       2
 * '墙'（1）                         3
 * '箱子'（3）
    * 箱子前面可能出现的情况
        * '地图边缘' (-1)            4
        * '空白' （0）               5
        * '墙' （1）                 6
        * '箱子' （3）               7
        * '目的地' （4）             8
        * '已完成的箱子' （5）        9
 * '目的地'（4）                     10
 * '已完成的箱子'（5）
    * 箱子前面可能出现的情况
        * '地图边缘' (-1)            11
        * '空白' （0）               12
        * '墙' （1）                 13
        * '箱子' （3）               14
        * '目的地' （4）             15
        * '已完成的箱子' （5）        16
 */


/**
 1  * -1
 2  *  0
 3  *  1
 4  *  3 -1
 5  *  3  0
 6  *  3  1
 7  *  3  3
 8  *  3  4
 9  *  3  5
 10 *  4
 11 *  5 -1
 12 *  5  0
 13 *  5  1
 14 *  5  3
 15 *  5  4
 16 *  5  5
 */

int initStatus(void)
{
	if (tx == -1 || tx == 8 || ty == -1 || ty == 8) {
		return 1;
	}
	else if (map[tx][ty] == 0) {
		return 2;
	}
	else if (map[tx][ty] == 1) {
		return 3;
	}
	else if (map[tx][ty] == 3) {
		if (ttx == -1 || ttx == 8 || tty == -1 || tty == 8) {
			return 4;
		}
		else if (map[ttx][tty] == 0) {
			return 5;
		}
		else if (map[ttx][tty] == 1) {
			return 6;
		}
		else if (map[ttx][tty] == 3) {
			return 7;
		}
		else if (map[ttx][tty] == 4) {
			return 8;
		}
		else if (map[ttx][tty] == 5) {
			return 9;
		}
	}
	else if (map[tx][ty] == 4) {
		return 10;
	}
	else if (map[tx][ty] == 5) {
		if (ttx == -1 || ttx == 8 || tty == -1 || tty == 8) {
			return 11;
		}
		else if (map[ttx][tty] == 0) {
			return 12;
		}
		else if (map[ttx][tty] == 1) {
			return 13;
		}
		else if (map[ttx][tty] == 3) {
			return 14;
		}
		else if (map[ttx][tty] == 4) {
			return 15;
		}
		else if (map[ttx][tty] == 5) {
			return 16;
		}
	}
} // Done

void move(int stu)
{
	switch (stu) {
	case 1:
	case 3:
	case 4:
	case 6:
	case 7:
	case 9:
	case 11:
	case 13:
	case 14:
	case 16:
		return;
		break;
	case 2:
	case 10:
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		break;
	case 5:
		map[ttx][tty] = 3;
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		break;
	case 8:
		map[ttx][tty] = 5;
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		boxes--;
		break;
	case 12:
		map[ttx][tty] = 3;
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		boxes++;
		break;
	case 15:
		map[ttx][tty] = 5;
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		break;
	default:
		return;
	}
} // Done

void mapRec(int x, int y)
{
	map[x][y] = recoveryMAP[x][y];
} // Done
