#include <bits/stdc++.h>
using namespace std;

const int max_n = 101;
int n, m, k, ny, nx, a, b, c, d;
int arr[max_n][max_n], visited[max_n][max_n];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<int> ret;

int dfs(int y, int x){
    visited[y][x] = 1;
    int ret = 1;
    for(int i=0 ; i<4 ; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx] == 1) continue;
        if(arr[ny][nx] == 1) continue;
        ret += dfs(ny, nx);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 1<= m, n, k <= 100
    cin >> n >> m >> k;
    
    for(int i=0 ; i<k ; i++) {
        cin >> a >> b >> c >> d;
        for(int i=a ; i<c ; i++){
            for(int j=b ; j<d ; j++){
                arr[i][j] = 1;
            }
        }
    }

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(arr[i][j] != 1 && visited[i][j] == 0){
                ret.push_back(dfs(i, j));   
            }
        }
    }

    sort(ret.begin(), ret.end());
    
    cout << ret.size() << '\n';
    for(int final : ret) cout << final << ' ';

    return 0;
}