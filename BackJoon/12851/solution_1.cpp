#include <bits/stdc++.h>
#define MAX 200000
using namespace std;

int n, k;
int visited[MAX+4], cnt[MAX+4];

// 1차원 맵에서 BFS 어떻게 구현?
int main(){
    cin >> n >> k;

    // 시작과 끝이 같을 경우 예외 처리
    if(n == k){
        puts("0"); puts("1");
        return 0;
    }
    // 1차원 방문, 경우의 수 인덱스
    visited[n] = 1;
    cnt[n] = 1;

    queue<int> q;
    q.push(n);
    while(q.size()){
        int now = q.front();
        q.pop();
        for(int next : {now+1, now-1, now*2}){
            // 0 <= next <= 10만
            if(0 <= next && next <= MAX){
                if(!visited[next]){
                    q.push(next);
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now];
                } else if(visited[next] == visited[now] + 1){
                    cnt[next] += cnt[now];
                }
            }
        }
    }

    cout << visited[k] - 1 << '\n';
    cout << cnt[k] << '\n';

    return 0;
}