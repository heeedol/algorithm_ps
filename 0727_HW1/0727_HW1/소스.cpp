#include <iostream>
#include <stack>
#include <vector>
// Ch.19 pg.628 예제: 스택을 이용한 울타리 자르기 문제의 해법의 답안 입니다.
using namespace std;
vector<int> h;
int max(int a, int b) {
	return a >= b ? a : b;
}

int solveStack() {
	stack<int> remaining;
	h.push_back(0);
	int ret = 0;
	for (int i = 0; i < h.size(); ++i) {
		while (!remaining.empty() && h[remaining.top()] >= h[i]) {
			int j = remaining.top();
			remaining.pop();
			int width = -1;
			if (remaining.empty())
				width = i;
			else
				width = (i - remaining.top() - 1);
			ret = max(ret, h[j] * width);
		}
		remaining.push(i);
	}
	return ret;
 }

void main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		h.push_back(tmp);
	}
	cout << solveStack() << endl;
}