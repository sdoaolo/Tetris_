//checkFInish.c_1
#include "myTetris.h"
extern int block_dir;
extern int block_row;
extern int block_column;

int checkFinish() {
	//새로운 블럭이 생성 될 수 없으면 종료
	if (!checkMove(block_row, block_column, block_dir))
		return MY_GAME_STOP;
	//새로운 블럭이 움직일 수 없으면 종료
	if (checkMove(block_row + 1, block_column, block_dir))
		return MY_GAME_GO;
	else if (checkMove(block_row, block_column + 1, block_dir))
		return MY_GAME_GO;
	else if (checkMove(block_row, block_column - 1, block_dir))
		return MY_GAME_GO;
	else if (checkMove(block_row, block_column, (block_dir + 1) % 4))
		return MY_GAME_GO;
}