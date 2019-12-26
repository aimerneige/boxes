
// 宏定义头文件
// 保存各种宏定义

#ifndef _DEFINE_H_
#define _DEFINE_H_

#define BLANK      0 // 空
#define WALL       1 // 墙
#define HUMAN      2 // 人
#define BOX        3 // 箱子
#define DEST       4 // 目的地
#define DONE       5 // 已完成的箱子
#define EDGE      -1 // 左上边缘
#define EDGE_R   (width + 1)  // 右边缘
#define EDGE_D   (height + 1) // 下边缘

#define COULD_NOT_MOVE  1 // 不能移动
#define COULD_MOVE_B    2 // 移动向空地
#define COULD_PULL_B    3 // 推向空地
#define COULD_PULL_D    4 // 推向目的地
#define COULD_PULL_D_B  5 // 推完成的箱子向空地
#define COULD_PULL_D_D  6 // 推完成的箱子向目的地

#define Width  1600   // 宽
#define Height 900    // 高

#define BLOCK 64  // 单位长度（箱子的宽度）

#endif