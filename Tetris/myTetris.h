//myTetris.h
#pragma once
#ifndef _MY_TETRIS_H
#define _MY_TETRIS_H

#define MY_PATTERN_NUM 6
#define MY_WIDTH       12
#define MY_HIGH        20
#define MY_DELAY_TIME  1000
#define MY_MIN_DELAY   100

//key값
#define SPACE	       32	// 입력용
#define MY_SPACE       0x0F  // 출력용
#define MY_WALL        0xF0
#define MY_BLOCK_1     0
#define MY_BLOCK_2     1
#define MY_BLOCK_3     2
#define MY_BLOCK_4     3
#define MY_BLOCK_5     4
#define MY_BLOCK_6_BOMB 5
//#define MY_BLOCK_BOMB_ROW  7
//#define MY_BLOCK_BOMB_COLUMN 8

#define MY_BASE_BLOCK   9
#define MY_BLOCK_SHADOW 22
#define CAN_MOVE       1
#define CANNOT_MOVE    0

#define MY_KEY_UP      72
#define MY_KEY_DOWN    80
#define MY_KEY_RIGHT   77
#define MY_KEY_LEFT    75
#define MY_KEY_SPACE   32
#define MY_KEY_PAUSE   'P' //일시정지, 다시p누르면 시작함

#define MY_GAME_STOP 0
#define MY_GAME_GO 1

typedef struct _Point {
	int row;    //행
	int column; //열
}Point;

void init();
void newBlock();
void display(int);
unsigned char getKey();
void getMove(int key, int* row, int* column, int* dir);
int delayFunction(unsigned int t);
int checkMove(int row, int column, int direction);
void moveBlock(int row, int column, int direction, int key);
void copyBlock();
void removeLines();
int removeLine(int);
int checkFinish();
void gotoxy(int x, int y);
//void bomb();
void BombRemove(int* row, int* column);
void tetrisLevel();
void blockShadow(int x, int y);
//void previousShow();

#endif