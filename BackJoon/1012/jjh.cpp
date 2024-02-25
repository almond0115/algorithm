#include <bits/stdc++.h>
using namespace std;

const int max_n = 54;
int t, n, m, k, y, x, a, b;
int arr[max_n][max_n], visited[max_n][max_n];
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i=0 ; i<4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(arr[ny][nx] == 1 && !visited[ny][nx]){
            dfs(ny, nx);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    scanf("%d", &t);
    int tk = t;
    int ret[t], p = 0;
    while(t--){
        int num = 0;
        scanf("%d %d %d", &n, &m, &k);
        while(k--){
            scanf("%d %d", &a, &b);
            arr[a][b] = 1;
        }

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(arr[i][j] == 1 && !visited[i][j]){
                    num++; dfs(i, j);
                }
            }
        }

        ret[p] = num;
        p++;
    } 

    for(int i=0 ; i<tk ; i++){
        printf("%d\n", ret[i]);
    }

    return 0;
}