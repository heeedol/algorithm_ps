#pragma once
/*색깔 정의*/
#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 
/*키보드 정의*/
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 //스페이스바

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

void textcolor(int foreground, int background) {
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void drawtitle() {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "            ********   ********  ****    **** ************     ************ ***      *** ************ ************ ***********  ************ **********         " << endl;
	cout << "           **********  ********  *****   **** ************     ************ ***  **  *** ************ ************ ************ ************ ***********        " << endl;
	cout << "          ************   ****    ******  **** ****             ****         ***  **  *** ****         ****         ***      *** ****         ****    ***        " << endl;
	cout << "          ***  **  ***   ****    ************ ************     ************ ***  **  *** ************ ************ ************ ************ *********          " << endl;
	cout << "          ***  **  ***   ****    ************ ************     ************ ***  **  *** ************ ************ ***********  ************ *********          " << endl;
	cout << "          ***  **  ***   ****    ****  ****** ****                    ***** ************ ****         ****         ****         ****         ****  ****         " << endl;
	cout << "          ***  **  *** ********  ****   ***** ************     ************  **********  ************ ************ ****         ************ ****   ****        " << endl;
	cout << "          ***      *** ********  ****    **** ************     ************   ********   ************ ************ ****         ************ ****    ****       " << endl;
}

//커서 위치 이동 함수
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int keyControl() {
	char temp = _getch();

	if (temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == ' ') {
		return SUBMIT;
	}
}

int drawmainmenu() {
	int x = 80;
	int y = 30;
	gotoxy(x - 2, y);
	cout << "> 게 임 시 작" << endl;
	gotoxy(x, y + 1);
	cout << "게 임 정 보" << endl;
	gotoxy(x, y + 2);
	cout << "   종 료   " << endl;
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 30) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < 32) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 30;
		}
		}
	}
}