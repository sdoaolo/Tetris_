/*#include"myTetris.h"
#include<stdio.h>
#include<windows.h>

void previousShow() {

	gotoxy(30, 2);
	printf(" < N E X T >");
	for (int i = 0; i < 6; i++) {
		gotoxy(30, 3+i);
		for (int k = 0; k < 6; k++) {
			if (i == 0 || i == 5 || k == 0 || k == 5)
				printf("бр");
			else printf("  ");
		}printf("\n");
	}
}*/