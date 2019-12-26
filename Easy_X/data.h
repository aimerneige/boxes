
// 全局变量声明头文件
// 声明保存在“data.cpp”文件中的全局变量
// 以让其他文件中的程序可以访问这些全局变量
// 具体注释请自行查看“data.cpp”文件中的注释，此处不做赘述

#ifndef _DATA_H_
#define _DATA_H_

extern int** recoveryMAP;
extern int** restartMAP;
extern int** map;

extern int x;
extern int y;

extern int tx, ty;
extern int ttx, tty;

extern int boxes;

extern char direction;

extern int level;
extern int maxLevel;

extern int width;
extern int height;


extern IMAGE BkImg;
extern IMAGE Blank;
extern IMAGE Wall;
extern IMAGE Human;
extern IMAGE Box;
extern IMAGE Dest;
extern IMAGE Box_D;
extern IMAGE Miku;
extern IMAGE Explain;

/* Map Start */
extern const int map_1[8][8];
extern const int recMap_1[8][8];

extern const int map_2[8][8];
extern const int recMap_2[8][8];

extern const int map_3[9][10];
extern const int recMap_3[9][10];

extern const int map_4[10][11];
extern const int recMap_4[10][11];

extern const int map_5[9][7];
extern const int recMap_5[9][7];

extern const int map_6[8][8];
extern const int recMap_6[8][8];

extern const int map_7[7][8];
extern const int recMap_7[7][8];

extern const int map_8[8][8];
extern const int recMap_8[8][8];

extern const int map_9[9][7];
extern const int recMap_9[9][7];

extern const int map_10[9][10];
extern const int recMap_10[9][10];

extern const int map_11[8][7];
extern const int recMap_11[8][7];

extern const int map_12[9][9];
extern const int recMap_12[9][9];

extern const int map_13[8][10];
extern const int recMap_13[8][10];

extern const int map_14[10][9];
extern const int recMap_14[10][9];

extern const int map_15[8][9];
extern const int recMap_15[8][9];
/* Map End */

#endif