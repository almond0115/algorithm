#include <bits/stdc++.h>
using namespace std;

const int MAX = 500000;
int n, k, ok, turn = 1;

// 동생 찾는 최단 시간을 홀,짝으로 구분하여 방문 처리
// why? 공간 복잡도 최소화
int visited[2][MAX+4];

int  main(){
    cin >> n >> k;
    if(n == k){ 
        cout << 0 << '\n';
        return 0;
    }
    visited[0][n] = 1;
    queue<int> q;
    q.push(n);
    while(q.size()){
        k += turn;                  // 동생 위치 이동
        if(k > MAX) break;          // 동생 위치 범위 초과
        if(visited[turn % 2][k]){ 
            ok = 1; break;          // 동생 위치 도달했다면 true
        }

        // 동생의 좌표가 k += turn 코드로 이동할 때마다
        // 수빈이의 이동을 flood fill 방식으로 적용
        // 1 -> 3 -> 9 ...
        int qSize = q.size();      
        for(int i=0 ; i<qSize ; i++){
            int now = q.front(); q.pop();
            for(int next : {now+1, now-1, now*2}){
                // overflow, 방문 여부 체크
                if(next < 0 || next > MAX || visited[turn % 2][next]) continue;
                visited[turn % 2][next] = visited[(turn + 1) % 2][now] + 1;
                if(next == k){
                    ok = 1; break;
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

