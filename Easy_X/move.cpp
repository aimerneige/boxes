
// ���ƽ�ɫ�ƶ��ĺ���

#include "head.h"
#include "define.h"
#include "func.h"
#include "data.h"

// �����ƶ������ֱ��Ӧ��ͬ�Ĵ�������㷽��

void moveUp(void)
{
	tx = x - 1;
	ty = y;
	ttx = tx - 1;
	tty = ty;
	move(initStatus()); // ͨ���������ж�״̬�������ƶ���ʽ�����ĵ�ͼ�ķ�ʽ��
}
// �����ƶ�

void moveDown(void)
{
	tx = x + 1;
	ty = y;
	ttx = tx + 1;
	tty = ty;
	move(initStatus());
}
// �����ƶ�


void moveLeft(void)
{
	tx = x;
	ty = y - 1;
	ttx = tx;
	tty = ty - 1;
	move(initStatus());
}
// �����ƶ�

void moveRight(void)
{
	tx = x;
	ty = y + 1;
	ttx = tx;
	tty = ty + 1;
	move(initStatus());
}
// �����ƶ�


// ��ͬ��״̬���ڲ�ͬ���ƶ���ʽ�����ĵ�ͼ�ķ�ʽ��

void move(int stu)
{
	switch (stu) {
	case COULD_NOT_MOVE: // �����ƶ�
		return;
		break;
	case COULD_MOVE_B: // �ƶ���յ�
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		break;
	case COULD_PULL_B: // ����յ�
		map[ttx][tty] = 3;
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		break;
	case COULD_PULL_D: // ����Ŀ�ĵ�
		map[ttx][tty] = 5;
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		boxes--;
		break;
	case COULD_PULL_D_B: // ����ɵ�������յ�
		map[ttx][tty] = 3;
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		boxes++;
		break;
	case COULD_PULL_D_D: // ����ɵ�������Ŀ�ĵ�
		map[ttx][tty] = 5;
		map[tx][ty] = 2;
		mapRec(x, y);
		x = tx;
		y = ty;
		break;
	default: // Ĭ��ʲô��������һ�㲻��������ֿ��ܣ�
		return;
	}
}




// ȷ����ǰ״̬�Ծ����ƶ���ʽ
// ����ʵ��ԭ���·�ע��

int initStatus(void)
{
	if (tx == EDGE || tx == EDGE_R || ty == EDGE || ty == EDGE_D) {
		return COULD_NOT_MOVE;
	}
	else if (map[tx][ty] == BLANK) {
		return COULD_MOVE_B;
	}
	else if (map[tx][ty] == WALL) {
		return COULD_NOT_MOVE;
	}
	else if (map[tx][ty] == BOX) {
		if (ttx == EDGE || ttx == EDGE_R || tty == EDGE || tty == EDGE_D) {
			return COULD_NOT_MOVE;
		}
		else if (map[ttx][tty] == BLANK) {
			return COULD_PULL_B;
		}
		else if (map[ttx][tty] == WALL) {
			return COULD_NOT_MOVE;
		}
		else if (map[ttx][tty] == BOX) {
			return COULD_NOT_MOVE;
		}
		else if (map[ttx][tty] == DEST) {
			return COULD_PULL_D;
		}
		else if (map[ttx][tty] == DONE) {
			return COULD_NOT_MOVE;
		}
	}
	else if (map[tx][ty] == DEST) {
		return COULD_MOVE_B;
	}
	else if (map[tx][ty] == DONE) {
		if (ttx == EDGE || ttx == EDGE_R || tty == EDGE || tty == EDGE_D) {
			return COULD_NOT_MOVE;
		}
		else if (map[ttx][tty] == BLANK) {
			return COULD_PULL_D_B;
		}
		else if (map[ttx][tty] == WALL) {
			return COULD_NOT_MOVE;
		}
		else if (map[ttx][tty] == BOX) {
			return COULD_NOT_MOVE;
		}
		else if (map[ttx][tty] == DEST) {
			return COULD_PULL_D_D;
		}
		else if (map[ttx][tty] == DONE) {
			return COULD_NOT_MOVE;
		}
	}
}

/**ǰ����ܳ��ֵ����
 * '��ͼ��Ե'
 * '�հ�'
 * 'ǽ'
 * '����'
	* ����ǰ����ܳ��ֵ����
		* '��ͼ��Ե'
		* '�հ�'
		* 'ǽ'
		* '����'
		* 'Ŀ�ĵ�'
		* '����ɵ�����'
 * 'Ŀ�ĵ�'
 * '����ɵ�����'
	* ����ǰ����ܳ��ֵ����
		* '��ͼ��Ե'
		* '�հ�'
		* 'ǽ'
		* '����'
		* 'Ŀ�ĵ�'
		* '����ɵ�����'
 */


 // �ƶ���ָ���ͼ

void mapRec(int x, int y)
{
	map[x][y] = recoveryMAP[x][y];
}