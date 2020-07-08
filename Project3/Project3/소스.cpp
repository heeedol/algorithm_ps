#include <iostream>
#include <cstring>

using namespace std;

int n, m;
bool areFriends[10][10] = { 0 };
int output;
bool finish;

int countPairings(bool taken[10]) {
    int firstFree = -1;
    for (int i = 0; i < n; ++i) {
        if (!taken[i]) {
            firstFree = i;
            break;
        }
    }
    //���� ��� : ��� �л��� ¦�� ã������ �� ���� ����� ã������ �����Ѵ�.
    if (firstFree == -1) return 1;
    int ret = 0;
    //�� �л��� ¦���� �л��� �����Ѵ�.
    for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
        if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}

int main() {
    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
        output = 0;
        bool taken[10] = { 0 };
        memset(areFriends, 0, sizeof(areFriends));
        cin >> n >> m;
        for (int k = 0; k < m; k++) {
            int x, y;
            cin >> x >> y;
            areFriends[x][y] = 1;
            areFriends[y][x] = 1;
        }
        cout << countPairings(taken) << endl;
    }
    return 0;
}