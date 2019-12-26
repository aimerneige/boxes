
// 进行游戏的函数

#include "head.h"
#include "define.h"
#include "func.h"
#include "data.h"

void startGame(void)
{
	// 初始化数据
	initData();

	// 绘制地图
	drawMap();

	// 循环控制
	do {
		direction = _getch();// 读取键盘输入
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
		case 'n':
		case 'N':
			nextLevel();
			break;
		case 'b':
		case 'B':
			prevLevel();
			break;
		default:
			; // 输入错误的按键执行空语句
		}
		drawMap();      // 绘制地图
	} while (boxes);    // 当盒子数不为0时循环

	// 跳出循环说明游戏结束，进行下一关
	nextLevel();
}