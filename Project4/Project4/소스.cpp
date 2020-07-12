#include <string>
#include <iostream>

using namespace std;

string reverse(string::iterator& it) {
	char head = *it;
	++it;
	if (head == 'b' || head == 'w') {
		return string(1, head);
	}
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);

	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
	int testcase;
	cin >> testcase;
	for (int tc = 0; tc < testcase; tc++) {
		string k;
		cin >> k;
		auto it = k.begin();
		cout << reverse(it) << endl;
	}
}