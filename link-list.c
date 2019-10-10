#include <stdio.h>

struct MAP {
    const int recoveryMAP[8][8];
    const int restartMAP[8][8];
    int map[8][8];
    struct MAP * next;
};

struct MAP A_map;
struct MAP * level1 = &A_map;

level->recoveryMAP[8][8] = {
		{0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 1, 4, 1, 0, 0, 0},
		{0, 0, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 4, 1},
		{1, 4, 0, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 0, 0},
		{0, 0, 0, 1, 4, 1, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0}
};

level->restartMAP[8][8] = {
		{0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 1, 4, 1, 0, 0, 0},
		{0, 0, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 3, 0, 3, 4, 1},
		{1, 4, 0, 3, 2, 1, 1, 1},
		{1, 1, 1, 1, 3, 1, 0, 0},
		{0, 0, 0, 1, 4, 1, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0}
};

level->map[8][8] = {
		{0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 1, 4, 1, 0, 0, 0},
		{0, 0, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 3, 0, 3, 4, 1},
		{1, 4, 0, 3, 2, 1, 1, 1},
		{1, 1, 1, 1, 3, 1, 0, 0},
		{0, 0, 0, 1, 4, 1, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0}
};

A_map.next = NULL;

int main(void)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", level1->recoveryMAP[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", level1->restartMAP[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", level1->map[i][j]);
        }
        printf("\n");
    }
    return 0;
}