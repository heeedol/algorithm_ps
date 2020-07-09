```
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> word55;
const int dx[8] = { -1,-1,-1,1,1,1,0,0 };
const int dy[8] = { -1,0,1,-1,0,1,-1,1 };
bool hasWord(int y, int x, string word) {
	//잘못된 입력에 대한 것
	if ((y < 0 || y >= 5) || (x < 0 || x >= 5)) {
		return false;
	}
	if (word[0] != word55[y][x]) {
		return false;
	}
	if (word.size() == 1) {
		return true;
	}
	word.erase(word.begin());
	for (int direction = 0; direction < 8; ++direction) {
		int nextY = y + dy[direction];
		int nextX = x + dx[direction];
		if (hasWord(nextY, nextX, word))
			return true;
	}
	return false;
	//안되는 이유: True 가 하나라도 나오면 true 임. 근데 이런 식으로 하게 되면 true 랑 false 중에서 먼저 나오는 놈이 return 된다.
	//즉, false가 나온부분에 대해서 제대로 생각을 못한 것.
		/*hasWord(y - 1, x - 1, word);
		hasWord(y - 1, x, word);
		hasWord(y - 1, x + 1, word);
		hasWord(y, x + 1, word);
		hasWord(y + 1, x + 1, word);
		hasWord(y + 1, x, word);
		hasWord(y + 1, x - 1, word);
		hasWord(y, x - 1, word);*/

}
void word55Fill() {
	word55.push_back("urlpm");
	word55.push_back("xpret");
	word55.push_back("giaet");
	word55.push_back("xtnzy");
	word55.push_back("xoqrs");
}
void main() {
	word55Fill();
	(hasWord(1, 1, "pxpret") ? cout << "YES" << endl : cout << "NO" << endl);
}
```

