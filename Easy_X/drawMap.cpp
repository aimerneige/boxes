
// ���Ƶ�ͼ�ĺ���

#include "head.h"
#include "define.h"
#include "func.h"
#include "data.h"


// ������Ϸ��ͼ
// ����֮ǰ�豣֤ȫ�ֱ���map����������height��width��Ϣ��ˢ��
void drawMap(void)
{
	// ��ʼ������ͼ���Ա�֤�ڵ��������ͼƬ������˸��
	BeginBatchDraw();

	// �������ͼƬ
	putimage(0, 0, &BkImg);

	// �����ͼ����������Ϸ���棩
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			putimage(BLOCK * (j + 2), BLOCK * (i + 2), mapPicLoad(map[i][j]));
		}
	}

	// ���˵����Ϣ
	putimage(1179, 0, &Explain);

	// ������½ǵ�Miku
	putimage(1179, 260, &Miku);

	// ���������ͼ����
	FlushBatchDraw();

	// ����������ͼ
	EndBatchDraw();
}

// ���ض�Ӧ��ͼƬ���ã�Ӧ�ñ���Ϊ���ðɣ�
IMAGE* mapPicLoad(int id)
{
	switch (id) {
	case BLANK:
		return &Blank;
		break;
	case WALL:
		return &Wall;
		break;
	case HUMAN:
		return &Human;
		break;
	case BOX:
		return &Box;
		break;
	case DEST:
		return &Dest;
		break;
	case DONE:
		return &Box_D;
		break;
	default:
		return NULL;
	}
}