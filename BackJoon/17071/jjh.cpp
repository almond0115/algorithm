#include <bits/stdc++.h>
using namespace std;

const int MAX = 500000;
int n, k, turn = 1, ok;
int visited[2][MAX+4];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;

    visited[0][n] = 1;
    queue<int> q;
    q.push(n);
    while(q.size()){
        k += turn;
        if(k > MAX) break;
        if(visited[turn % 2][k]) {
            ok = 1; 
            break;
        }
        // flood fill 적용
        int qSize = q.size();
        for(int i=0 ; i < qSize ; i++){
            int now = q.front(); q.pop();
            for(int next : {now+1, now-1, now*2}){
                if(next < 0 || next >= MAX || visited[turn % 2][next]) continue;
                visited[turn % 2][next] = visited[(turn + 1) % 2][now] + 1;
                if(next == k) {
                    ok = 1; 
                    break;
                }
                q.push(next);
            }
            if(ok) break;
        }
        if(ok) break;
        turn++;
    }
    if(ok) cout << turn << '\n';
    else cout << -1 << '\n';
    return 0;
}