//tetrisLevel.c
#include "myTetris.h"
#include <windows.h>
#include <time.h>
int level = 1;
int delayFuntion_T = 1000;
extern int score;


void tetrisLevel() {
	if (score > 250 * level) {
		if (level < 5) { //max ==5로 설정 해놓았기 때문에
			level++;
			delayFuntion_T -= 200;
		}


		/*else if (level == 5) //MAX LEVEL이 되었을 때부터는 블록 30초에 한번씩 올라옴
		{
			double newtime;
			static double oldtime = 0; //함수호출과 무관하게 유지함
			newtime = GetTickCount();
			if ((newtime - oldtime) > 30000) { //30초에 한번씩
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