#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Board
{
private:
	vector<vector<int>> mineBoard;
	int colNum, mineNum;
	bool fin, lose;
	int leftNum, mineLeft;
public:
	Board() {
		colNum = 16;
		mineNum = 40;
		fin = false;
		leftNum = 0;
		mineLeft = 40;
		lose = false;
	}
	Board(int a, int b) {
		colNum = a;
		mineNum = b;
		leftNum = 0;
		fin = false;
		mineLeft = b;
		lose = false;
	}
	void setColNum(int a);
	void setMineNum(int a);
	bool printFin();
	int printColNum();
	vector<vector<int>>& printMineBoard();
	int printLeftNum();
	int printMineNum();
	int printMineLeft();
	bool printLose();
	void setLose(bool a);
	void setFin(bool a);
	void initialize();
	bool showPoint(int x,int y);
	void add1Point(int x, int y);
	void add5000Point(int x, int y);
};

