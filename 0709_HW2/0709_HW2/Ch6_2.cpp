#include <iostream>
#include <vector>
#include <stdio.h>
// '시계맞추기'문제 (pg.168)의 해답입니다. //
using namespace std;
const int INF = 9999, SWITCHES = 10, CLOCKS = 16; // INF 는 굉장히 큰 수, SWITCHES, CLOCKS는 스위치, 시계 개수
const char linked[SWITCHES][CLOCKS + 1] = {
		"xxx.............",
		"...x...x.x.x....",
		"....x.....x...xx",
		"x...xxx.........",
		"......xxx.x.x...",
		"x.x...........xx",
		"...x..........xx",
		"....xx.x......xx",
		".xxxxx..........",
		"...xxx...x...x.."
};
bool areAligned(const vector<int>& clocks) {
	for (int i = 0; i < CLOCKS; ++i) {
		if (clocks[i] != 12) return false;
	}
	return true;
}// 모두 12면 출력
void push(vector<int>& clocks, int swtch) {
	for (int clock = 0; clock < CLOCKS; ++clock) {
		if (linked[swtch][clock] == 'x') {
			clocks[clock] += 3;
			if (clocks[clock] == 15) clocks[clock] = 3;
		}
	}
}
int min(int a, int b) {
	return a > b ? b : a;
}
int solve(vector<int>& clocks, int swtch) {
	if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;
	
	int ret = INF;
	for (int cnt = 0; cnt < 4; cnt++) {
		ret = min(ret, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}
	return ret;

}
void main() {
	char str[50];
	vector <int> clocks;
	gets_s(str, 50);
	int num = 0, count = 0;
	for (int i = 0; str[i] != NULL; i++) {
		if (str[i] != ' ') {
			num = num * 10 + str[i] - '0';
		}
		else {
			clocks.push_back(num);
			cout << clocks.back() << endl;
			num = 0;
		}
		if (str[i+1]==NULL) {
			clocks.push_back(num);
			cout << clocks.back() << endl;
			break;
		}
	}
	int result = solve(clocks, 0);
	cout << result << endl;
}
