
// ��������ͷ�ļ�

#ifndef _FUNC_H_
#define _FUNC_H_

void startGame(void);        // ������Ϸ
void initData(void);         // ��ʼ����Ϸ����
void drawMap(void);          // ���ƻ���
void moveUp(void);           // �����ƶ�
void moveDown(void);         // �����ƶ�
void moveLeft(void);         // �����ƶ�
void moveRight(void);        // �����ƶ�
void mapRec(int x, int y);   // ��ԭ
void move(int stu);          // �ƶ�
int initStatus(void);        // ȷ��״̬
void restart(void);          // ����
void nextLevel(void);        // ǰһ��
void prevLevel(void);        // ��һ��
void initMap(int level);     // ��ʼ����ͼ����
IMAGE* mapPicLoad(int id);   // ���ض�Ӧ��ͼƬ����
void loadImage(void);        // ����ͼƬ��Դ

#endif