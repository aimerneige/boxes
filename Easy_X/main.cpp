
// main����

#include "head.h"
#include "define.h"
#include "func.h"
#include "data.h"

int main()
{
	// ��ʼ������
	initgraph(Width, Height);

	// ��ȡͼƬ��Դ�ļ�
	loadImage();

	// ������Ϸ
	startGame();

	// �رջ�ͼ����
	closegraph();

	// ������Ϸ
	return 0;
}