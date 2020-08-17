#include "init.h"
#include "GameBoard.h"
/* Function Declaration */

void initTitle();
GameBoard gameboard;

int main() {
	while (1) {
		initTitle();
		int menuSelect = drawmainmenu();
		if (menuSelect == 0) {//Game Start
			srand((size_t)time(NULL));
			system("cls");
			gameboard.createBoard();
			while (1) {
				gameboard.printBoard();
				int tempkey = keyControl();
				if (tempkey == SUBMIT) {
					gameboard.checkBoard(gameboard.cursorX, gameboard.cursorY);
					cout << gameboard.cursorX << gameboard.cursorY;
				}
				else if(tempkey == RIGHT){
					if (gameboard.cursorX <= 14) {
						++gameboard.cursorX;
					}
				}
				else if (tempkey == LEFT) {
					if (gameboard.cursorX >= 1) {
						--gameboard.cursorX;
					}
				}
				else if (tempkey == DOWN) {
					if (gameboard.cursorY <= 14) {
						++gameboard.cursorY;
					}
				}
				else if (tempkey == UP) {
					if (gameboard.cursorY >= 1) {
						--gameboard.cursorY;
					}
				}
				else if (tempkey == QUIT) {
					break;
				}
			}

		}
		else if (menuSelect == 1) { //Game Info
			system("cls");
			gotoxy(55, 15);
			cout << "Minesweeper Clone Made By Woo Hyeok Choi (@cw00h)"<<endl;
			gotoxy(55, 18);
			cout << "Press W, A, S, D to move" << endl;
			gotoxy(55, 20);
			cout << "Press Space bar to check the block" << endl;
			gotoxy(55, 22);
			cout << "Press F to flag the block" << endl;
			gotoxy(55, 24);
			cout << "Press R to put a question mark on the block" << endl;
			gotoxy(55, 26);
			cout << "Press Q to exit during the game" << endl;
			gotoxy(55, 32);
			cout << "Press Space bar to exit";
			while (1) {
				if (keyControl() == SUBMIT) {
					break;
				}
			}
		}
		else if (menuSelect == 2) {
			return 0; //Exit
		}
		system("cls");
	}
	return 0; 
}

void initTitle() {
	system(" mode  con lines=50   cols=160 ");
	textcolor(WHITE, LIGHTBLUE);
	drawtitle();
	textcolor(WHITE, BLACK);
}