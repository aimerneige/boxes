
// ���Ĺؿ��ĺ���

#include "head.h"
#include "define.h"
#include "func.h"
#include "data.h"

// ������һ�ؿ�
void nextLevel(void)
{
	if (level < maxLevel) {
		level++;
	}
	else {
		level = 1; // �ؿ�Ϊ���һ��ʱ���Ϊ��һ�أ�ʵ��ѭ��
	}

	// ����ȫ�ֱ����Ĺؿ��������½�����Ϸ
	startGame();
}

void prevLevel(void)
{
	if (level > 1) {
		level--;
	}
	else {
		level = maxLevel; // �ؿ�Ϊ��һ��ʱ���Ϊ���һ�أ�ʵ��ѭ��
	}

	// ����ȫ�ֱ����Ĺؿ��������½�����Ϸ
	startGame();
}

void restart(void)
{
	// ���½�����Ϸ
	startGame();
}
