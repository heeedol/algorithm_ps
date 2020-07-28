#include <iostream>
#include <algorithm>
#include<queue>
#include"RNG.h"
using namespace std;

struct RNG {
	unsigned seed;
	RNG(): seed(1983){}
	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};

int countRanges(int k, int n) {
	RNG rng;
	queue<int> range;
	int ret = 0, rangeSum = 0;
	for (int i = 0; i < n; i++) {
		int newSignal = rng.next();
		rangeSum += newSignal;
		range.push(newSignal);

		while (rangeSum > k) {
			//k이상이면 head를 1만큼 옮긴다.
			rangeSum -= range.front();
			range.pop();
		}
		if (rangeSum == k) ret++;
	}
	return ret;
}

int main() {
	cout<<countRanges(3578452, 5000000)<<endl;
	return 0;
}