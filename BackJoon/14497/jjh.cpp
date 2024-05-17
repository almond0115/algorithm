#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int n, m, a, b, c, d, y, x, ny, nx, ret;
char _map[304][304], visited[304][304];

// 최소 점프 횟수? BFS
int main(){
    // 1 <= n, m <= 300
    cin >> n >> m;
    cin >> a >> b >> c >> d;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> _map[i][j];
        }
    }

    // visited에 점프 횟수를 저장
    visited[a-1][b-1] = 0;
    queue<pair<int, int>> q;
    q.push({a-1, b-1});
    while(q.size()){
        // 파동은 flood fill 방식으로 구현
        int qSize = q.size();
        for(int i=0 ; i<qSize ; i++){
            tie(y, x) = q.front(); q.pop();
            for(int j=0 ; j<4 ; j++){
                ny = y + dy[j];
                nx = x + dx[j];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(visited[ny][nx] || _map[ny][nx] == '0') continue;
                visited[ny][nx] = visited[y][x] + 1;
                if(_map[ny][nx] == '#'){
                    cout << visited[ny][nx] << '\n';
                    return 0;
                }
                // if(_map[ny][nx] == '1' || _map[ny][nx] == '0') {
                //     _map[ny][nx] = '0';
                //     q.push({ny, nx});
                // }
                q.push({ny, nx});
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}