//tetrisLevel.c
#include "myTetris.h"
#include <windows.h>
#include <time.h>
int level = 1;
int delayFuntion_T = 1000;
extern int score;


void tetrisLevel() {
	if (score > 250 * level) {
		if (level < 5) { //max ==5�� ���� �س��ұ� ������
			level++;
			delayFuntion_T -= 200;
		}


		/*else if (level == 5) //MAX LEVEL�� �Ǿ��� �����ʹ� ��� 30�ʿ� �ѹ��� �ö��
		{
			double newtime;
			static double oldtime = 0; //�Լ�ȣ��� �����ϰ� ������
			newtime = GetTickCount();
			if ((newtime - oldtime) > 30000) { //30�ʿ� �ѹ���
				oldtime = newtime;
				int x;
				srand(time(NULL));
				x = rand() % MY_WIDTH + 2;

				for (int i = MY_HIGH-2; i < 1; i--) {
					for (int k = 1; k < MY_WIDTH; k++) {
						baseground[i-1][k] = baseground[i][k];
					}
				}
				for (int i = 1; i < MY_WIDTH - 1; i++) {
					if (i == x)
						baseground[MY_HIGH - 2][x] = MY_SPACE;
					else
						baseground[MY_HIGH - 2][x] = MY_BASE_BLOCK;
				}
			}
		}*/
	}
}