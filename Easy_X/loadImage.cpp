
// ����ͼƬ��Դ�ĺ���
// �����ͼ����ɼ�������

#include "head.h"
#include "define.h"
#include "func.h"
#include "data.h"

void loadImage(void)
{
	/* ����ͼƬ��Դ */

	loadimage(&BkImg, L"res/BackGround.png", Width, Height);  // ����

	loadimage(&Blank, L"res/BLANK.png", BLOCK, BLOCK);   // ��
	loadimage(&Wall, L"res/WALL.png", BLOCK, BLOCK);     // ǽ
	loadimage(&Human, L"res/HUMAN.png", BLOCK, BLOCK);   // ��
	loadimage(&Box, L"res/BOX.png", BLOCK, BLOCK);       // ����
	loadimage(&Box_D, L"res/BOX_DONE.png", BLOCK, BLOCK);   // Ŀ�ĵ�
	loadimage(&Dest, L"res/DEST.png", BLOCK, BLOCK);     // ����ɵ�����

	loadimage(&Miku, L"res/miku.png", 421, 640);       // Miku

	loadimage(&Explain, L"res/Explain.png", 421, 260); // ��Ϸ˵��
}
