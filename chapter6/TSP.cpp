#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 8
double dist[MAX][MAX];
int N;

double shortestPath(vector<int>& path, vector<bool>& visited, double currentlength) {
    //path:지금까지 경로
    //visited:각 도시의 방문 여부
    //currentLength: 지금까지 만든 경로의 길이
    //기저사례: 모든 도시를 방문했을 경우 이때까지의 길이를 반환하고 종료.
    if (path.size() == N) return currentlength;
    double ret = INFINITY;
    for (int next = 0; next < N; next++) {
        if (visited[next]) continue;
        int here = path.back();
        path.push_back(next);
        visited[next] = true;
        //나머지 경로의 모든경우중 최소의 길이 반환
        ret = min(ret, shortestPath(path, visited, currentlength + dist[here][next]));
        visited[next] = false;
        path.pop_back();
    }
    return ret;
}

int main(){
    int testcases;
    double distanceSum;
    vector<double> answer;
    cout << "case를 입력해주세요." << endl;
    cin >> testcases;
    for (int i = 0; i < testcases;i++) {
        distanceSum = INFINITY;
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cin >> dist[i][j];
        }
        //외판원이 출발하는 모든 정점의 경우 고려
        for (int j = 0; j < N; j++) {
            //j에서 출발
            vector<int> path(1, j);
            vector<bool> visited(N, 0);
            visited[j] = true;
            //모든 정점의 출발 경우에서 가장 짧은길이 반환
            distanceSum = min(distanceSum, shortestPath(path, visited, 0));
        }
        answer.push_back(distanceSum);
    }
    for (int i = 0; i < testcases; i++) {
        cout <<"case "<<i+1 << ":";
        printf("%10f\n", answer[i]);
    }
    return 0;
}

