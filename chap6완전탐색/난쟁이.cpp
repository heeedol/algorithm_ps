#include <vector>
#include <iostream>

using namespace std;
int height[9];
vector<int> picked;

void insertSort(int v[]) {
	for (int a = 0; a < 9; a++) {
		for (int b = 0; b<a;b++){
			if (v[a] < v[b]) {
				int tem = v[a];
				v[a] = v[b];
				v[b] = tem;
		  }
		}
	}
}

void pick(int n, vector<int>& picked, int toPick) {
	if (toPick == 0) {
		int heightSum=0;
		for (int i = 0; i < picked.size(); i++) heightSum += height[picked[i]];
		if (heightSum == 100) {
			for (auto i : picked) cout << height[i] << endl;
			return;
		}
		return;
	}
	int smallest = picked.empty() ? 0 : picked.back()+1;
   
	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		int a;
		cin >> a; 
		height[i] = a;
	}
	insertSort(height);
    pick(9, picked, 7);
	return 0;
}