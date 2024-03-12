#include <bits/stdc++.h>
using namespace std;

int n, m, r, root;
vector<int> adj[54];

int dfs(int here){
    int ret = 0;
    int child = 0;
    for(int there : adj[here]){
        // 지울 노드를 제외하는 방식
        if(there == r) continue;
        ret += dfs(there);
        child++;
    }

    if(child == 0) return 1;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> m;
        if(m == -1)  root = i;
        else adj[m].push_back(i);
    }

    cin >> r;

    if(r == root){
        cout << 0 << '\n';
        return 0;
    }
    cout << dfs(root) << '\n';
    return 0;
}