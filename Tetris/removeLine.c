//removeLine.c
#include "myTetris.h"
extern unsigned char baseground[MY_HIGH][MY_WIDTH];
extern int score;
int scoreA;
int scoreB;

void removeLines() {
	int i;
	scoreA = 0;
	scoreB = 0;
	for (i = MY_HIGH - 2; i > 0; i--) {
		if (removeLine(i)) {
			display(0);
			delayFunction(500);
			i++;
			scoreA += 1;
			scoreB += scoreA * 10;
			score += scoreB; //���ٸ� ���ָ� 10�� ������ ���ÿ� 40�� ���ߵ��� 100�� ���ߵ���200��
		}
	}
}
int removeLine(int line) {
	int i, k;
	for (i = 1; i < MY_WIDTH; i++) {
		if (baseground[line][i] == MY_SPACE) return 0;
	}
	for (i = line; i > 1; i--) {
		for (k = 1; k < MY_WIDTH; k++) {
			baseground[i][k] = baseground[i - 1][k];
		}
	}
	return 1;
}