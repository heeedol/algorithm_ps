#include <iostream>
#include <algorithm>
using namespace std;
int cache[100][100];

int climb(int days, int climbed) {
	//±âÀú»ç·Ê

	if (days == 0) return climbed <= 0 ? 1 : 0;

	int& ret = cache[days][climbed];
	if (ret != -1) return ret;
	
	return ret = climb(days - 1, climbed - 1) + climb(days - 1, climbed - 2);

}
int main() {
	int tcase;
	cin >> tcase;
	for (int i = 0; i < tcase; i++) {
		for (int j = 0; j < 100; j++)
			for (int k = 0; k < 100; k++)
				cache[j][k] = -1;
		int m;
		int n;
		cin >> m;
		cin >> n;
		cout << climb(m, n)/(double)pow(2,m) << endl;
	}
	return 0;
}