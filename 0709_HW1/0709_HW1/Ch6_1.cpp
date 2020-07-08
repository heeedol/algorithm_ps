//'중첩 반복문 대체하기'(pg.148)의 예제입니다.
#include<iostream>
#include <vector>
using namespace std;
void printPicked(vector<int>& picked) {
	for (int i = 0; i < picked.size(); ++i) {
		cout << picked[i] << " ";
	}
	cout << endl;
}
void pick(int n, vector<int>& picked, int toPick) {
	if (toPick == 0) { printPicked(picked); return; } // return이 들어가는 이유?
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int next = smallest; next < n; ++next) {
		picked.push_back(next); // 가지치기
		pick(n, picked, toPick - 1);
		picked.pop_back(); // 되돌아가기
	}
}

void main() {
	// 대체하기 전의 중첩문
	vector<int> picked;
	int n;
	cin >> n;

	// 대체하기 전의 중첩문
	/*	for (int i = 0; i < n-3; ++i) { // n보다는 n-3이 더 좋을 것 같음.
			for (int j = i+1; j < n-2; ++j) {
				for (int k = j + 1; k < n-1; ++k) {
					for (int l = k + 1; l < n; ++l) {
						cout << i << " " << j << " " << k << " " << l << endl;
					}
				}
			}
		}
	*/

	int toPick;
	cin >> toPick;
	pick(n, picked, toPick);
}