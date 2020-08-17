#pragma once
#include "init.h"
#include <ctime>
#include <cstdlib>
#include <string.h>

class GameBoard {
public:
	GameBoard() {}
	void createBoard();
	void printBoard() const;
	void checkBoard(int _X, int _Y);
	int board[16][16] = { 0 };
	bool Checkedboard[16][16] = { 0 };
	int cursorX = 0;
	int cursorY = 0;
	bool gameover = 0;
};