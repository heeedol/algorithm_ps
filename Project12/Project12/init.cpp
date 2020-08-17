#include "init.h"

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
	else if (temp == 'f' || temp == 'F') {
		return FLAG;
	}
	else if (temp == 'r' || temp == 'R') {
		return QUESTION;
	}
	else if (temp == 'q' || temp == 'Q') {
		return QUIT;
	}
}

int drawmainmenu() {
	int x = 75;
	int y = 30;
	gotoxy(x - 2, y);
	cout << "> G a m e  S t a r t" << endl;
	gotoxy(x, y + 1);
	cout << " G a m e  I n f o " << endl;
	gotoxy(x, y + 2);
	cout << "      E x i t     " << endl;
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