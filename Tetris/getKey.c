#include<conio.h>
unsigned char getKey() {
	unsigned char key = NULL;

	if (_kbhit()) { //kbhit = 0 키입력X = 1 키입력 ㅇ
		key = _getch();
		if (key == 224) key = _getch();
	}
	return key;
}