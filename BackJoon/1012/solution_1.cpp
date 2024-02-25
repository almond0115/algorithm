#include <bits/stdc++.h>
using namespace std;

const int max_n = 51;
int t, n, m, k, ny, nx, a, b;
int arr[max_n][max_n];
bool visited[max_n][max_n];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i=0 ; i<4 ; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(arr[ny][nx] == 1 && !visited[ny][nx]){
            dfs(ny, nx);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    while(t--){
        // test case 초기화
        fill(&arr[0][0], &arr[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        
        int ret = 0;
        cin >> n >> m >> k;
        
        for(int i=0 ; i<k ; i++){
            cin >> a >> b;
            arr[a][b] = 1;
        }
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(arr[i][j] == 1 && !visited[i][j]){
                    dfs(i, j);
                    ret++;
                }
            }
        }
        cout << ret << '\n';
    }
    
    return 0;
}