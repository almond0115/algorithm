#include <bits/stdc++.h>
using namespace std;

int n, m, ny, nx, _max;
char _map[54][54];
int visited[54][54];
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

void bfs(int y, int x){
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i=0 ; i<4 ; i++){
            ny = y + dy[i];
            nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || _map[ny][nx] == 'W') continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            _max = max(_max, visited[ny][nx]);
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> _map[i][j];
        }
    }

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(_map[i][j] == 'L'){
                bfs(i, j);
            }
        }
    }

    cout << _max - 1 << '\n';
}