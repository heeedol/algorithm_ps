#include "RNG.h"

RNG::RNG(int n) {
	A.push_back(1983);
	for (int i = 1; i < n; i++) {
		int a=(A[i - 1] * 214013 + 2531011) % int(pow(2, 32));
		A.push_back(a%10000+1);
	}
}
void RNG::print() {
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}