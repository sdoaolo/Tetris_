//delayFuntion.c
#include<windows.h>
#include<stdio.h>
#include "myTetris.h"

int delayFunction(unsigned int t) {
	double newtime;
	static double oldtime = 0;//�Լ�ȣ��� �����ϰ� ������
	newtime = GetTickCount();
	if ((newtime - oldtime) > t) {
		oldtime = newtime;
		return 1;
	}
	else return 0;
}