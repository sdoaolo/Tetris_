//newBlock.c
#include "myTetris.h"

extern int next_block_type;
extern int next_block_dir;
extern int block_dir;
extern int block_row;
extern int block_column;
extern int block_type;

void newBlock() {
	block_type = next_block_type;
	block_dir = next_block_dir;

	next_block_type = rand() % MY_PATTERN_NUM;
	next_block_dir = rand() % 4;

	block_row = 1;
	block_column = (rand() % (MY_WIDTH - 5)) + 1;
}