#include <bits/stdc++.h>
#define max_n 10001
using namespace std;

int n, m, a, b, final;
int comp[max_n], visited[max_n]; 
vector<int> hack[max_n];

int dfs(int n){
    visited[n] = 1;
    int ret = 1;
    for(int next : hack[n]){
        if(visited[next]) continue;
        ret += dfs(next);
    }
    return ret;    
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // n <= 10,000
    // m <= 100,000
    cin >> n >> m;
    
    // 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터 번호 오름차순 출력
    for(int i=0 ; i<m ; i++){
        cin >> a >> b;
        hack[b].push_back(a); 
    }

    for(int i=1 ; i<=n ; i++){
        fill(visited, visited + max_n, 0);
        comp[i] = dfs(i);
        final = max(comp[i], final);
    }

    for(int i=1 ; i<=n ; i++) {
        if(final == comp[i]) cout << i << " ";
    }

    return 0;
}