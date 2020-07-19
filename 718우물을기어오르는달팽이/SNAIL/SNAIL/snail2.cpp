#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;
double cache[1000][1000];

double climb(int days, int climbed) {
	//±âÀú»ç·Ê
	if (days == 1) {
		if (climbed < 2) return 1;
		if (climbed == 2) return 0.75;
		if (climbed > 2) return 0;
	}

	double& ret = cache[days][climbed];
	if (ret != -1) return ret;

	return ret = 0.25* climb(days - 1, climbed - 1) + 0.75* climb(days - 1, climbed - 2);

}
int main() {
	int tcase;
	cin >> tcase;
	
	for (int i = 0; i < tcase; i++) {
		for (int j = 0; j < 1000; j++)
			for (int k = 0; k < 1000; k++)
				cache[j][k] = -1;
		int m;
		int n;
		cin >> n;
		cin >> m;
		cout << setprecision(16);
		cout << climb(m, n) << endl;
	}
	return 0;
}