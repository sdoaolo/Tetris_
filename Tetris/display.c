//display
#include<stdio.h>
#include <Windows.h>
#include "myTetris.h"
extern unsigned char playground[MY_HIGH][MY_WIDTH];
extern unsigned char oldplayground[MY_HIGH][MY_WIDTH];
extern unsigned char baseground[MY_HIGH][MY_WIDTH];
extern Point blockPattern[MY_PATTERN_NUM][4][4];

extern int block_type;
extern int block_dir;
extern int block_row;
extern int block_column;
extern int score, count;
extern int level;
extern int bestscore;
extern unsigned char nextblock[4][4];
extern int next_block_type;
extern int next_block_dir;

//	flag = 1, block �߰�
//	flag = 0, remove line -> �� �߰� ����

void display(int flag) {
	int i, k;
	int x, y;

	int check_shadow = 0;
	int tmp_y = 0;
	int tmp_x = 0;
	int onlyone1 = 1;
	int onlyone2 = 1;

	int test = 0;
	for (i = 0; i < MY_HIGH; i++) { //baseground�� playground�� �����ϴ�.
		for (k = 0; k < MY_WIDTH; k++) {
			playground[i][k] = baseground[i][k];
		}
	}

	if (flag == 1) //���� ��ġ�� ����Ͽ� playground�� �߰��Ѵ�.
	{
		//int j = MY_HIGH - 2;
		//int h = 0;
		for (i = 0; i < 4; i++) {
			y = block_row + blockPattern[block_type][block_dir][i].row;
			x = block_column + blockPattern[block_type][block_dir][i].column;
			blockShadow(x, y);
			playground[y][x] = block_type;
		}
	}

	for (i = 0; i < MY_HIGH; i++) { //playground ����â�� ����Ѵ�.
		for (k = 0; k < MY_WIDTH; k++) {
			//playground�� old���Ͽ� ���� �ٸ� �κи� ����Ѵ�.
			if (playground[i][k] != oldplayground[i][k]) {
				gotoxy(k * 2, i);
				switch (playground[i][k])
				{
				case MY_SPACE:
					printf("  ");
					break;
				case MY_WALL:
					printf("��");
					break;
				case MY_BLOCK_6_BOMB: //MY_BLOCK_BOMB_ROW:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //������
					printf("��");
					break;
					/*case MY_BLOCK_BOMB_COLUMN:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //������
						printf("��");
						break;*/
				case MY_BLOCK_SHADOW:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); //�Ƹ� ȸ��
					printf("��");
					break;
				case MY_BLOCK_1://�׸���, ������, ��ź��, ����?> �����ϴ°� // �ö���°�, ������
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //�Ķ���
					printf("��");
					break;
				case MY_BLOCK_2:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //�����
					printf("��");
					break;
				case MY_BLOCK_3:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //���ֻ�
					printf("��");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //���
					break;
				case MY_BLOCK_4:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //�ʷϻ�
					printf("��");
					break;
				case MY_BLOCK_5:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); //����
					printf("��");
					break;
				case MY_BASE_BLOCK:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //�ʷϻ�
					printf("��");
					break;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //���
			}
		}
	}
	//score ���
	gotoxy(0, 20);
	printf("Score: %3d", score);
	gotoxy(15, 20);
	if (level < 5)
		printf("Level: %3d", level);
	else
		printf("Level: MAX");
	gotoxy(0, 21);
	printf("BEST_score: %3d", bestscore);
	////	next block ���

	gotoxy((int)(MY_WIDTH)+20, 0);
	printf("< NEXT BLOCK TYPE >");

	gotoxy((int)(MY_WIDTH + 7) + 20, 2);
	int A = 2;
	if (flag == 1) {
		for (i = 0; i < 4; i++) {
			y = blockPattern[next_block_type][next_block_dir][i].row;
			x = blockPattern[next_block_type][next_block_dir][i].column;
			nextblock[y][x] = next_block_type;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			switch (nextblock[i][j]) {
			case MY_SPACE:
				printf("  ");
				break;

				/*case MY_BLOCK_BOMB_COLUMN:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //������
					printf("��");
					break;*/
			case MY_BLOCK_SHADOW:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); //ȸ��
				printf("��");
				break;
				break;
			case MY_BLOCK_1://�׸���, ������, ��ź��, ����?> �����ϴ°� // �ö���°�, ������
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //�Ķ���
				printf("��");
				break;
			case MY_BLOCK_2:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //�����
				printf("��");
				break;
			case MY_BLOCK_3:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); //���ֻ�
				printf("��");
				break;
			case MY_BLOCK_4:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("��");
				break;
			case MY_BLOCK_5:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //����
				printf("��");
				break;
			case MY_BLOCK_6_BOMB://MY_BLOCK_BOMB_ROW:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //������
				printf("��");
				break;
			case MY_BASE_BLOCK:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //�ʷϻ�
				printf("��");
				break;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //���
		}
		printf("\n");
		A++;
		gotoxy((int)(MY_WIDTH + 7) + 20, A);
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			nextblock[i][j] = 0x0F;
		}
	}
	//playground�� old�� ī���Ѵ�.
	for (int i = 0; i < MY_HIGH; i++) {
		for (int k = 0; k < MY_WIDTH; k++) {
			oldplayground[i][k] = playground[i][k];
		}
	}


}