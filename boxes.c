/* Only Win Permitted */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// #define WIDTH 8
// #define HEIGHT 8

void initData(void); // ��ʼ������
void drawMap(void); // ���ƻ���
void moveUp(void); // �����ƶ�
void moveDown(void); // �����ƶ�
void moveLeft(void); // �����ƶ�
void moveRight(void); // �����ƶ�
void move(char direction); // �ƶ�

int map[8][8] = {
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 4, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 3, 0, 3, 4, 1},
        {1, 4, 0, 3, 2, 1, 1, 1},
        {1, 1, 1, 1, 3, 1, 0, 0},
        {0, 0, 0, 1, 4, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0}
}; // ��ͨ����ά����ʵ�ֶ�ؿ�
/**
 * 0 ��ʾ��
 * 1 ��ʾǽ
 * 2 ��ʾ��
 * 3 ��ʾ����
 * 4 ��ʾĿ�ĵ�
 * 5 ��ʾ����ɵ�����
 */

int x = 0;
int y = 0;

int boxes = 0;

// int course = 1; // ��ͨ����ά����ʵ�ֶ�ؿ�

// int error = 0;

int main()
{
    char direction;
    initData();
    printf("Press \"w a s d\" to move.\n");
    // printf("Press \"w a s d\" to move and press r to restart.\n");
    drawMap();
    direction = getch();
    while ( boxes ) {
        move(direction);
        system("cls");
        drawMap();
        direction = getch();
    }
    printf("You win!\n");

    return 0;
}


void initData(void)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ( map[i][j] == 2 ) {
                x = i;
                y = j;
            } else if ( map [i][j] == 3) {
                boxes++;
            }
        }
    }
}

void drawMap(void)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int temp = map[i][j];
            switch (temp) {
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
                    // default:
                    // printf("Error Happens!\n");
                    // error = 1;
                    // return;
            }
        }
        printf("\n");
    }
} // Tested

/** �ƶ�ʱ�Ŀ���
 * ǰ����ǽ
 * ǰ���ǿհ�
 * ǰ�������� -- ����ǰ���� 'ǽ' '�հ�' '����' 'Ŀ�ĵ�' '��ɵ�����'
 * ǰ����Ŀ�ĵ�
 * ǰ������ɵ�����
 */

void moveUp(void)
{

}

void moveDown(void)
{

}

void moveLeft(void)
{

}

void moveRight(void)
{

}

void move(char direction)
{
    switch (direction) {
        case 'w':
            moveUp();
            break;
        case 'a':
            moveLeft();
            break;
        case 's':
            moveDown();
            break;
        case 'd':
            moveRight();
            break;
        default:
            direction = getch();
            move(direction);
    }
}