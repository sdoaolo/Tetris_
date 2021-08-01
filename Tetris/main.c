//main.c
#include<stdio.h>
#include <windows.h>
#include "myTetris.h"

unsigned char playground[MY_HIGH][MY_WIDTH] = { 0 }; //display
unsigned char oldplayground[MY_HIGH][MY_WIDTH] = { 0 };
unsigned char baseground[MY_HIGH][MY_WIDTH] = { 0 };
extern unsigned char previousground[4][4];
int block_type;
int block_dir;//direct
int block_row;
int block_column;
int next_block;
int score = 0, count = 0;
extern int scoreA;
extern int scoreB;
extern int level;
extern int delayFuntion_T;
int forBomb = 0; //15���� 1�� bomb����� �������� �ϴ� ����
extern char name[20];
int bestscore = 0;
extern int check_IS_THIS_FIRST_TIME_EVER;

unsigned char nextblock[4][4] =
{ 0x0F, 0x0f, 0x0F, 0x0f,
0x0F, 0x0f, 0x0F, 0x0f,
0x0F, 0x0f, 0x0F, 0x0f,
0x0F, 0x0f, 0x0F, 0x0f };

int bRow, bColumn, bDir, bType;
int currentScore;

int next_block_type;
int next_block_dir;

int main() {
	unsigned char key;
	int row, column, dir;
	int delayTime = MY_DELAY_TIME;

	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);

	system("mode con: cols=150 lines=40");


	block_type = 100;
	game_start();
	init();
	display(1);

	while (1) {
		key = NULL;
		tetrisLevel();
		if (delayFunction(delayFuntion_T)) key = MY_KEY_DOWN;
		else key = getKey();

		if (key != NULL) {
			if (key == 'q') break;
			getMove(key, &row, &column, &dir);
			if (checkMove(row, column, dir) == CAN_MOVE) //1
			{
				moveBlock(row, column, dir, key);
				display(1);
			}
			else if (key == MY_KEY_DOWN) {
				copyBlock();
				removeLines();

				/*if (block_type > 6 && block_type < 9)//6~8 (MY_BLOCK_BOMB_ROW ~ MYBLOCK_BOMB_COLUMN
					BombRemove(&row, &column);//bomb���� ����� ��

				forBomb += 1;
				if (forBomb % 15 == 0)
					bomb();
				else*/
				if (block_type == MY_BLOCK_6_BOMB)
					BombRemove(&row, &column);

				newBlock();


				if (!checkFinish()) break;
				display(1);
			}
		}
	}
	if (check_IS_THIS_FIRST_TIME_EVER == 1) {
		if (score > 1)
			bestscore = score;
	}
	else {
		if (bestscore < score)
			bestscore = score;
	}
	PutScore(name);

	//��ź��� �� �������� ���� �����ֱ�? ��ź��� 7 
	//preview
	//�׸��� �������� ���������� �����ִ� �������... >�׸��ڴ� 6 void blockShadow ()
	//score.. v
	//�ð��������� ���� int ���� �ö󰡸� v
	//�Ʒ��� ���ο� ������ �߰� �Ǵ°���

	gotoxy(4, 9);
	printf("                 \n");
	gotoxy(4, 10);
	printf("G A M E _ O V E R\n");
	printf("                 ");

	Sleep(2000);
	system("cls");

	//printScore();
	return 0;
}

