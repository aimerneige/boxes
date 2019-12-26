
// ��ʼ����ͼ�ĺ���

#include "head.h"
#include "define.h"
#include "func.h"
#include "data.h"

// ��Щ���������������ã��ʵ�������

// ��ʼ��������ͼ�ĺ���
void initMap_1(void);
void initMap_2(void);
void initMap_3(void);
void initMap_4(void);
void initMap_5(void);
void initMap_6(void);
void initMap_7(void);
void initMap_8(void);
void initMap_9(void);
void initMap_10(void);
void initMap_11(void);
void initMap_12(void);
void initMap_13(void);
void initMap_14(void);
void initMap_15(void);
void initMap_NULL(void); // �������������������ͼ

void init(int w, int h);        // ��ʼ��һ���յĴ�д��ĵ�ͼ
int** map_malloc(int h, int w); // Ϊ��ͼ�����ڴ�
void map_free(int** map);       // �ͷŵ�ͼ���ڵĶ�ά������ڴ�ռ�

void initMap(int level)
{
	switch (level) {
	case 1:
		initMap_1();
		break;
	case 2:
		initMap_2();
		break;
	case 3:
		initMap_3();
		break;
	case 4:
		initMap_4();
		break;
	case 5:
		initMap_5();
		break;
	case 6:
		initMap_6();
		break;
	case 7:
		initMap_7();
		break;
	case 8:
		initMap_8();
		break;
	case 9:
		initMap_9();
		break;
	case 10:
		initMap_10();
		break;
	case 11:
		initMap_11();
		break;
	case 12:
		initMap_12();
		break;
	case 13:
		initMap_13();
		break;
	case 14:
		initMap_14();
		break;
	case 15:
		initMap_15();
		break;
	default:
		initMap_NULL();
		break;
	}
}

int** map_malloc(int w, int h)
{
	// �������Ϊ���ʱ������ɿ�ָ������޷������ڴ棬ֱ�ӷ���NULL
	// NULL����ɳ��������Ϊ��ֹ�����������Ҫ�����߱�֤����������������
	if (w <= 0 || h <= 0) {
		return NULL;
	}

	// ���ȴ�����ʱ���ر���
	int** ret = NULL;

	// ʹ��malloc����ռ�
	ret = (int**)malloc(sizeof(int*) * h);
	for (int i = 0; i < h; i++) {
		ret[i] = (int*)malloc(sizeof(int) * w);
	}

	// �����ѿ��ٿռ�ĵ�ַ
	return ret;
}

void map_free(int** map)
{
	// ���ͷ��ڲ���ڴ�
	for (int i = 0; i < height; i++) {
		free(map[i]);
	}

	// �ͷ������ڴ�
	free(map);
}

void init(int h, int w)
{
	// Ϊ��ֹ�ڴ�����������ͷžɵ�ͼ���ڴ�
	map_free(recoveryMAP);
	map_free(restartMAP);
	map_free(map);

	// Ϊ�µĵ�ͼ���ٿռ�
	recoveryMAP = map_malloc(w, h);
	restartMAP = map_malloc(w, h);
	map = map_malloc(w, h);

	// �趨��ͼ��ߵ�ȫ�ֱ���
	height = h;
	width = w;
}

void initMap_1(void)
{
	// ���ȳ�ʼ��һ���յĴ�д��ĵ�ͼ
	init(8, 8);

	// ����ȫ�ֱ����еĵ�ͼ���ݲ�д��ղŴ����õĿյ�ͼ
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_1[i][j];
			restartMAP[i][j] = map_1[i][j];
			recoveryMAP[i][j] = recMap_1[i][j];
		}
	}
}

// ֮���������ȫһ�£�����׸��

void initMap_2(void)
{
	init(8, 8);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_2[i][j];
			restartMAP[i][j] = map_2[i][j];
			recoveryMAP[i][j] = recMap_2[i][j];
		}
	}
}

void initMap_3(void)
{
	init(9, 10);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_3[i][j];
			restartMAP[i][j] = map_3[i][j];
			recoveryMAP[i][j] = recMap_3[i][j];
		}
	}
}

void initMap_4(void)
{
	init(10, 11);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_4[i][j];
			restartMAP[i][j] = map_4[i][j];
			recoveryMAP[i][j] = recMap_4[i][j];
		}
	}
}

void initMap_5(void)
{
	init(9, 7);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_5[i][j];
			restartMAP[i][j] = map_5[i][j];
			recoveryMAP[i][j] = recMap_5[i][j];
		}
	}
}

void initMap_6(void)
{
	init(8, 8);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_6[i][j];
			restartMAP[i][j] = map_6[i][j];
			recoveryMAP[i][j] = recMap_6[i][j];
		}
	}
}

void initMap_7(void)
{
	init(7, 8);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_7[i][j];
			restartMAP[i][j] = map_7[i][j];
			recoveryMAP[i][j] = recMap_7[i][j];
		}
	}
}

void initMap_8(void)
{
	init(8, 8);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_8[i][j];
			restartMAP[i][j] = map_8[i][j];
			recoveryMAP[i][j] = recMap_8[i][j];
		}
	}
}

void initMap_9(void)
{
	init(9, 7);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_9[i][j];
			restartMAP[i][j] = map_9[i][j];
			recoveryMAP[i][j] = recMap_9[i][j];
		}
	}
}

void initMap_10(void)
{
	init(9, 10);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_10[i][j];
			restartMAP[i][j] = map_10[i][j];
			recoveryMAP[i][j] = recMap_10[i][j];
		}
	}
}

void initMap_11(void)
{
	init(8, 7);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_11[i][j];
			restartMAP[i][j] = map_11[i][j];
			recoveryMAP[i][j] = recMap_11[i][j];
		}
	}
}

void initMap_12(void)
{
	init(9, 9);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_12[i][j];
			restartMAP[i][j] = map_12[i][j];
			recoveryMAP[i][j] = recMap_12[i][j];
		}
	}
}

void initMap_13(void)
{
	init(8, 10);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_13[i][j];
			restartMAP[i][j] = map_13[i][j];
			recoveryMAP[i][j] = recMap_13[i][j];
		}
	}
}

void initMap_14(void)
{
	init(10, 9);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_14[i][j];
			restartMAP[i][j] = map_14[i][j];
			recoveryMAP[i][j] = recMap_14[i][j];
		}
	}
}

void initMap_15(void)
{
	init(8, 9);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = map_15[i][j];
			restartMAP[i][j] = map_15[i][j];
			recoveryMAP[i][j] = recMap_15[i][j];
		}
	}
}


// �˴���ʼ���˸�����ĵ�ͼ
// �û���Ӧ�ÿ��������ͼ
// ������Թ����г����������ͼ������������bug
void initMap_NULL(void)
{
	init(4, 3);

	map[0][0] = WALL; map[0][1] = WALL;  map[0][2] = WALL;
	map[1][0] = WALL; map[1][1] = HUMAN; map[1][2] = WALL;
	map[2][0] = WALL; map[2][1] = WALL;  map[2][2] = WALL;
	map[3][0] = BOX;  map[3][1] = BOX;   map[3][2] = BOX;


	recoveryMAP[0][0] = WALL; recoveryMAP[0][1] = WALL;  recoveryMAP[0][2] = WALL;
	recoveryMAP[1][0] = WALL; recoveryMAP[1][1] = HUMAN; recoveryMAP[1][2] = WALL;
	recoveryMAP[2][0] = WALL; recoveryMAP[2][1] = WALL;  recoveryMAP[2][2] = WALL;
	recoveryMAP[3][0] = BOX;  recoveryMAP[3][1] = BOX;   recoveryMAP[3][2] = BOX;

	restartMAP[0][0] = WALL; restartMAP[0][1] = WALL;  restartMAP[0][2] = WALL;
	restartMAP[1][0] = WALL; restartMAP[1][1] = HUMAN; restartMAP[1][2] = WALL;
	restartMAP[2][0] = WALL; restartMAP[2][1] = WALL;  restartMAP[2][2] = WALL;
	restartMAP[2][0] = BOX;  restartMAP[2][1] = BOX;   restartMAP[2][2] = BOX;
}