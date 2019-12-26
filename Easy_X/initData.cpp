
// 初始化数据的函数

#include "head.h"
#include "define.h"
#include "func.h"
#include "data.h"

// 初始化基础数据
void initData(void)
{
	// 读入地图
	initMap(level); // 此处level已被初始化为1

	// 初始化箱子数
	boxes = 0;

	// 坐标和箱子数
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (map[i][j] == 2) {
				x = i;
				y = j;
			}
			if (map[i][j] == 3) {
				boxes++;
			}
		} // 内层循环结束
	}
}// 函数结束
