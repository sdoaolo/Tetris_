//FILE.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "myTetris.h"
extern int score;
extern int bestscore;
int check_IS_THIS_FIRST_TIME_EVER;
int colorNum[6] = { 0 };
struct Today {
	int year;
	int month;
	int day;
	int time;
	int min;
}Today;

char* buffer;
char* res;

void user(char* name) { //user 이름 입력 함수
	printf("제작 : 18018001 강지은\n\n");
	gotoxy(30, 7);
	printf("T E T R I S >> \n ");
	gotoxy(20, 12);
	printf("ID : ");
	scanf("%s", name);
	system("cls");
}

void PutScore(char* name)
{
	FILE* myScore = fopen("scoreFile.txt", "r");
	if (myScore == NULL) {
		//a new file create
		check_IS_THIS_FIRST_TIME_EVER = 1;
		myScore = fopen("scoreFile.txt", "w");
		fprintf(myScore, "date/time");
		fprintf(myScore, "               name");
		fprintf(myScore, "        score");
		fclose(myScore);
	}

	myScore = fopen("scoreFile.txt", "a");
	char Date[20];
	char Time[20];
	char A = 0;
	_strdate(Date);
	_strtime(Time); //문자열로 date와 time 입력

	Today.year = 2000 + atoi(&Date[6]);
	Today.month = atoi(Date);
	Today.day = atoi(&Date[4]);
	Today.time = atoi(Time);
	Today.min = atoi(&Time[3]);
	fprintf(myScore, "\n%d.%d.%d : %d:%d", Today.year, Today.month, Today.day, Today.time, Today.min); //가 바로 이것인가?
	fprintf(myScore, "       %s", name);
	fprintf(myScore, "       %d", score);
	fclose(myScore);

}

//??????????????????
void setConfig() { //환경변수 설정

	FILE* fp_configuration = fopen("myPuzzleConfig.txt", "r");
	if (fp_configuration == NULL)
		printf(" ");
	else {
		int i = 0;
		while (1) {

			res = fgets(buffer, sizeof(buffer), fp_configuration);
			if (res == NULL) break;

			if (strncmp("BLOCK_1: ", buffer, 9) == 0) {
				if (strncmp("9", &buffer[9], 1) == 0) colorNum[i] = 9;
			}
			else if (strncmp("BLOCK_2: ", buffer, 9) == 0) {
				if (strncmp("10", &buffer[9], 2) == 0) colorNum[i] = 10;
			}
			else if (strncmp("BLOCK_3: ", buffer, 9) == 0) {
				if (strncmp("11", &buffer[9], 2) == 0) colorNum[i] = 11;
			}
			else if (strncmp("BLOCK_4: ", buffer, 9) == 0) {
				if (strncmp("12", &buffer[9], 2) == 0) colorNum[i] = 12;
			}
			else if (strncmp("BLOCK_5: ", buffer, 9) == 0) {
				if (strncmp("13", &buffer[9], 2) == 0) colorNum[i] = 13;
			}
			else if (strncmp("BLOCK_6: ", buffer, 9) == 0) {
				if (strncmp("14", &buffer[9], 2) == 0) colorNum[i] = 14;
			}
			else if (strncmp("SCORE: ", buffer, 7) == 0) {
				strcpy("myScore.txt", &buffer[7]);
			}
			i++;
		}

	}

}
void printScore() {
	FILE* Score = fopen("myScore.txt", "r");
	if (Score == NULL) {
		printf("파일을 열 수 없습니다..");
	}
	while (!feof(Score))
	{
		printf("%c", fgetc(Score));
	}
	fclose(Score);
}