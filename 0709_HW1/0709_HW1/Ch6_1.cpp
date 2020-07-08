//'��ø �ݺ��� ��ü�ϱ�'(pg.148)�� �����Դϴ�.
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
	if (toPick == 0) { printPicked(picked); return; } // return�� ���� ����?
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int next = smallest; next < n; ++next) {
		picked.push_back(next); // ����ġ��
		pick(n, picked, toPick - 1);
		picked.pop_back(); // �ǵ��ư���
	}
}

void main() {
	// ��ü�ϱ� ���� ��ø��
	vector<int> picked;
	int n;
	cin >> n;

	// ��ü�ϱ� ���� ��ø��
	/*	for (int i = 0; i < n-3; ++i) { // n���ٴ� n-3�� �� ���� �� ����.
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