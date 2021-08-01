//blockShadow.c
#include "myTetris.h"
extern Point blockPattern[MY_PATTERN_NUM][4][4];
extern unsigned char playground[MY_HIGH][MY_WIDTH];
extern unsigned char baseground[MY_HIGH][MY_WIDTH];
extern int block_dir;
extern int block_row;
extern int block_column;
extern int block_type;

void blockShadow(int x, int y) {
	int shadowrow;
	int row2 = block_row;
	int i;
	/*
	while (checkMove(block_row, block_column, block_dir) == CAN_MOVE)
	{
		block_row++;
		shadowrow = block_row;
	}
	shadowrow = block_row--; //shadow_row ¾îµòÁö ¼³Á¤
	block_row = row2;
	*/
	while (1) {
		if (checkMove(block_row, block_column, block_dir)) {

			block_row++;
			shadowrow = block_row;
		}
		else {
			shadowrow = block_row--; //shadow_row ¾îµòÁö ¼³Á¤
			block_row = row2;
			break;
		}
	}

	for (i = 0; i < 4; i++) {
		y = shadowrow + blockPattern[block_type][block_dir][i].row;
		x = block_column + blockPattern[block_type][block_dir][i].column;
		playground[y - 1][x] = MY_BLOCK_SHADOW; //¿Ö ¸ÔÀ»±î..
	}
}