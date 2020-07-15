//�ִ� ���� �κ� ���� (8�� 4��)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

//ù ��° �ڵ�
int lis(const vector<int>& A) {
	//���� ��� : A�� �� ��� ���� ��
	if (A.empty()) return 0;
	int ret = 0;
	for (int i = 0; i < A.size(); ++i) {
		vector<int> B;
		for (int j = i + 1; j < A.size(); ++j)
			if (A[i] < A[j])
				B.push_back(A[j]);
		ret = max(ret, 1 + lis(B));
	}
	return ret;
}

//�� ��° �ڵ�
int n1;
int cache1[500], S1[500];
//S[start]���� �����ϴ� ���� �κ� ���� �� �ִ� ���̸� ��ȯ�Ѵ�.
int lis2(int start) {
	int& ret = cache1[start];
	if (ret != -1) return ret;
	//�׻� S[start]�� �ֱ� ������ ���̴� ���� 1
	ret = 1;
	for (int next = start + 1; next < n1; ++next)
		if (S1[start] < S1[next])
			ret = max(ret, lis2(next) + 1);
	return ret;
}

//�� ��° �ڵ�
int n2;
int cache2[501], S2[500];

int lis3(int start) {
	int& ret = cache2[start + 1];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < n2; ++next)
		if (start == -1 || S2[start] < S2[next])
			ret = max(ret, lis3(next) + 1);
	return ret;
}

int main() {
	int testcase;
	cin >> testcase;
	for (int tc = 0; tc < testcase; tc++) {
		memset(cache2, -1, sizeof(cache2));
		cin >> n2;
		for (int k = 0; k < n2; k++) {
			int num;
			cin >> num;
			S2[k] = num;
		}
		cout<< (lis3(-1) - 1) << endl;
	}
}