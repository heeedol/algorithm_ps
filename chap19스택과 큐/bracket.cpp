#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char openBracket[3] = { '(','{','[' };
char closeBracket[3] = { ')','}',']' };

bool isBracketMatch(string givenString) {
	vector<char> charVec;
	int pos = 0;
	while (pos != givenString.size()) {
		char i = givenString[pos];
		if (i==openBracket[0]|| i == openBracket[1]|| i == openBracket[2]) {
			charVec.push_back(i);
		}
		else{
			if (charVec.size() == 0) 
				return 0;
			else if (i == closeBracket[0]) 
				if(charVec.back()== openBracket[0]) charVec.pop_back();
			else if (i == closeBracket[1])
				if (charVec.back() == openBracket[1]) charVec.pop_back();
			else if (i == closeBracket[2])
				if (charVec.back() == openBracket[2]) charVec.pop_back();
			else return 0;
		}
		++pos;
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