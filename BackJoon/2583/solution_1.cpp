#include <bits/stdc++.h>
#define y1 aaaa
using namespace std;

const int max_n = 104;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int n, m, k, x1, y1, x2, y2, nx, ny;
int arr[max_n][max_n], visited[max_n][max_n];
vector<int> ret;

int dfs(int y, int x){
    visited[y][x] = 1;
    int num = 1;
    for(int i=0 ; i<4 ; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx] == 1) continue;
        if(arr[ny][nx] == 1) continue;
        num += dfs(ny, nx);
    }

    return num;
}

int main() {
    cin >> n >> m >> k;
    for(int i=0 ; i<k ; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int x=x1 ; x<x2 ; x++){
            for(int y=y1 ; y<y2 ; y++){
                arr[x][y] = 1;
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

    for(int final : ret){
        cout << final << ' ';
    }

    return 0;
}