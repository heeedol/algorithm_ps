#pragma once
#include <iostream>
#include <time.h>
#include "Board.h"
#include "gameplayUtility.h"

int x_default = 4, y_default = 4;

void printBoard(Board& a) {
	int colNum = a.printColNum();
	vector<vector<int>> mineBoard = a.printMineBoard();
	gotoxy(x_default, y_default-2);
	printf("Mine Left : %d", a.printMineLeft());
	gotoxy(x_default+16, y_default-2);
	printf("Non-Mine Left : %d", a.printLeftNum());
	gotoxy(x_default+38, y_default-2);
	printf("Goal : %d", (a.printColNum() * a.printColNum()) - a.printMineNum());
	
	
	for (int i = 1; i < colNum + 1; i++) {
		for (int j = 1; j < colNum + 1; j++) {
			gotoxy((2 * i) + x_default - 2, (2 * j) + y_default - 2);
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
				a.printFin() ? printf("* ") : printf("@ ");
				//printf("* ");
				//cout << "* ";
			}
			else {
				printf("%d ", mineBoard[i][j] * (-1));
				//cout << mineBoard[i][j] * (-1) << " ";
			}
		}
		cout << endl;
	}
	gotoxy(0,0);
}

bool resetGame(Board& a, int time) {
	gotoxy(x_default, y_default - 2);
	if (a.printLose()) {
	printf("                                                                ");
	gotoxy(x_default, y_default - 2);
	printf("you win!");
	gotoxy(x_default + 12, y_default - 2);
	printf("It have been ");
	time / 60 == 0 ? printf("%d seconds",time % 60): printf("%d minutes and %d seconds", time / 60, time % 60);
	}
	else {
	printf("                                                                ");
	gotoxy(x_default, y_default - 2);
	printf("you lose!");
	gotoxy(x_default + 12, y_default - 2);
	printf("It have played ");
	time / 60 == 0 ? printf("%d seconds", time % 60) : printf("%d minutes and %d seconds", time / 60, time % 60);
	}
	int y_reset = 2 * (a.printColNum() - 2) + y_default + 4;
	gotoxy(x_default, y_reset);
	printf("wanna play again?");
	gotoxy(x_default + 1, y_reset + 1);
	printf("Yes");
	gotoxy(x_default + 7, y_reset + 1);
	printf("Mainmenu");
	gotoxy(x_default + 17, y_reset + 1);
	printf("Quit");
	return 0;
}

int gameBoard(Board& a) {
	int x = x_default;
	int y = y_default;
	int x_cursor = 0, y_cursor = 0;
	printBoard(a);
	time_t start, end;
	start = time(NULL);
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
			if (temp) { // clicked the mine
				a.setFin(true);
				printBoard(a);
				end = time(NULL);
				if (resetGame(a, (int)end - start )) {
					return 1; //reset
				}
				return 0; // Quit
			}
			else if (a.printLeftNum() == (a.printColNum() * a.printColNum()) - a.printMineNum()) {
				a.setFin(true); // win the game
				a.setLose(true);
				printBoard(a);
				end = time(NULL);
				if (resetGame(a , (int)end - start)) {
					return 1; //reset
				}
				return 0; // Quit
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

