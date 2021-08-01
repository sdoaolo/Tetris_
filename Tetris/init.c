//init
#include"myTetris.h"
#include<time.h>
#include<windows.h>

extern Point blockPattern[MY_PATTERN_NUM][4][4];
extern unsigned char oldplayground[MY_HIGH][MY_WIDTH];
extern unsigned char baseground[MY_HIGH][MY_WIDTH];

extern int next_block_type;
extern int next_block_dir;

extern int block_type;
extern int block_dir;
extern int block_row;
extern int block_column;

void init() {
	int i, j;
	int x, y;

	//baseground �ʱ�ȭ
	for (i = 0; i < MY_HIGH; i++) {
		for (j = 0; j < MY_WIDTH; j++) {
			baseground[i][j] = MY_SPACE;
		}
	}
	for (i = 0; i < MY_WIDTH; i++)
		baseground[0][i] = MY_WALL;
	for (i = 0; i < MY_WIDTH; i++)
		baseground[MY_HIGH - 1][i] = MY_WALL;
	for (i = 0; i < MY_HIGH; i++)
		baseground[i][0] = MY_WALL;
	for (i = 0; i < MY_HIGH; i++)
		baseground[i][MY_WIDTH - 1] = MY_WALL;

	//�� ����
	srand(time(NULL));
	block_type = rand() % MY_PATTERN_NUM;
	block_dir = rand() % 4;//direct =4��

	next_block_type = rand() % MY_PATTERN_NUM;
	next_block_dir = rand() % 4;
	//block��ġ �ʱ�ȭ
	block_row = 1;
	block_column = (rand() % (MY_WIDTH - 5)) + 1;

	//oldplayground�ʱ�ȭ .c.h�ִϱ� 2�ð� 30�� ���� ȭ���� 9�ù� ���ֽ����1, ��������� ������ �о���� ��������ϱ� ��.. �߰���� 
	//display���� oldplayground�� playground�� ���� �ٸ���쿡�� �μ��ϱ� ������
	//ó�� ������ ������ �� display�ǰ� �ϱ� ���� �ʱ�ȭ�Ѵ�.
	for (i = 0; i < MY_HIGH; i++) {
		for (j = 0; j < MY_WIDTH; j++) {
			oldplayground[i][j] = 0xFF;
		}
	}
}