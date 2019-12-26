
// 控制角色移动的函数

#include "head.h"
#include "define.h"
#include "func.h"
#include "data.h"

// 四种移动方法分别对应不同的次坐标计算方法

void moveUp(void)
{
	tx = x - 1;
	ty = y;
	ttx = tx - 1;
	tty = ty;
	move(initStatus()); // 通过次坐标判断状态，决定移动方式（更改地图的方式）
}
// 向上移动

void moveDown(void)
{
	tx = x + 1;
	ty = y;
	ttx = tx + 1;
	tty = ty;
	move(initStatus());
}
// 向下移动


void moveLeft(void)
{
	tx = x;
	ty = y - 1;
	ttx = tx;
	tty = ty - 1;
	move(initStatus());
}
// 向左移动

void moveRight(void)
{
	tx = x;
	ty = y + 1;
	ttx = tx;
	tty = ty + 1;
	move(initStatus());
}
// 向右移动


// 不同的状态对于不同的移动方式（更改地图的方式）

void move(int stu)
{
	switch (stu) {
	case COULD_NOT_MOVE: // 不能移动
		return;
		break;
	case COULD_MOVE_B: // 移动向空地
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		break;
	case COULD_PULL_B: // 推向空地
		map[ttx][tty] = 3;
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		break;
	case COULD_PULL_D: // 推向目的地
		map[ttx][tty] = 5;
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		boxes--;
		break;
	case COULD_PULL_D_B: // 推完成的箱子向空地
		map[ttx][tty] = 3;
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		boxes++;
		break;
	case COULD_PULL_D_D: // 推完成的箱子向目的地
		map[ttx][tty] = 5;
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		break;
	default: // 默认什么都不做（一般不会出现这种可能）
		return;
	}
}




// 确定当前状态以决定移动方式
// 具体实现原理看下方注释

int initStatus(void)
{
	if (tx == EDGE || tx == EDGE_R || ty == EDGE || ty == EDGE_D) {
		return COULD_NOT_MOVE;
	}
	else if (map[tx][ty] == BLANK) {
		return COULD_MOVE_B;
	}
	else if (map[tx][ty] == WALL) {
		return COULD_NOT_MOVE;
	}
	else if (map[tx][ty] == BOX) {
		if (ttx == EDGE || ttx == EDGE_R || tty == EDGE || tty == EDGE_D) {
			return COULD_NOT_MOVE;
		}
		else if (map[ttx][tty] == BLANK) {
			return COULD_PULL_B;
		}
		else if (map[ttx][tty] == WALL) {
			return COULD_NOT_MOVE;
		}
		else if (map[ttx][tty] == BOX) {
			return COULD_NOT_MOVE;
		}
		else if (map[ttx][tty] == DEST) {
			return COULD_PULL_D;
		}
		else if (map[ttx][tty] == DONE) {
			return COULD_NOT_MOVE;
		}
	}
	else if (map[tx][ty] == DEST) {
		return COULD_MOVE_B;
	}
	else if (map[tx][ty] == DONE) {
		if (ttx == EDGE || ttx == EDGE_R || tty == EDGE || tty == EDGE_D) {
			return COULD_NOT_MOVE;
		}
		else if (map[ttx][tty] == BLANK) {
			return COULD_PULL_D_B;
		}
		else if (map[ttx][tty] == WALL) {
			return COULD_NOT_MOVE;
		}
		else if (map[ttx][tty] == BOX) {
			return COULD_NOT_MOVE;
		}
		else if (map[ttx][tty] == DEST) {
			return COULD_PULL_D_D;
		}
		else if (map[ttx][tty] == DONE) {
			return COULD_NOT_MOVE;
		}
	}
}

/**前面可能出现的情况
 * '地图边缘'
 * '空白'
 * '墙'
 * '箱子'
	* 箱子前面可能出现的情况
		* '地图边缘'
		* '空白'
		* '墙'
		* '箱子'
		* '目的地'
		* '已完成的箱子'
 * '目的地'
 * '已完成的箱子'
	* 箱子前面可能出现的情况
		* '地图边缘'
		* '空白'
		* '墙'
		* '箱子'
		* '目的地'
		* '已完成的箱子'
 */


 // 移动后恢复地图

void mapRec(int x, int y)
{
	map[x][y] = recoveryMAP[x][y];
}