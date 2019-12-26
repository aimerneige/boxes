
// main函数

#include "head.h"
#include "define.h"
#include "func.h"
#include "data.h"

int main()
{
	// 初始化窗口
	initgraph(Width, Height);

	// 读取图片资源文件
	loadImage();

	// 进入游戏
	startGame();

	// 关闭绘图界面
	closegraph();

	// 结束游戏
	return 0;
}