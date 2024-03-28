#include <bits/stdc++.h>
#define MAX 200000
using namespace std;

int visited[MAX+4];
long long cnt[MAX+4];

int n, k;

// 동생을 찾는 가장 빠른 시간, 방법의 수?
// 최단 거리?
int main(){
    cin >> n >> k;
    // if(n == k){
    //     puts("0"); puts("1");
    //     return 0;
    // }

    visited[n] = 1; 
    cnt[n] = 1;

    queue<int> q;
    q.push(n);
    while(q.size()){
        int now = q.front();
        q.pop();
        for(int next : {now-1, now+1, now*2}){
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