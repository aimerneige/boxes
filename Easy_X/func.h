
// 函数声明头文件

#ifndef _FUNC_H_
#define _FUNC_H_

void startGame(void);        // 进入游戏
void initData(void);         // 初始化游戏数据
void drawMap(void);          // 绘制画面
void moveUp(void);           // 向上移动
void moveDown(void);         // 向下移动
void moveLeft(void);         // 向左移动
void moveRight(void);        // 向右移动
void mapRec(int x, int y);   // 复原
void move(int stu);          // 移动
int initStatus(void);        // 确定状态
void restart(void);          // 重启
void nextLevel(void);        // 前一关
void prevLevel(void);        // 后一关
void initMap(int level);     // 初始化地图数据
IMAGE* mapPicLoad(int id);   // 返回对应的图片引用
void loadImage(void);        // 加载图片资源

#endif