#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isBracketMatch(string givenString) {
	vector<char> charVec;
	int pos = 0;
	while (pos++ != givenString.size()) {
		char i = givenString[pos];
		if (i == '{' || i == '(' || i == '[') {
			charVec.push_back(i);
		}
		else{
			if (charVec.size() == 0) return 0;
			else if (i == charVec.back()) charVec.pop_back();
			else return 0;
		}
	}
	return 1;
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase-- > 0) {
		string givenString;
		cin >> givenString;
		cout<<isBracketMatch(givenString)<<endl;
	}
	return 0;
}