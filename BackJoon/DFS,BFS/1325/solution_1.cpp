#include <bits/stdc++.h>
#define max_n 100001
using namespace std;

int n, m, a, b, ret, final;
int dp[max_n], visited[max_n];
vector<int> adj[max_n];

int dfs(int here){
    visited[here] = 1;
    int ret = 1;
    for(int there : adj[here]){
        if(visited[there]) continue;
        ret += dfs(there);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for(int i=1 ; i<=n ; i++){
        memset(visited, 0, sizeof(visited));
        dp[i] = dfs(i);
        final = max(final, dp[i]);
    }
    
    for(int i=1 ; i<=n ; i++) if(final == dp[i]) cout << i << ' ';

    return 0;
}