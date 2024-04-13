#include <bits/stdc++.h>
using namespace std;

const int max_n = 104;
int n, m, arr[max_n][max_n], visited[max_n][max_n], y, x;
string road;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

// void go(int y, int x){  
//     visited[y-1][x-1] = 1;
//     for(int i=0 ; i<4 ; i++) {
//         int ny = (y-1) + dy[i];
//         int nx = (x-1) + dx[i];
//         if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
//         if(arr[ny][nx] == 0) continue;
//         if(visited[ny][nx]) continue;
//         go(ny, nx);
//     }
//     return;
// }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    
    for(int i=0 ; i<n ; i++) {
        cin >> road;
        for(int j=0 ; j<m ; j++) {
            char num = road[j];
            arr[i][j] = atoi(&num);
        }
    }

    // BFS 최단거리 
    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({0, 0});
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i=0 ; i<4 ; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || arr[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    cout << visited[n-1][m-1] << '\n';

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}