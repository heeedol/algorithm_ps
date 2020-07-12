#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> h;
int solve(int left, int right) {
	//���� ���: ���ڰ� �ϳ� �ִ� ���
	if (left == right) return h[left];
	//[left,mid] [mid+1,right] �� �������� ���� ����
	int mid = (left + right) / 2;
	int ret = max(solve(left, mid), solve(mid + 1, right));
	//�κκ� ��ο� ��ġ�� �簢�� �� ū �� ã��

	//�ʺ� 2�� ���
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