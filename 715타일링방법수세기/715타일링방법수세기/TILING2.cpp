#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
int cache[101];
int tiling(int width) {
	//기저사례 너비가 1이하일 때
	if (width <= 1) return 1;
	//메모이제이션
	int& ret = cache[width];
	if (ret != -1) return ret;
	//점화식
	return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;
}
int asymmetric(int width) {
	if (width % 2 == 1)
		return (tiling(width) - tiling(width / 2) + MOD) % MOD;
	int ret = tiling(width);
	ret = (ret - tiling(width / 2) + MOD) % MOD;
	ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;
}
int main() {
	for (int i = 0; i < 101; i++) {
		cache[i] = -1;
	}
	int tcase;
	cin >> tcase;
	for (int i = 0; i < tcase; i++) {
		int n;
		cin >> n;
		cout<<tiling(n)<<endl;
	}
	return 0;
}