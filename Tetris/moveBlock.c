//moveBlock.c
#include "myTetris.h"

extern int block_dir;
extern int block_row;
extern int block_column;

//getmove에서 계산된 좌표값을
void moveBlock(int row, int column, int dir, int key) {
	block_row = row;
	block_column = column;
	block_dir = dir;

	if (key == MY_KEY_SPACE) //스패이스 누르면 바로 내리기 기능
	{
		while (1) {
			if (!checkMove(block_row, block_column, block_dir)) {
				block_row--;
				break;
			}
			block_row++;
		}
	}
}