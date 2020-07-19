#include <iostream>
#include <vector>
using namespace std;

int n, d, p, q, t;
int connected[51][51], deg[51];
double cache[51][101];

/*
double search(vector<int&> path) {
	if (path.size() == d + 1) {
		if (path.back() != q) return 0.0;
		double ret = 1.0;
		for (int i = 0; i + 1 < path.size(); ++i) {
			ret /= deg[path[i]];
		}
		return ret;
	}
	double ret = 0;
	for (int there = 0; there < n; ++there) {
		if (connected[path.back()][there]) {
			path.push_back(there);
			ret += search(path);
			path.pop_back();
		}
	}
	return ret;
}
*/

double search2(int here, int days) {
	if (days == d) return (here == q ? 1.0 : 0.0);
	double& ret = cache[here][days];
	if (ret > -0.5) return ret;
	ret = 0.0;
	for (int there = 0; there < n; ++there) {
		if (connected[here][there]) {
			ret += search2(there, days + 1)/deg[here];
		}
	}
	return ret;
}

void init() {
	int tmp;
	int count;
	cin >> n >> d >> p;
	for (int i = 0; i < n; ++i) {
		count = 0;
		for (int j = 0; j < n; ++j) {
			cin >> tmp;
			connected[i][j] = tmp;
			if (tmp == 1) count++;
		}
		deg[i] = count;
	}
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 101; j++) {
			cache[i][j] = -1;
		}
	}
}

void main() {
	init();
	cout << endl;
	cout << endl;
	cout << endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << connected[i][j] << " ";
		}
		cout << endl;
		cout << endl;
		cout << deg[i];
	}
	int ttmp;
	cin >> t;
	vector<int> T;
	for (int i = 0; i < t; i++) {
		cin >> ttmp;
		T.push_back(ttmp);
	}
	for (int i = 0; i < t; i++) {
		cout << T[i] << endl;
		cout << search2(T[i], 1) << " ";
	}
}



