#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;


int append(int here, int edge, int mod) {
	int there = here * 10 + edge;  //자릿수를 하나 증가시킴
	if (there >= mod) return mod + there % mod; //반환 값은 새로 만들어진 수의 나머지. there가 mod 보다 큰 것은 회색이므로, 나누는 수(n)인 mod에 there%mod 를 더해준다.
	return there % mod;  //here이 0인 경우 대비. 
}

string gifts(string digits, int n, int m) {
	sort(digits.begin(), digits.end());  //digits는 사용 가능한 자리수이다. 
	vector<int> parent(2 * n, -1), choice(2 * n, -1); // parent[i] 는 i 정점의 부모이고, choice[i]는  parent[i] 에서 i로 연결되는 간선의 번호이다. 
	//m=0인 상황을 방지하기 위해서 2n의 크기로 벡터를 설정한다.
	queue<int> q;
	parent[0] = 0;  // m=0 일때의 상황 해결하기 위해서 설정. 흰색 0번 큐에 추가
	q.push(0); // 시작점
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < digits.size(); ++i) {
			int there = append(here, digits[i] - '0', n); //digits를 string으로 입력받으므로, '0'을 빼주어야 한다.
			if (parent[there] == -1) {  //부모가 아직 없다는 것은 방문하지 않았다는 것. 
				parent[there] = here;    //자식을 방문하기 전의 node가 부모로 저장됨.
				choice[there] = digits[i] - '0'; // 간선에 추가된 자릿수(edge)가 저장. 
				q.push(there); // queue 에 삽입. 
			}
		}
	} //while문이 끝나는 것은 나머지의 순환이 끝났을 때. 나머지는 싸이클을 이룬다.
	if (parent[n + m] == -1) return "impossible"; // while문을 돌고도 -1 이라는 것은 나머지가 주어진 digits로는 n+m의 나머지를 가지는 숫자를 가지지 못한다는 것.  

	string ret;  //결정된 숫자를 저장하는 container
	int here = n + m; //마지막에 도착해야만 하는 index.
	while (parent[here] != here) { //parent[here]== here 인 놈이 출발 지점이다. 
		ret += char('0' + choice[here]);
		here = parent[here]; //부모 단계로 거슬러 올라가기/
	}
		reverse(ret.begin(), ret.end());
		return ret;
}

int main() {
	int testCase;
	cin >> testCase;
	while (testCase) {
		string digits;
		int n, m;
		cin >> digits >> n >> m;
		cout << gifts(digits, n, m) << endl;
	}
	return 0;
}