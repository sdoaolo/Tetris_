#include<conio.h>
unsigned char getKey() {
	unsigned char key = NULL;

	if (_kbhit()) { //kbhit = 0 Ű�Է�X = 1 Ű�Է� ��
		key = _getch();
		if (key == 224) key = _getch();
	}
	return key;
}