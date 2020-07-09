#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> dwarf;

void main() {
	int height, sum = 0;
	bool ok = false;
	for (int i = 0; i < 9; ++i) {
		cin >> height;
		dwarf.push_back(height);
		sum += height;
	}
	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if ((sum - dwarf[i] - dwarf[j]) == 100) {
				dwarf.erase(dwarf.begin() + i);
				dwarf.erase(dwarf.begin() + j - 1);
				ok = true;
				break;
			}
		}
		if (ok) break;
	}
	if (ok) {
		cout << "answer" << endl;
		sort(dwarf.begin(), dwarf.end());
		for (int k = 0; k < dwarf.size(); ++k) {
			cout << dwarf[k] << endl;
		}
	}
}