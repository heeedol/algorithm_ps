#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int keyControl() {
	int temp = _getch();
	if (temp == 122 || temp == 90) { // Z
		return 4;
	}
	else if (temp == 120 || temp == 88) { // X
		return 5;
	}
	else if (temp == 67 || temp == 99) { // C
		return 6;
	}
	else if (temp == 224) {
		switch (_getch()) {
		case 72: //UP
			return 0;
			break;
		case 75: //LEFT
			return 2;
			break;
		case 77: //RIGHT
			return 3;
			break;
		case 80: //DOWN
			return 1;
			break;
		}
	}
}