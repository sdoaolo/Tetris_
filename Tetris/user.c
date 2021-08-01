//user.c
#include<Windows.h>
char name[20];

void game_start() {

	char choice;

	for (int i = 0; i < 3; i++)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		gotoxy(20, 8);
		printf("■■■■■■");
		for (int i = 1; i <= 4; i++)
		{
			gotoxy(20, 8 + i);
			printf("     ■     ");
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		for (int i = 1; i <= 5; i++)
		{
			gotoxy(34, 7 + i);
			if (i % 2 == 1)
				printf("■■■■■");
			if (i % 2 == 0)
			{
				printf("■");
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		gotoxy(45, 8);
		printf("■■■■■■");
		for (int i = 1; i <= 4; i++)
		{
			gotoxy(45, 8 + i);
			printf("     ■     ");
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		for (int i = 1; i <= 5; i++)
		{
			gotoxy(58, 7 + i);
			if (i == 1 || i == 3)
				printf("■■■■■");
			if (i == 2)
				printf("■       ■");
			if (i == 4)
				printf("■      ■");
			if (i == 5)
				printf("■        ■");
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //9
		for (int i = 1; i <= 5; i++)
		{
			gotoxy(71, 7 + i);
			if (i == 1 || i == 5)
				printf("■■■■■■");
			else
				printf("     ■     ");
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //12
		for (int i = 1; i <= 5; i++)
		{
			gotoxy(85, 7 + i);
			if (i == 1)
				printf(" ■■■■■");
			else if (i == 3)
				printf(" ■■■■■");
			else if (i == 2)
				printf("■");
			else if (i == 5)
				printf(" ■■■■■");
			else
				printf("          ■");
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		gotoxy(20, 5);
		printf("< 제작 : 정보통신학부_18018001_강지은 >                                                                 ");

		Sleep(250);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 135); //112,128,135
		gotoxy(50, 19);
		printf("                ");
		gotoxy(50, 20);
		printf(" ENTER TO START ");
		gotoxy(50, 21);
		printf("                ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		Sleep(250);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	scanf("%c", &choice);
	system("cls");
	setConfig();
	user(name);

}