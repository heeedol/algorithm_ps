#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> h;
int solve(int left, int right) {
	//기저 사례: 판자가 하나 있는 경우
	if (left == right) return h[left];
	//[left,mid] [mid+1,right] 두 구간으로 문제 분할
	int mid = (left + right) / 2;
	int ret = max(solve(left, mid), solve(mid + 1, right));
	//두부분 모두에 걸치는 사각형 중 큰 것 찾기

	//너비가 2인 경우
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	ret = max(ret, height * 2);

	while (left < lo || hi < right) {
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;

}
void main() {
	int tcase;
	int row;
	int n;
	cin >> tcase;
	for (int i = 0; i < tcase; i++) {
		cin >> row;
		for (int j = 0; j < row; j++) {
			cin >> n;
			h.push_back(n);
		}
		cout << solve(0, row - 1) << endl;
		h.clear();
	}

}