#include <bits/stdc++.h>
using namespace std;

int n, m, d, root;
vector<int> v[54];

int dfs(int r){
    int leaf = 0;
    int child = 0;
    // 부모 노드 인덱스에 저장된 자식 노드 순회
    for(int i : v[r]){
        // 지울 노드인 경우 탐색 X
        if (i == d) continue;
        // 재귀를 통해 리턴 받은 리프 노드 수확(?)
        leaf += dfs(i);
        child++;
    }

    // 리프 노드인 경우
    if(child == 0) return 1;
    return leaf;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0 ; i<n ; i++){
        // m 은 각 노드의 부모를 의미!
        cin >> m;
        // -1 일 경우 루트 노드
        // 부모 노드 배열에 해당 자식 노드의 인덱스 저장
        if(m == -1) root = i;
        else v[m].push_back(i);
    }

    cin >> d;
    // 루트 노드가 삭제 노드인 경우 예외 처리
    if(d == root){
        cout << 0 << '\n';
        return 0;
    }
    cout << dfs(root) << '\n';

    return 0;

    
}