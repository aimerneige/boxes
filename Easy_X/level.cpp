
// 更改关卡的函数

#include "head.h"
#include "define.h"
#include "func.h"
#include "data.h"

// 加载下一关卡
void nextLevel(void)
{
	if (level < maxLevel) {
		level++;
	}
	else {
		level = 1; // 关卡为最后一关时变更为第一关，实现循环
	}

	// 更改全局变量的关卡数后，重新进行游戏
	startGame();
}

void prevLevel(void)
{
	if (level > 1) {
		level--;
	}
	else {
		level = maxLevel; // 关卡为第一关时变更为最后一关，实现循环
	}

	// 更改全局变量的关卡数后，重新进行游戏
	startGame();
}

void restart(void)
{
	// 重新进行游戏
	startGame();
}
