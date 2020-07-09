#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int height;
vector<int> dwarf;
vector<int> emptyVector;


void printPicked(vector<int>& picked) {
	for (int i = 0; i < picked.size(); i++) {
		cout << dwarf[picked[i]] << ' ';
	}
	cout << endl;
}

void pick(int n, vector<int>& picked, int toPick) {
	//±âÀú»ç·Ê
	if (height == 100 && toPick == 0) {
		printPicked(picked); return;
	}
	int smallest = (picked.empty() ? 0 : picked.back() + 1);

	for (int next = smallest; next < n; ++next) {
		height += dwarf[next];
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		height -= dwarf[next];
		picked.pop_back();
	}
}

void main() {
	for (int i = 0; i < 9; i++) {
		int a;
		cin >> a;
		dwarf.push_back(a);
	}
	height = 0;
	sort(dwarf.begin(), dwarf.end());
	pick(9, emptyVector, 7);
}