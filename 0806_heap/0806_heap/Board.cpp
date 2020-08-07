#include "Board.h"
#include <random> 
void Board::setColNum(int a) {
	colNum = a;
}
void Board::setMineNum(int a) {
	mineNum = a;
}
void Board::add1Point(int x, int y) {
	mineBoard[x + 1][y - 1] += 1;
	mineBoard[x + 1][y] += 1;
	mineBoard[x + 1][y + 1] += 1;
	mineBoard[x][y - 1] += 1;
	mineBoard[x][y + 1] += 1;
	mineBoard[x - 1][y - 1] += 1;
	mineBoard[x - 1][y] += 1;
	mineBoard[x - 1][y + 1] += 1;
}
void Board::initialize() {
	vector <int> mineTemp;
	mineTemp.assign(colNum+2, 0);
	for (int i = 0; i < colNum+2; i++) {
		mineBoard.push_back(mineTemp);
	}
	random_device rd;
	uniform_int_distribution<int> dist(1, colNum);
	int x, y, i;
	i = 0;
	while (i < mineNum) {
		x = dist(rd);
		y = dist(rd);
		if (mineBoard[x][y] >= 1000) {
			continue;
		}
		else {
			mineBoard[x][y] += 1000;
			add1Point(x, y);
			i++;
		}
	}
	/*for (int i = 0; i < colNum + 2; i++) {
		for (int j = 0; j < colNum + 2; j++) {
			cout << mineBoard[i][j] << " ";
		}
		cout << endl;
	}*/
}
void Board::add5000Point(int x, int y) {
	if (mineBoard[x + 1][y + 1] >= 0 && mineBoard[x + 1][y + 1] < 10000) {
		if (mineBoard[x + 1][y + 1] < 5000) {
			mineBoard[x + 1][y + 1] += 5000;
			mineLeft -= 1;
		}
		else {
			mineBoard[x + 1][y + 1] -= 5000;
			mineLeft += 1;
		}
	}
}
bool Board::showPoint(int x, int y) { // only for Z button!
	if (x < 0 || x >= colNum || y < 0 || y>=colNum ||mineBoard[x+1][y+1]<0 || mineBoard[x + 1][y + 1] == 10000) {
		//nothing happen!
	}
	else if (mineBoard[x + 1][y + 1] >= 5000 && mineBoard[x + 1][y + 1] < 10000) {
		mineBoard[x + 1][y + 1] -= 5000;
	}

	if (x < 0 || x >= colNum || y < 0 || y >= colNum || mineBoard[x + 1][y + 1] < 0 || mineBoard[x + 1][y + 1] == 10000) {
		//nothing happen!
	}
	else if (mineBoard[x + 1][y + 1] == 0) {
		mineBoard[x + 1][y + 1] += 10000;
		leftNum++;
		showPoint(x - 1, y - 1);
		showPoint(x - 1, y);
		showPoint(x - 1, y + 1);
		showPoint(x, y - 1);
		showPoint(x, y + 1);
		showPoint(x + 1, y - 1);
		showPoint(x + 1, y);
		showPoint(x + 1, y + 1);
	}
	else if (mineBoard[x + 1][y + 1] >= 1000) {
		fin = true;
		return fin;
	}
	else {
		mineBoard[x + 1][y + 1] *= -1;
		leftNum++;
	}
	return false;
}
bool Board::printFin() {
	return fin;
}
int Board::printColNum() {
	return colNum;
}
vector<vector<int>>& Board::printMineBoard() {
	return mineBoard;
}
int Board::printLeftNum() {
	return leftNum;
}
int Board::printMineNum() {
	return mineNum;
}
int Board::printMineLeft() {
	return mineLeft;
}

bool Board::printLose() {
	return lose;
}
void Board::setFin(bool a) {
	fin = a;
}
void Board::setLose(bool a) {
	lose = a;
}