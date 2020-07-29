#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

map<int, int> participants;

bool isDominated(int x, int y) {
	auto it = participants.lower_bound(x);
	if (it == participants.end()) return false;
	return y < it->second;
}

void removeDominated(int x, int y) {
	auto it = participants.lower_bound(x);
	if (it == participants.begin()) return;
	--it;
	while (true) {
		if (it->second > y) break;
		if (it == participants.begin()) {
			participants.erase(it);
			break;
		}
		else {
			auto jt = it;
			--jt;
			participants.erase(it);
			it = jt;
		}
	}
}

int registered(int x, int y) {
	if (isDominated(x, y)) return participants.size();
	removeDominated(x, y);
	participants[x] = y;
	return participants.size();
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase-- > 0) {
		int participateNum;
		int answer = 0;
		cin >> participateNum;
		for (int i = 0; i < participateNum; i++) {
			int psNum, ramyeonNum;
			cin >> psNum >> ramyeonNum;
			registered(psNum, ramyeonNum);
		}
		cout << answer << endl;
		participants.clear();
	}
	return 0;
}