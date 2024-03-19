#include <bits/stdc++.h>
#define max_n 54
using namespace std;

int n, m, y, x, ny, nx, _max; 
char _map[max_n][max_n];
int visited[max_n][max_n];
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

void bfs(int y, int x){
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i=0 ; i<4 ; i++){
            ny = y + dy[i];
            nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || _map[ny][nx] == 'W') continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            _max = max(_max, visited[i][j]);
        }
    
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            scanf("%1s", &_map[i][j]);
        }
    }
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(_map[i][j] == 'L'){
                memset(visited, 0, sizeof(visited));
                bfs(i, j);
            }
        }
    }
    cout << _max - 1 << '\n';
    return 0;
}
