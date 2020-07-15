#include <iostream>
#include <chrono>
//Ch8 (pg.215)의 예제: 외발뛰기 의 답입니다.
using namespace std;
using namespace chrono;
int n;
int** board;
int** cache;
int count1 = 0, count2 = 0;
bool jump(int y, int x) {
	if (y >= n || x >= n) {
		return false;
	}
	if (y == n - 1 && x == n - 1) {
		return true;
	}
	count1++;
	int jumpSize = board[y][x];
	return jump(y + jumpSize, x) || jump(y, x + jumpSize);
}

bool jump2(int y, int x) {
	if (y >= n || x >= n) {
		return false;
	}
	if (y == n - 1 && x == n - 1) {
		return true;
	}
	int& ret = cache[y][x];
	if (ret != -1) {
		return cache[y][x];
	}
	count2++;
	int jumpSize = board[y][x];
	return ret = jump2(y + jumpSize, x) || jump2(y, x + jumpSize);
}

void main() {
	cin >> n;
	board = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		*(board + i) = (int*)malloc(sizeof(int*) * n);
	}
	cache = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		*(cache + i) = (int*)malloc(sizeof(int*) * n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = 1;
		}
	}
	board[n-1][n-2] = 2;
	board[n-2][n-1] = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cache[i][j] = -1;
		}
	}
	
	//그냥 재귀함수의 방법
	system_clock::time_point start = system_clock::now();
	cout << "We" << (jump(0, 0) ? "can" : "can't") << "go to the end" << endl;
	system_clock::time_point end = system_clock::now();
	microseconds microSec = duration_cast<microseconds> (end - start);
	cout << microSec.count() << endl;
	cout << "Number of stage : " << count1 << endl;
	
	//메모이제이션의 적용
	system_clock::time_point start2 = system_clock::now();
	cout << "We" << (jump2(0, 0) ? "can" : "can't") << "go to the end" << endl;
	system_clock::time_point end2 = system_clock::now();
	microseconds microSec2 = duration_cast<microseconds> (end2 - start2);
	cout << microSec2.count() << endl;
	cout << "Number of stage : " << count2 << endl;



}