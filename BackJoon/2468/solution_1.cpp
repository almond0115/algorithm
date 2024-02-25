#include <bits/stdc++.h>
using namespace std;

const int max_n = 101;
int n, y, x, ny, nx, final=1;
int arr[max_n][max_n], ret[max_n];
bool visited[max_n][max_n];
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

void dfs(int y, int x, int k){
    visited[y][x] = 1;
    for(int i=0 ; i<4 ; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(arr[ny][nx] > k && !visited[ny][nx]){
            dfs(ny, nx, k);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int k=1 ; k<101 ; k++) {
        fill(&visited[0][0], &visited[0][0] + 101*101, 0);
        int point = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(arr[i][j] > k && !visited[i][j]){
                    dfs(i, j, k);
                    point++;
                }
            }
        }
        final = max(final, point);
    }
    cout << final << '\n';

    return 0;
}