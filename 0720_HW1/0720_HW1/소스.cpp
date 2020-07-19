#include <iostream>
#include <algorithm>
using namespace std;

int n;
int triangle[100][100];
int cache[100][100];
int countCache[100][100];

void init() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cache[i][j] = -1;
			triangle[i][j] = 0;
			countCache[i][j] = -1;
		}
	}
}

int path(int y, int x) {
	if (y == n - 1) return triangle[y][x];
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	return ret = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}

int count(int y, int x) {
	if (y == n - 1) return 1;
	int& ret = countCache[y][x];
	if (ret != -1) return ret;
	ret = 0;
	if (path(y + 1, x + 1) >= path(y + 1, x)) ret += count(y + 1, x + 1);
	if (path(y + 1, x + 1) <= path(y + 1, x)) ret += count(y + 1, x);
	return ret;
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
		cout << count(0, 0) << endl;
	}

}