
// ������Ϸ�ĺ���

#include "head.h"
#include "define.h"
#include "func.h"
#include "data.h"

void startGame(void)
{
	// ��ʼ������
	initData();

	// ���Ƶ�ͼ
	drawMap();

	// ѭ������
	do {
		direction = _getch();// ��ȡ��������
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
		case 'n':
		case 'N':
			nextLevel();
			break;
		case 'b':
		case 'B':
			prevLevel();
			break;
		default:
			; // �������İ���ִ�п����
		}
		drawMap();      // ���Ƶ�ͼ
	} while (boxes);    // ����������Ϊ0ʱѭ��

	// ����ѭ��˵����Ϸ������������һ��
	nextLevel();
}