
// 初始化地图的函数

#include "head.h"
#include "define.h"
#include "func.h"
#include "data.h"

// 这些函数仅在这里有用，故单独声明

// 初始化各个地图的函数
void initMap_1(void);
void initMap_2(void);
void initMap_3(void);
void initMap_4(void);
void initMap_5(void);
void initMap_6(void);
void initMap_7(void);
void initMap_8(void);
void initMap_9(void);
void initMap_10(void);
void initMap_11(void);
void initMap_12(void);
void initMap_13(void);
void initMap_14(void);
void initMap_15(void);
void initMap_NULL(void); // 正常情况不会加载这个地图

void init(int w, int h);        // 初始化一个空的待写入的地图
int** map_malloc(int h, int w); // 为地图分配内存
void map_free(int** map);       // 释放地图所在的二维数组的内存空间

void initMap(int level)
{
	switch (level) {
	case 1:
		initMap_1();
		break;
	case 2:
		initMap_2();
		break;
	case 3:
		initMap_3();
		break;
	case 4:
		initMap_4();
		break;
	case 5:
		initMap_5();
		break;
	case 6:
		initMap_6();
		break;
	case 7:
		initMap_7();
		break;
	case 8:
		initMap_8();
		break;
	case 9:
		initMap_9();
		break;
	case 10:
		initMap_10();
		break;
	case 11:
		initMap_11();
		break;
	case 12:
		initMap_12();
		break;
	case 13:
		initMap_13();
		break;
	case 14:
		initMap_14();
		break;
	case 15:
		initMap_15();
		break;
	default:
		initMap_NULL();
		break;
	}
}

int** map_malloc(int w, int h)
{
	// 如果输入为零或负时，会造成空指针或者无法分配内存，直接返回NULL
	// NULL会造成程序崩溃，为防止程序崩溃，需要开发者保证不会输入错误的数字
	if (w <= 0 || h <= 0) {
		return NULL;
	}

	// 首先创建临时本地变量
	int** ret = NULL;

	// 使用malloc分配空间
	ret = (int**)malloc(sizeof(int*) * h);
	for (int i = 0; i < h; i++) {
		ret[i] = (int*)malloc(sizeof(int) * w);
	}

	// 返回已开辟空间的地址
	return ret;
}

void map_free(int** map)
{
	// 先释放内层的内存
	for (int i = 0; i < height; i++) {
		free(map[i]);
	}

	// 释放外层的内存
	free(map);
}

void init(int h, int w)
{
	// 为防止内存溢出，首先释放旧地图的内存
	map_free(recoveryMAP);
	map_free(restartMAP);
	map_free(map);

	// 为新的地图开辟空间
	recoveryMAP = map_malloc(w, h);
	restartMAP = map_malloc(w, h);
	map = map_malloc(w, h);

	// 设定地图宽高的全局变量
	height = h;
	width = w;
}

void initMap_1(void)
{
	// 首先初始化一个空的待写入的地图
	init(8, 8);

	// 检索全局变量中的地图数据并写入刚才创建好的空地图
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_1[i][j];
			restartMAP[i][j] = map_1[i][j];
			recoveryMAP[i][j] = recMap_1[i][j];
		}
	}
}

// 之后的内容完全一致，不在赘述

void initMap_2(void)
{
	init(8, 8);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_2[i][j];
			restartMAP[i][j] = map_2[i][j];
			recoveryMAP[i][j] = recMap_2[i][j];
		}
	}
}

void initMap_3(void)
{
	init(9, 10);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_3[i][j];
			restartMAP[i][j] = map_3[i][j];
			recoveryMAP[i][j] = recMap_3[i][j];
		}
	}
}

void initMap_4(void)
{
	init(10, 11);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_4[i][j];
			restartMAP[i][j] = map_4[i][j];
			recoveryMAP[i][j] = recMap_4[i][j];
		}
	}
}

void initMap_5(void)
{
	init(9, 7);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_5[i][j];
			restartMAP[i][j] = map_5[i][j];
			recoveryMAP[i][j] = recMap_5[i][j];
		}
	}
}

void initMap_6(void)
{
	init(8, 8);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_6[i][j];
			restartMAP[i][j] = map_6[i][j];
			recoveryMAP[i][j] = recMap_6[i][j];
		}
	}
}

void initMap_7(void)
{
	init(7, 8);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_7[i][j];
			restartMAP[i][j] = map_7[i][j];
			recoveryMAP[i][j] = recMap_7[i][j];
		}
	}
}

void initMap_8(void)
{
	init(8, 8);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_8[i][j];
			restartMAP[i][j] = map_8[i][j];
			recoveryMAP[i][j] = recMap_8[i][j];
		}
	}
}

void initMap_9(void)
{
	init(9, 7);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_9[i][j];
			restartMAP[i][j] = map_9[i][j];
			recoveryMAP[i][j] = recMap_9[i][j];
		}
	}
}

void initMap_10(void)
{
	init(9, 10);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_10[i][j];
			restartMAP[i][j] = map_10[i][j];
			recoveryMAP[i][j] = recMap_10[i][j];
		}
	}
}

void initMap_11(void)
{
	init(8, 7);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_11[i][j];
			restartMAP[i][j] = map_11[i][j];
			recoveryMAP[i][j] = recMap_11[i][j];
		}
	}
}

void initMap_12(void)
{
	init(9, 9);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_12[i][j];
			restartMAP[i][j] = map_12[i][j];
			recoveryMAP[i][j] = recMap_12[i][j];
		}
	}
}

void initMap_13(void)
{
	init(8, 10);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_13[i][j];
			restartMAP[i][j] = map_13[i][j];
			recoveryMAP[i][j] = recMap_13[i][j];
		}
	}
}

void initMap_14(void)
{
	init(10, 9);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_14[i][j];
			restartMAP[i][j] = map_14[i][j];
			recoveryMAP[i][j] = recMap_14[i][j];
		}
	}
}

void initMap_15(void)
{
	init(8, 9);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_15[i][j];
			restartMAP[i][j] = map_15[i][j];
			recoveryMAP[i][j] = recMap_15[i][j];
		}
	}
}


// 此处初始化了个错误的地图
// 用户不应该看到这个地图
// 如果调试过程中出现了这个地图，则程序出现了bug
void initMap_NULL(void)
{
	init(4, 3);

	map[0][0] = WALL; map[0][1] = WALL;  map[0][2] = WALL;
	map[1][0] = WALL; map[1][1] = HUMAN; map[1][2] = WALL;
	map[2][0] = WALL; map[2][1] = WALL;  map[2][2] = WALL;
	map[3][0] = BOX;  map[3][1] = BOX;   map[3][2] = BOX;


	recoveryMAP[0][0] = WALL; recoveryMAP[0][1] = WALL;  recoveryMAP[0][2] = WALL;
	recoveryMAP[1][0] = WALL; recoveryMAP[1][1] = HUMAN; recoveryMAP[1][2] = WALL;
	recoveryMAP[2][0] = WALL; recoveryMAP[2][1] = WALL;  recoveryMAP[2][2] = WALL;
	recoveryMAP[3][0] = BOX;  recoveryMAP[3][1] = BOX;   recoveryMAP[3][2] = BOX;

	restartMAP[0][0] = WALL; restartMAP[0][1] = WALL;  restartMAP[0][2] = WALL;
	restartMAP[1][0] = WALL; restartMAP[1][1] = HUMAN; restartMAP[1][2] = WALL;
	restartMAP[2][0] = WALL; restartMAP[2][1] = WALL;  restartMAP[2][2] = WALL;
	restartMAP[2][0] = BOX;  restartMAP[2][1] = BOX;   restartMAP[2][2] = BOX;
}