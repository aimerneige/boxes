/************
���Ի�����VS2019רҵ��
************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

const int recoveryMAP[8][8] = {
		{0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 1, 4, 1, 0, 0, 0},
		{0, 0, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 4, 1},
		{1, 4, 0, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 0, 0},
		{0, 0, 0, 1, 4, 1, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0}
}; // ��ͼ�Ļָ������ں���

const int restartMAP[8][8] = {
		{0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 1, 4, 1, 0, 0, 0},
		{0, 0, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 3, 0, 3, 4, 1},
		{1, 4, 0, 3, 2, 1, 1, 1},
		{1, 1, 1, 1, 3, 1, 0, 0},
		{0, 0, 0, 1, 4, 1, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0}
}; // ��ͼ�Ļָ�����������

int map[8][8] = {
		{0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 1, 4, 1, 0, 0, 0},
		{0, 0, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 3, 0, 3, 4, 1},
		{1, 4, 0, 3, 2, 1, 1, 1},
		{1, 1, 1, 1, 3, 1, 0, 0},
		{0, 0, 0, 1, 4, 1, 0, 0},
		{0, 0, 0, 1, 1, 1, 0, 0}
}; // ���ڸ��ļ�����Ķ�̬��ͼ
// ��ͨ����ά����ʵ�ֶ�ؿ�

/**
 * 0 ��ʾ��
 * 1 ��ʾǽ
 * 2 ��ʾ��
 * 3 ��ʾ����
 * 4 ��ʾĿ�ĵ�
 * 5 ��ʾ����ɵ�����
 */

int x;
int y; // ����

int tx, ty;
int ttx, tty; // ������

int boxes = 0; // ������

char direction; // ����

void initData(void);         // ��ʼ������     // Done
void drawMap(void);          // ���ƻ���       // Done
void moveUp(void);           // �����ƶ�       // Done
void moveDown(void);         // �����ƶ�       // Done        
void moveLeft(void);         // �����ƶ�       // Done         
void moveRight(void);        // �����ƶ�       // Done
void restart(void);          // ����          // Done
void mapRec(int x, int y);   // ��ԭ          // Done
int initStatus(void);        // ȷ��״̬       // Done
void move(int stu);          // �ƶ�          // Done

int main(void)
{
	initData(); // ��ʼ������
	drawMap(); // ���Ƶ�ͼ
	do {
		direction = _getch(); // VS2019��ʹ�ã�_getch();����������������ʹ�ã�getch();��
		switch (direction) {
		case 'w':
		case 'W':
			moveUp();
			break;
		case 'a':
		case 'A':
			moveLeft();
			break;
		case 's':
		case 'S':
			moveDown();
			break;
		case 'd':
		case 'D':
			moveRight();
			break;
		case 'r':
		case 'R':
			restart();
			break;
		case 'q':
		case 'Q':
			return 0;
		default:
			;
		}
		drawMap();
	} while (boxes); // ����������Ϊ0ʱѭ��
	printf("You win!\n");

	return 0;
}

void initData(void)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (map[i][j] == 2) {
				x = i;
				y = j;
			}
			if (map[i][j] == 3) {
				boxes++;
			}
		}
	}
} // Done

void drawMap(void)
{
	system("cls");
	printf("Press \"w a s d\" to move.\nPress \"r\" to restart game.\nPress \"q\" to exit.\n");
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			switch (map[i][j]) {
			case 0:
				printf("  ");
				break;
			case 1:
				printf("��");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			default:
				printf("error!");
			}
		}
		printf("\n");
	}
} // Done

void moveUp(void)
{
	tx = x - 1;
	ty = y;
	ttx = tx - 1;
	tty = ty;
	move(initStatus());
} // Done

void moveDown(void)
{
	tx = x + 1;
	ty = y;
	ttx = tx + 1;
	tty = ty;
	move(initStatus());
} // Done

void moveLeft(void)
{
	tx = x;
	ty = y - 1;
	ttx = tx;
	tty = ty - 1;
	move(initStatus());
} // Done

void moveRight(void)
{
	tx = x;
	ty = y + 1;
	ttx = tx;
	tty = ty + 1;
	move(initStatus());
} // Done

void restart(void)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			map[i][j] = restartMAP[i][j];
		}
	}
	initData();
} // Done

/**ǰ����ܳ��ֵ����
 * '��ͼ��Ե' (-1)                   1
 * '�հ�'��0��                       2
 * 'ǽ'��1��                         3
 * '����'��3��
    * ����ǰ����ܳ��ֵ����
        * '��ͼ��Ե' (-1)            4
        * '�հ�' ��0��               5
        * 'ǽ' ��1��                 6
        * '����' ��3��               7
        * 'Ŀ�ĵ�' ��4��             8
        * '����ɵ�����' ��5��        9
 * 'Ŀ�ĵ�'��4��                     10
 * '����ɵ�����'��5��
    * ����ǰ����ܳ��ֵ����
        * '��ͼ��Ե' (-1)            11
        * '�հ�' ��0��               12
        * 'ǽ' ��1��                 13
        * '����' ��3��               14
        * 'Ŀ�ĵ�' ��4��             15
        * '����ɵ�����' ��5��        16
 */


/**
 1  * -1
 2  *  0
 3  *  1
 4  *  3 -1
 5  *  3  0
 6  *  3  1
 7  *  3  3
 8  *  3  4
 9  *  3  5
 10 *  4
 11 *  5 -1
 12 *  5  0
 13 *  5  1
 14 *  5  3
 15 *  5  4
 16 *  5  5
 */

int initStatus(void)
{
	if (tx == -1 || tx == 8 || ty == -1 || ty == 8) {
		return 1;
	}
	else if (map[tx][ty] == 0) {
		return 2;
	}
	else if (map[tx][ty] == 1) {
		return 3;
	}
	else if (map[tx][ty] == 3) {
		if (ttx == -1 || ttx == 8 || tty == -1 || tty == 8) {
			return 4;
		}
		else if (map[ttx][tty] == 0) {
			return 5;
		}
		else if (map[ttx][tty] == 1) {
			return 6;
		}
		else if (map[ttx][tty] == 3) {
			return 7;
		}
		else if (map[ttx][tty] == 4) {
			return 8;
		}
		else if (map[ttx][tty] == 5) {
			return 9;
		}
	}
	else if (map[tx][ty] == 4) {
		return 10;
	}
	else if (map[tx][ty] == 5) {
		if (ttx == -1 || ttx == 8 || tty == -1 || tty == 8) {
			return 11;
		}
		else if (map[ttx][tty] == 0) {
			return 12;
		}
		else if (map[ttx][tty] == 1) {
			return 13;
		}
		else if (map[ttx][tty] == 3) {
			return 14;
		}
		else if (map[ttx][tty] == 4) {
			return 15;
		}
		else if (map[ttx][tty] == 5) {
			return 16;
		}
	}
} // Done

void move(int stu)
{
	switch (stu) {
	case 1:
	case 3:
	case 4:
	case 6:
	case 7:
	case 9:
	case 11:
	case 13:
	case 14:
	case 16:
		return;
		break;
	case 2:
	case 10:
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		break;
	case 5:
		map[ttx][tty] = 3;
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		break;
	case 8:
		map[ttx][tty] = 5;
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		boxes--;
		break;
	case 12:
		map[ttx][tty] = 3;
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		boxes++;
		break;
	case 15:
		map[ttx][tty] = 5;
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		break;
	default:
		return;
	}
} // Done

void mapRec(int x, int y)
{
	map[x][y] = recoveryMAP[x][y];
} // Done
