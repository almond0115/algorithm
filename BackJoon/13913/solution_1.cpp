#include <bits/stdc++.h>
#define max_n 200010
using namespace std;

int n, k;
int visited[max_n], _prev[max_n];
vector<int> _move;

int main(){
    cin >> n >> k;

    // 1차원 BFS 시작 인덱스 설정
    visited[n] = 1;

    queue<int> q;
    q.push(n);
    while(q.size()){
        int now = q.front();
        q.pop();
        for(int next : {now+1, now-1, now*2}){
            if(next < 0 || next >= max_n || visited[next]) continue;
            visited[next] = visited[now] + 1;
            _prev[next] = now; 
            q.push(next);
        }
    }

    for(int i = k ; i != n ; i = _prev[i]){
        _move.push_back(i);
    }
    _move.push_back(n);
    reverse(_move.begin(), _move.end());

    cout << visited[k] - 1 << '\n';
    for(int i : _move) cout << i << ' ';
    return 0;
}