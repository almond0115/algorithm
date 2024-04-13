#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int n, l, r, sum, ret;
int _map[54][54], visited[54][54];
vector<pair<int, int>> _move;

void dfs(int y, int x, vector<pair<int, int>> &v){
    visited[y][x] = 1;
    for(int i=0 ; i<4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
        if(abs(_map[ny][nx] - _map[y][x]) >= l && abs(_map[ny][nx] - _map[y][x]) <= r){
            sum += _map[ny][nx];
            _move.push_back({ny, nx});
            dfs(ny, nx, _move);
        }
    }
}

int main(){
    cin >> n >> l >> r;
    for(int i=0 ; i<n; i++){
        for(int j=0 ; j<n ; j++){
            cin >> _map[i][j];
        }
    }

    while(true){
        // 새로운 인구 이동 위한 flag, 방문 배열 초기화
        bool flag = 0;
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);

        // DFS 완전 탐색
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j< n ; j++){
                if(!visited[i][j]){
                    _move.clear();                      // 이동 좌표 저장 벡터 초기화
                    sum = _map[i][j];                   // DFS 시작 전 시작 국가 인구로 초기화
                    _move.push_back({i, j});            // 시작 국가 좌표 저장
                    dfs(i, j, _move);                   // DFS 시작
                    if(_move.size() == 1) continue;     // 인구 이동 안했으면 continue
                    for(pair<int, int> each : _move){   // 인구 이동한 좌표들의 인구 수 갱신
                        _map[each.first][each.second] = sum / _move.size();
                        flag = 1;                       // 인구 이동 했으면 flag = 1
                    }
                }
            }
        }
        // flag 가 0 (false) ? for 문 순회할 동안 인구 수 갱신이 없었다는 의미 
        // flag 가 1 (true)  ? while 순회
        if(!flag) break;
        ret++;
    }
    cout << ret << '\n';
    return 0;
}
