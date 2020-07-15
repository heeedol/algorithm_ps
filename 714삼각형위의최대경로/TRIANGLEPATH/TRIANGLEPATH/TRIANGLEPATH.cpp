#include <iostream>
#include <algorithm>
using namespace std;

int n;
int triangle[100][100];
int cache[100][100];

void init(){
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cache[i][j] = -1;
			triangle[i][j] = 0;
		}
	}
}
int path(int y, int x) {
	//기저 사례
	if (y == n - 1) return triangle[y][x];
	//메모이제이션
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	return ret=max(path(y + 1, x), path(y + 1, x + 1))+triangle[y][x];
}

void main() {
	int tcase;
	int contents;
	cin >> tcase;
	for (int i = 0; i < tcase; i++) {
		init();
		cin >> n;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < j + 1; k++) {
				cin >> contents;
				triangle[j][k] = contents;
			}
		}
		cout << path(0, 0) << endl;
	}
	
}