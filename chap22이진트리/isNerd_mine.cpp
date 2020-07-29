#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

map<int, int> participants;


int qualifiedNum(int a, int b) {
	participants.insert(make_pair(a, b));
	auto it = participants.begin();
	auto newIt = participants.find(a);
	if (it == newIt) {
		if (++it->second < b)
			participants.erase(newIt);
	}
	else {
		while (it != newIt) {
			if (it->second > b) {
				it++;
				continue;
			}
			it = participants.erase(it);
		}
	}
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
			answer += qualifiedNum(psNum,ramyeonNum);
		}
		cout << answer << endl;
		participants.clear();
	}
	return 0;
}