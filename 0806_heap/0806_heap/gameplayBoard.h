#pragma once
#include <iostream>
#include "Board.h"
#include "gameplayUtility.h"

void printBoard(Board& a) {
	int colNum = a.printColNum();
	vector<vector<int>> mineBoard = a.printMineBoard();
	gotoxy(30, 30);
	if (!a.printFin()) {
		printf("Mine Left : %d", a.printMineLeft());
		gotoxy(46, 30);
		printf("Non-Mine Left : %d", a.printLeftNum());
		gotoxy(68, 30);
		printf("Goal : %d", (a.printColNum() * a.printColNum()) - a.printMineNum());
	}
	else if(a.printLose()) {
		printf("----------------------------------------------------------");
		gotoxy(30, 30);
		printf("you win!");
	}
	else {
		printf("----------------------------------------------------------");
		gotoxy(30, 30);
		printf("you lose!");
	}
	for (int i = 1; i < colNum + 1; i++) {
		for (int j = 1; j < colNum + 1; j++) {
			gotoxy((2 * i) + 30, (2 * j) + 30);
			if (mineBoard[i][j] >= 10000) {
				printf("0 ");
				//cout << "0 ";
			}
			else if (mineBoard[i][j] >= 5000) {
				printf("M ");
			}
			else if (mineBoard[i][j] < 1000 && mineBoard[i][j] >= 0) {
				printf("@ ");
				//cout << mineBoard[i][j] << " ";
				//cout << "@ ";
			}
			else if (mineBoard[i][j] >= 1000) {
				//a.printFin() ? printf("* ") : printf("@ ");
				printf("* ");
				//cout << "* ";
			}
			else {
				printf("%d ", mineBoard[i][j] * (-1));
				//cout << mineBoard[i][j] * (-1) << " ";
			}
		}
		cout << endl;
	}
}

int gameBoard(Board& a) {
	int x_default = 32, y_default = 32;
	int x = x_default;
	int y = y_default;
	int x_cursor = 0, y_cursor = 0;
	while (1) {
		int n = keyControl();
		switch (n) {
		case 0: {
			if (y > y_default) {
				y -= 2;
				gotoxy(x, y);
				y_cursor--;
			}
			break;
		}
		case 1: {
			if (y < 2 * ((a.printColNum()) -2) + y_default + 2) {
				y += 2;
				gotoxy(x, y);
				y_cursor++;
			}
			break;
		}
		case 2: {
			if (x > x_default) {
				x -= 2;
				gotoxy(x, y);
				x_cursor--;
			}
			break;
		}
		case 3: {
			if (x < 2 * ((a.printColNum()) - 2) + x_default + 2) {
				x += 2;
				gotoxy(x, y);
				x_cursor++;
				//cout << x_cursor;
			}
			break;
		}
		case 4: {
			bool temp = a.showPoint(x_cursor, y_cursor);
			printBoard(a);
			if (temp) {
				return 0;
			}
			else if (a.printLeftNum() == (a.printColNum() * a.printColNum()) - a.printMineNum()) {
				a.setFin(true);
				a.setLose(true);
				printBoard(a);
				int y_reset = 2 * (a.printColNum() - 2) + y_default + 4;
				gotoxy(30, y_reset);
				printf("wanna play again?");
				gotoxy(31, y_reset + 1);
				printf("Yes");
				gotoxy(37, y_reset + 1);
				printf("Mainmenu");
				gotoxy(47, y_reset + 1);
				printf("Quit");
				return 0;
			}
			break;
		}
		case 5: { // for X button!
			a.add5000Point(x_cursor, y_cursor);
			printBoard(a);
			break;
		}
		}
	}
}

