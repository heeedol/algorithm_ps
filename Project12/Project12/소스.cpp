#include "init.h"

/* �Լ� ���� */

void initMainmenu();

int main() {
	initMainmenu();
	return 0; 
}

void initMainmenu() {
	system(" mode  con lines=50   cols=160 ");
	textcolor(WHITE, LIGHTBLUE);
	drawtitle();
	textcolor(WHITE, BLACK);
	drawmainmenu();
}