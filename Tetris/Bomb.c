//bomb.c
#include "myTetris.h"
extern int block_row;
extern int block_column;
extern int block_type;
extern unsigned char baseground[MY_HIGH][MY_WIDTH];
extern int score;

/*void bomb() {
	block_type = rand() % 2 + 7;
	block_row = 1;
	block_column = (rand() % (MY_WIDTH - 5)) + 1;
}*/
void BombRemove(int* row, int* column) {
	int i;
	score += 10; //폭탄 블럭은 무조건 10점이다
	switch (block_type)
	{
	case MY_BLOCK_6_BOMB:// MY_BLOCK_BOMB_ROW:
		for (i = MY_HIGH - 2; i > 1; i--) {
			baseground[i][*column] = MY_SPACE;
		}
		break;
		/*
	case MY_BLOCK_BOMB_COLUMN:
		for (i = 1; i < MY_WIDTH-1; i++) {
			baseground[*row-1][i] = MY_SPACE;
		}
		for (i = *row-1; i > 1; i--) {
			for (int k = 1; k < MY_WIDTH; k++) {
				baseground[i][k] = baseground[i - 1][k];
			}
		}
		break;
		*/
	}

}
