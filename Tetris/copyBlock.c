//copyBlock.c
#include "myTetris.h"

extern int block_dir;
extern int block_row;
extern int block_column;
extern int block_type;
extern Point blockPattern[MY_PATTERN_NUM][4][4];
extern unsigned char baseground[MY_HIGH][MY_WIDTH];

void copyBlock() {
	int x, y, i;
	for (i = 0; i < 4; i++) {
		y = block_row + blockPattern[block_type][block_dir][i].row;
		x = block_column + blockPattern[block_type][block_dir][i].column;
		baseground[y][x] = MY_BASE_BLOCK;
	}
}