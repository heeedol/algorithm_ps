// Ch8 ����: Quantization �� ��� �Դϴ�.
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int n;
int A[101], pSum[101], pSqSum[101];

void precalc() {
	sort(A, A + n);
	pSum[0] = A[0];
	pSqSum[0] = A[0] * A[0];
	for (int i = 1; i < n; ++i) {
		pSum[i] = pSum[i - 1] + A[i];
		pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
	}
}
int minError(int lo, int hi) {
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);
	int m = int(0.5 + (double)sum / (hi - lo + 1));
	int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
	return ret;
}
int cache[101][11];
int quantize(int from, int parts) {
	if (from == n) return 0;
	if (parts == 0) return INF;
	int& ret = cache[from][parts];
	if (ret != -1) return ret;
	ret = INF;
	for (int partSize = 1; from + partSize <= n; ++partSize) {
		ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));
	}
	return ret;
}

void main() {
	int parts;
	cin >> n >> parts;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 11; j++) {
			cache[i][j] = -1;
		}
	}
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		A[i] = a;
	}
	precalc();
	cout << quantize(0, parts) << endl;
}
