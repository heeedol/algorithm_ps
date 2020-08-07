#include <iostream>
#include <vector>
#include <random> 
#include "gameplayBoard.h"
//Áö·ÚÃ£±â
using namespace std;
void main() {
	Board a(5,2);
	a.initialize();
	//a.showPoint(0, 0);
	printBoard(a);
	gameBoard(a);
}