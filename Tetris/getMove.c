//getMove.c
#include "myTetris.h"

extern int block_dir;
extern int block_row;
extern int block_column;

void getMove(int key, int* row, int* column, int* dir)
{
	*row = block_row;
	*column = block_column;
	*dir = block_dir;

	switch (key)
	{
	case MY_KEY_UP:
		*dir = (block_dir + 1) % 4;
		break;
	case MY_KEY_DOWN:
		*row = block_row + 1;
		break;
	case MY_KEY_LEFT:
		*column = block_column - 1;
		break;
	case MY_KEY_RIGHT:
		*column = block_column + 1;
		break;
	}
}