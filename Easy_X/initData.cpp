
// ��ʼ�����ݵĺ���

#include "head.h"
#include "define.h"
#include "func.h"
#include "data.h"

// ��ʼ����������
void initData(void)
{
	// �����ͼ
	initMap(level); // �˴�level�ѱ���ʼ��Ϊ1

	// ��ʼ��������
	boxes = 0;

	// �����������
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (map[i][j] == 2) {
				x = i;
				y = j;
			}
			if (map[i][j] == 3) {
				boxes++;
			}
		} // �ڲ�ѭ������
	}
}// ��������
