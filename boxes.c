/**Something need to add
 * Only Win Permitted 
 * Can't Restart
 * Don't have more level/course
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Can't use on Linux and some other device

// #define WIDTH 8
// #define HEIGHT 8

// void initData(void); // ��ʼ������
// void drawMap(void); // ���ƻ���
// void moveUp(void); // �����ƶ�
// void moveDown(void); // �����ƶ�
// void moveLeft(void); // �����ƶ�
// void moveRight(void); // �����ƶ�
// void move(char direction); // �ƶ�
// Just for remind an accident.

void initData(void); // ��ʼ������
void drawMap(void); // ���ƻ���
void moveUp(void); // �����ƶ�
void moveDown(void); // �����ƶ�
void moveLeft(void); // �����ƶ�
void moveRight(void); // �����ƶ�
void move(char direction); // �ƶ�
void mapRec(int x, int y); // ��ԭ
void restart(void); // ����

const int recMAP[8][8] = {
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 4, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 4, 1},
        {1, 4, 0, 0, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 4, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0}
}; // ��ͼ�Ļָ������ں���

const int resMAP[8][8] = {
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 4, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 3, 0, 3, 4, 1},
        {1, 4, 0, 3, 2, 1, 1, 1},
        {1, 1, 1, 1, 3, 1, 0, 0},
        {0, 0, 0, 1, 4, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0}
}; // ��ͼ�Ļָ�����������

int map[8][8] = {
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 4, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 3, 0, 3, 4, 1},
        {1, 4, 0, 3, 2, 1, 1, 1},
        {1, 1, 1, 1, 3, 1, 0, 0},
        {0, 0, 0, 1, 4, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0}
}; // ���ڸ��ļ�����Ķ�̬��ͼ
// ��ͨ����ά����ʵ�ֶ�ؿ�

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

int main()
{
    char direction;
    initData();
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
            }
            if ( map [i][j] == 3) {
                boxes++;
            }
        }
    }
}

void drawMap(void)
{
    printf("Press \"w a s d\" to move.\nPress \"r\" to restart game.\n");
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
                default:
                    printf("That's impossible to print this.\nIf you see this, I's mean that there have some error happens.\nYou can connect me on GitHub.\n@ aimerneige");
            }
        }
        printf("\n");
    }
}

void move(char direction)
{
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
        default:
            direction = getch();
            move(direction);
    }
}

/**ǰ����ܳ��ֵ����
 * ǰ���ǿհף�0��
 * ǰ����ǽ��1��
 * ǰ�������ӣ�3��
    * ����ǰ����ܳ��ֵ����
        * '�հ�' ��0��
        * 'ǽ' ��1��
        * '����' ��3��
        * 'Ŀ�ĵ�' ��4��
        * '����ɵ�����' ��5��
 * ǰ����Ŀ�ĵأ�4��
 * ǰ��������ɵ����ӣ�5��
    * ����ǰ����ܳ��ֵ����
        * '�հ�' ��0��
        * 'ǽ' ��1��
        * '����' ��3��
        * 'Ŀ�ĵ�' ��4��
        * '����ɵ�����' ��5��
 */

void moveUp(void)
{
    if (x == 0) {
        return;
    }
    int tx, ty;
    tx = x - 1;
    ty = y;
    if ( map[tx][ty] == 0 ) {
        map[tx][ty] = 2;
        mapRec(x, y);
    } else if ( map[tx][ty] == 1 ) {
        return;
    } else if ( map[tx][ty] == 3 ) {
        if ( tx == 0 ) {
            return;
        }
        int ttx, tty;
        ttx = tx - 1;
        tty = ty;
        if ( map[ttx][tty] == 0 ) {
            map[ttx][tty] = 3;
            map[tx][ty] = 2;
            mapRec(x, y);
        } else if ( map[ttx][tty] == 1 ) {
            return;
        } else if ( map[ttx][tty] == 3 ) {
            return;
        } else if ( map[ttx][tty] == 4 ) {
            map[ttx][tty] = 5;
            map[tx][ty] = 2;
            mapRec(x, y);
            boxes--;
        } else if ( map[ttx][tty] == 5 ) {
            return;
        }
    } else if ( map[tx][ty] == 4 ) {
        map[tx][ty] = 2;
        mapRec(x, y);
    } else if ( map[tx][ty] == 5 ) {
        if ( tx == 0 ) {
            return;
        }
        int ttx, tty;
        ttx = tx - 1;
        tty = ty;
        if ( map[ttx][tty] == 0 ) {
            map[ttx][tty] = 3;
            map[tx][ty] = 2;
            mapRec(x, y);
            boxes++;
        } else if ( map[ttx][tty] == 1 ) {
            return;
        } else if ( map[ttx][tty] == 3 ) {
            return;
        } else if ( map[ttx][tty] == 4 ) {
            map[ttx][tty] = 5;
            map[tx][ty] = 2;
            mapRec(x, y);
        } else if ( map[ttx][tty] == 5 ) {
            return;
        }
    }
}

void moveDown(void)
{
    if (x == 7) {
        return;
    }
    int tx, ty;
    tx = x + 1;
    ty = y;
    if ( map[tx][ty] == 0 ) {
        map[tx][ty] = 2;
        mapRec(x, y);
    } else if ( map[tx][ty] == 1 ) {
        return;
    } else if ( map[tx][ty] == 3 ) {
        if ( tx == 7 ) {
            return;
        }
        int ttx, tty;
        ttx = tx + 1;
        tty = ty;
        if ( map[ttx][tty] == 0 ) {
            map[ttx][tty] = 3;
            map[tx][ty] = 2;
            mapRec(x, y);
        } else if ( map[ttx][tty] == 1 ) {
            return;
        } else if ( map[ttx][tty] == 3 ) {
            return;
        } else if ( map[ttx][tty] == 4 ) {
            map[ttx][tty] = 5;
            map[tx][ty] = 2;
            mapRec(x, y);
            boxes--;
        } else if ( map[ttx][tty] == 5 ) {
            return;
        }
    } else if ( map[tx][ty] == 4 ) {
        map[tx][ty] = 2;
        mapRec(x, y);
    } else if ( map[tx][ty] == 5 ) {
        if ( tx == 7 ) {
            return;
        }
        int ttx, tty;
        ttx = tx + 1;
        tty = ty;
        if ( map[ttx][tty] == 0 ) {
            map[ttx][tty] = 3;
            map[tx][ty] = 2;
            mapRec(x, y);
            boxes++;
        } else if ( map[ttx][tty] == 1 ) {
            return;
        } else if ( map[ttx][tty] == 3 ) {
            return;
        } else if ( map[ttx][tty] == 4 ) {
            map[ttx][tty] = 5;
            map[tx][ty] = 2;
            mapRec(x, y);
        } else if ( map[ttx][tty] == 5 ) {
            return;
        }
    }
}

void moveLeft(void)
{
    if (y == 0) {
        return;
    }
    int tx, ty;
    tx = x;
    ty = y - 1;
    if ( map[tx][ty] == 0 ) {
        map[tx][ty] = 2;
        mapRec(x, y);
    } else if ( map[tx][ty] == 1 ) {
        return;
    } else if ( map[tx][ty] == 3 ) {
        if ( tx == 0 ) {
            return;
        }
        int ttx, tty;
        ttx = tx;
        tty = ty - 1;
        if ( map[ttx][tty] == 0 ) {
            map[ttx][tty] = 3;
            map[tx][ty] = 2;
            mapRec(x, y);
        } else if ( map[ttx][tty] == 1 ) {
            return;
        } else if ( map[ttx][tty] == 3 ) {
            return;
        } else if ( map[ttx][tty] == 4 ) {
            map[ttx][tty] = 5;
            map[tx][ty] = 2;
            mapRec(x, y);
            boxes--;
        } else if ( map[ttx][tty] == 5 ) {
            return;
        }
    } else if ( map[tx][ty] == 4 ) {
        map[tx][ty] = 2;
        mapRec(x, y);
    } else if ( map[tx][ty] == 5 ) {
        if ( ty == 0 ) {
            return;
        }
        int ttx, tty;
        ttx = tx;
        tty = ty - 1;
        if ( map[ttx][tty] == 0 ) {
            map[ttx][tty] = 3;
            map[tx][ty] = 2;
            mapRec(x, y);
            boxes++;
        } else if ( map[ttx][tty] == 1 ) {
            return;
        } else if ( map[ttx][tty] == 3 ) {
            return;
        } else if ( map[ttx][tty] == 4 ) {
            map[ttx][tty] = 5;
            map[tx][ty] = 2;
            mapRec(x, y);
        } else if ( map[ttx][tty] == 5 ) {
            return;
        }
    }
}

void moveRight(void)
{

    if (y == 7) {
        return;
    }
    int tx, ty;
    tx = x;
    ty = y + 1;
    if ( map[tx][ty] == 0 ) {
        map[tx][ty] = 2;
        mapRec(x, y);
    } else if ( map[tx][ty] == 1 ) {
        return;
    } else if ( map[tx][ty] == 3 ) {
        if ( ty == 7 ) {
            return;
        }
        int ttx, tty;
        ttx = tx;
        tty = ty + 1;
        if ( map[ttx][tty] == 0 ) {
            map[ttx][tty] = 3;
            map[tx][ty] = 2;
            mapRec(x, y);
        } else if ( map[ttx][tty] == 1 ) {
            return;
        } else if ( map[ttx][tty] == 3 ) {
            return;
        } else if ( map[ttx][tty] == 4 ) {
            map[ttx][tty] = 5;
            map[tx][ty] = 2;
            mapRec(x, y);
            boxes--;
        } else if ( map[ttx][tty] == 5 ) {
            return;
        }
    } else if ( map[tx][ty] == 4 ) {
        map[tx][ty] = 2;
        mapRec(x, y);
    } else if ( map[tx][ty] == 5 ) {
        if ( ty == 7 ) {
            return;
        }
        int ttx, tty;
        ttx = tx;
        tty = ty + 1;
        if ( map[ttx][tty] == 0 ) {
            map[ttx][tty] = 3;
            map[tx][ty] = 2;
            mapRec(x, y);
            boxes++;
        } else if ( map[ttx][tty] == 1 ) {
            return;
        } else if ( map[ttx][tty] == 3 ) {
            return;
        } else if ( map[ttx][tty] == 4 ) {
            map[ttx][tty] = 5;
            map[tx][ty] = 2;
            mapRec(x, y);
        } else if ( map[ttx][tty] == 5 ) {
            return;
        }
    }
}

void mapRec(int x, int y)
{
    map[x][y] = recMAP[x][y];
}

void restart(void)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            map[i][j] = resMAP[i][j];
        }
    }
    char direction;
    initData();
    direction = getch();
    move(direction);
}