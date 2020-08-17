#include "GameBoard.h"

void GameBoard::createBoard() {
	cursorX, cursorY = 0;
	memset(board, 0, sizeof(board));
	memset(Checkedboard, 0, sizeof(Checkedboard));//Initialization
	for (int i = 0; i < 40; ++i) {
		int randomnumX = rand() % 16;
		int randomnumY = rand() % 16;
		if (board[randomnumX][randomnumY] >= 100) {
			--i;
			continue;
		}
		board[randomnumX][randomnumY] += 100;
		if (randomnumX != 0 && randomnumY != 0)
			board[randomnumX - 1][randomnumY - 1] += 1;
		if (randomnumY != 0)
			board[randomnumX][randomnumY - 1] += 1;
		if (randomnumX != 15 && randomnumY != 0)
			board[randomnumX + 1][randomnumY - 1] += 1;
		if (randomnumX != 0)
			board[randomnumX - 1][randomnumY] += 1;
		if (randomnumX != 15)
			board[randomnumX + 1][randomnumY] += 1;
		if (randomnumX != 0 && randomnumY != 15)
			board[randomnumX - 1][randomnumY + 1] += 1;
		if (randomnumY != 15)
			board[randomnumX][randomnumY + 1] += 1;
		if (randomnumX != 15 && randomnumY != 15)
			board[randomnumX + 1][randomnumY + 1] += 1;
	}
}

void GameBoard::printBoard() const {
	for (int i = 0; i < 16; ++i) {
		for(int j = 0; j < 15; ++j) {
			gotoxy(3 * j + 60, 2 * i + 5);
			if (board[j][i] >= 100) {
				if (Checkedboard[j][i] == 0 && (cursorY == i && cursorX == j)) {
					textcolor(BLUE, BLUE);
				}
				else if (Checkedboard[j][i] == 0){
					textcolor(WHITE, WHITE);
				}
				else if (Checkedboard[j][i] == 1) { //Game Over
					textcolor(WHITE, RED);
				}
				else {//Game Over
					textcolor(WHITE, RED);
				}
				cout << "*";
				textcolor(WHITE, BLACK);
			}
			else {
				if (Checkedboard[j][i] == 0 && (cursorY == i && cursorX == j)) {
					textcolor(BLUE, BLUE);
				}
				else if(Checkedboard[j][i] == 0) {
					textcolor(WHITE, WHITE);
				}
				else if (Checkedboard[j][i] == 1 && (cursorY == i && cursorX == j)) {
					textcolor(WHITE, BLUE);
				}
				else {
					textcolor(WHITE, BLACK);
				}
				cout << board[j][i];
				textcolor(WHITE, BLACK);
			}
		}
		if (board[15][i] >= 100) {
			cout << "  ";
			if (Checkedboard[15][i] == 0 && (cursorY == i && cursorX == 15)) {
				textcolor(BLUE, BLUE);
			}
			else if (Checkedboard[15][i] == 0) {
				textcolor(WHITE, WHITE);
			}
			else if (Checkedboard[15][i] == 1) { //Game Over
				textcolor(WHITE, RED);
			}
			else {//Game Over
				textcolor(WHITE, RED);
			}
			cout << "*" << endl;
			textcolor(WHITE, BLACK);
		}
		else {
			cout << "  ";
			if (Checkedboard[15][i] == 0 && (cursorY == i && cursorX == 15)) {
				textcolor(BLUE, BLUE);
			}
			else if (Checkedboard[15][i] == 0) {
				textcolor(WHITE, WHITE);
			}
			else if (Checkedboard[15][i] == 1 && (cursorY == i && cursorX == 15)) {
				textcolor(WHITE, BLUE);
			}
			else {
				textcolor(WHITE, BLACK);
			}
			cout << board[15][i] << endl;
			textcolor(WHITE, BLACK);
		}
	}
}

void GameBoard::checkBoard(int _X, int _Y) {
	if (Checkedboard[_X][_Y] == 0) {
		Checkedboard[_X][_Y] = 1;
		if (board[_X][_Y] == 0) {
			if (_X == 0 && _Y == 0) {
				checkBoard(_X + 1, _Y + 1);
				checkBoard(_X + 1, _Y);
				checkBoard(_X, _Y + 1);
			}
			else if (_X == 0 && (_Y > 0 && _Y < 15)) {
				checkBoard(_X, _Y - 1);
				checkBoard(_X + 1, _Y - 1);
				checkBoard(_X + 1, _Y);
				checkBoard(_X + 1, _Y + 1);
				checkBoard(_X, _Y + 1);
			}
			else if (_X == 0 && _Y == 15) {
				checkBoard(_X + 1, _Y - 1);
				checkBoard(_X + 1, _Y);
				checkBoard(_X, _Y - 1);
			}
			else if ((_X > 0 && _X < 15) && _Y == 0) {
				checkBoard(_X - 1, _Y);
				checkBoard(_X + 1, _Y);
				checkBoard(_X - 1, _Y + 1);
				checkBoard(_X, _Y + 1);
				checkBoard(_X + 1, _Y + 1);
			}
			else if ((_X > 0 && _X < 15) && _Y == 15) {
				checkBoard(_X - 1, _Y);
				checkBoard(_X + 1, _Y);
				checkBoard(_X - 1, _Y - 1);
				checkBoard(_X, _Y - 1);
				checkBoard(_X + 1, _Y - 1);
			}
			else if (_X == 15 && _Y == 0) {
				checkBoard(_X - 1, _Y);
				checkBoard(_X - 1, _Y + 1);
				checkBoard(_X, _Y + 1);
			}
			else if (_X == 15 && (_Y > 0 && _Y < 15)) {
				checkBoard(_X, _Y + 1);
				checkBoard(_X, _Y - 1);
				checkBoard(_X-1, _Y + 1);
				checkBoard(_X-1, _Y - 1);
				checkBoard(_X-1, _Y);
			}
			else if (_X == 15 && _Y == 15) {
				checkBoard(_X, _Y - 1);
				checkBoard(_X - 1, _Y - 1);
				checkBoard(_X - 1, _Y);
			}
			else {
				checkBoard(_X - 1, _Y - 1);
				checkBoard(_X, _Y - 1);
				checkBoard(_X + 1, _Y - 1);
				checkBoard(_X - 1, _Y);
				checkBoard(_X + 1, _Y);
				checkBoard(_X + 1, _Y + 1);
				checkBoard(_X, _Y + 1);
				checkBoard(_X - 1, _Y + 1);
			}
		}
	}
}