#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

void josephus(int personNum,int jumpNum) {
	list<int> people;
	for (int i = 1; i <= personNum; i++) people.push_back(i);
	auto it = people.begin();
	while (--personNum) {
		it = people.erase(it);
		if (it == people.end()) it = people.begin();
		if (personNum == 2) break;
		for (int i = 0; i < jumpNum - 1;i++) {
			it++;
			if (it == people.end()) it = people.begin();
		}
	}
	cout << people.front() << " " << people.back() << endl;
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase-- > 0) {
		int personNum;
		int jumpNum;
		cin >> personNum ;
		cin >> jumpNum;
		josephus(personNum, jumpNum);
	}
	return 0;
}