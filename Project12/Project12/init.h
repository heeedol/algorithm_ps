#pragma once
/*Color code definition*/
#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 
/*Keyboard code definition*/
#define UP 0 //W
#define DOWN 1 //S
#define LEFT 2 //A
#define RIGHT 3 //D
#define SUBMIT 4 //Space bar
#define FLAG 5 //F
#define QUESTION 6 //R
#define QUIT 7 //Q

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

void textcolor(int foreground, int background);
void drawtitle();

//Function to move cursor
void gotoxy(int x, int y);

int keyControl();
int drawmainmenu();