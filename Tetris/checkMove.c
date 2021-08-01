//checkMove.c
//파일입출력 기능 쉬운문제 1

#include "myTetris.h"

extern Point blockPattern[MY_PATTERN_NUM][4][4];
extern int block_type;
extern unsigned char baseground[MY_HIGH][MY_WIDTH];

int checkMove(int row, int column, int direction) {
	int x, y, i;
	for (i = 0; i < 4; i++) {

		x = column + blockPattern[block_type][direction][i].column;
		y = row + blockPattern[block_type][direction][i].row;

		if (baseground[y][x] != MY_SPACE) return CANNOT_MOVE;
	}
	return CAN_MOVE;
}