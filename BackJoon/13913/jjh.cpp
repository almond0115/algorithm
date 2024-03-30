#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;
int n, k, ret;
int visited[MAX+4], _prev[MAX+4];
vector<int> _move;

int main(){
    cin >> n >> k;

    visited[n] = 1;

    queue<int> q;
    q.push(n);
    while(q.size()){
        int now = q.front();
        q.pop();
        if(now == k){
            ret = visited[k];
            break;
        }
        for(int next : {now+1, now-1, now*2}){
            if(next < 0 || next >= MAX || visited[next]) continue;
            q.push(next);
            visited[next] = visited[now] + 1;
            _prev[next] = now;
        }
    }

    // prev 로 trace
    for(int i = k ; i != n ; i = _prev[i]){
        _move.push_back(i);
    }
    _move.push_back(n);
    reverse(_move.begin(), _move.end());
    
    cout << ret - 1 << '\n';
    for(int i : _move) cout << i << ' ';
    return 0;
}

