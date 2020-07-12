// 아래 문제는 pg.176 의 예제: 수열의 빠른 합과 형렬의 빠른 제곱의 해답입니다.
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
long long int fastSum(int n) {
	if (n == 1) return 1;
	if (n % 2 == 1) return fastSum(n - 1) + n;
	return 2 * fastSum(n / 2) + (n / 2) * (n / 2);
}

class SquareMatrix {
public:
	SquareMatrix identity(int n);
	vector<vector<int>> numBox;
	int size;
	SquareMatrix() {
		size = 1;
		vector<int> a;
		a.push_back(0);
		numBox.push_back(a);
	}
	SquareMatrix(int n) {
		size = n;
		vector<int> a;
		for (int i = 0; i < size; i++) {
			a.push_back(0);
		}
		for (int i = 0; i < size; i++) {
			numBox.push_back(a);
		}
	}
	void setMatrix() {
		cout << "size :";
		int a;
		cin >> a;
		size = a;
		numBox.clear();
		for (int i = 0; i < size; i++) {
			vector<int> a;
			for (int j = 0; j < size; j++) {
				int b;
				cout << i << " row " << j << " col :";
				cin >> b;
				a.push_back(b);
			}
			numBox.push_back(a);
		}
		cout << endl;
	}
	void printMatrix() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << numBox[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	SquareMatrix operator*(SquareMatrix& a) {
		SquareMatrix b (size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				b.numBox[i][j]=0;
				for (int k = 0; k < size; k++) {
					 b.numBox[i][j] += numBox[i][k] * a.numBox[k][j];
				}
			}
		}
		return b;
	}
	
};
SquareMatrix identity(int n) {
	SquareMatrix a(n);
	for (int i = 0; i < n; i++) {
		a.numBox[i][i] = 1;
	}
	return a;
}

SquareMatrix pow(SquareMatrix& A, int m) {
	if (m == 0) return identity(A.size);
	if (m % 2 > 0) return pow(A, m - 1) * A;
	SquareMatrix half = pow(A, m / 2);
	return half * half;
}

void main() {
	clock_t start, finish;

	long long int sum = 0;
	start = clock();
	for (int i = 1; i <= 80000; i++) {
		sum += i;
	}
	finish = clock();
	cout << "직접 계산 값은 " << sum << " 걸린시간은 " << finish - start << endl;

	start = clock();
	long long int sum2 = fastSum(80000);
	finish = clock();
	cout << "정복알고리즘을 돌린 값은 " << sum2 << " 걸린시간은 " << finish - start << endl;

	SquareMatrix a;
	
	a.setMatrix();
	a.printMatrix();
	
	start = clock();
	SquareMatrix A = (a * a * a * a * a * a);
	finish = clock();
	cout << "직접 계산 값은 " << endl;
	A.printMatrix();
	cout << "걸린시간은 " << finish - start << endl;
	cout << endl;

	start = clock();
	SquareMatrix B = pow(a, 6);
	finish = clock();
	cout << "정복알고리즘의 값은 " << endl;
	B.printMatrix();
	cout << "걸린시간은 " << finish - start << endl;
	cout << endl;
}