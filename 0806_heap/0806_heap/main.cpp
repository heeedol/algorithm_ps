#include <iostream>
#include <vector>
#include <random> 
#include "gameplayBoard.h"
//����ã��
using namespace std;
void main() {
	Board a(16,40);
	a.initialize();
	//a.showPoint(0, 0);
	printBoard(a);
	gameBoard(a);
}