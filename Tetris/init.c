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

	//baseground 초기화
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

	//블럭 선택
	srand(time(NULL));
	block_type = rand() % MY_PATTERN_NUM;
	block_dir = rand() % 4;//direct =4개

	next_block_type = rand() % MY_PATTERN_NUM;
	next_block_dir = rand() % 4;
	//block위치 초기화
	block_row = 1;
	block_column = (rand() % (MY_WIDTH - 5)) + 1;

	//oldplayground초기화 .c.h주니까 2시간 30분 개발 화요일 9시반 아주쉬운문제1, 파일입출력 사이즈 읽어오고 점수기록하기 등.. 추가기능 
	//display에서 oldplayground와 playground의 값이 다른경우에만 인쇄하기 때문에
	//처음 게임을 시작할 때 display되게 하기 위해 초기화한다.
	for (i = 0; i < MY_HIGH; i++) {
		for (j = 0; j < MY_WIDTH; j++) {
			oldplayground[i][j] = 0xFF;
		}
	}
}