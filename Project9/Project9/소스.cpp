#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int input_n, input_k;
queue<int> survivors;

void josephus(int n, int k) {
	for (int i = 1; i < n+1; ++i) {
		survivors.push(i);
	}
	while(n>2) {
		survivors.pop();
		--n;
		for (int j = 0; j < k - 1; ++j) {
			int tmp = survivors.front();
			survivors.pop();
			survivors.push(tmp);
		}
	}
	cout << survivors.front() << " " << survivors.back() << endl;
	while (!(survivors.empty())) { //ÃÊ±âÈ­
		survivors.pop();
	}
}

int main() {
	int testcase;
	cin >> testcase;
	for (int tc = 0; tc < testcase; ++tc) {
		cin >> input_n >> input_k;
		josephus(input_n, input_k);
	}
}