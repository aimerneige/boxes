
// 加载图片资源的函数
// 如果贴图错误可检索这里

#include "head.h"
#include "define.h"
#include "func.h"
#include "data.h"

void loadImage(void)
{
	/* 加载图片资源 */

	loadimage(&BkImg, L"res/BackGround.png", Width, Height);  // 背景

	loadimage(&Blank, L"res/BLANK.png", BLOCK, BLOCK);   // 空
	loadimage(&Wall, L"res/WALL.png", BLOCK, BLOCK);     // 墙
	loadimage(&Human, L"res/HUMAN.png", BLOCK, BLOCK);   // 人
	loadimage(&Box, L"res/BOX.png", BLOCK, BLOCK);       // 箱子
	loadimage(&Box_D, L"res/BOX_DONE.png", BLOCK, BLOCK);   // 目的地
	loadimage(&Dest, L"res/DEST.png", BLOCK, BLOCK);     // 已完成的箱子

	loadimage(&Miku, L"res/miku.png", 421, 640);       // Miku

	loadimage(&Explain, L"res/Explain.png", 421, 260); // 游戏说明
}
