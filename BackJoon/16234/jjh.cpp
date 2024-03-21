#include <bits/stdc++.h>
using namespace std;

// 1 <= n <= 50
// 1 <= l <= r <= 100
int n, l, r, ny, nx, sum, num, ret;
int _map[104][104], visited[104][104];
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

void dfs(int y, int x){
    visited[y][x] = 1;
    // sum += _map[y][x];
    // cout << sum << '\n';
    for(int i=0 ; i<4 ; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
        if(abs(_map[ny][nx] - _map[y][x]) >= l && abs(_map[ny][nx] - _map[y][x]) <= r){
            sum += _map[y][x];
            num++;
            cout << "map : " << _map[y][x] << " sum : " << sum << " num : " << num << '\n';
            dfs(ny, nx);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l >> r;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> _map[i][j];
        }
    }

    // 인구 이동 며칠 동안 발생?
    while(true){
        // 초기화
        num = 1, sum = 0;
        bool flag = false;
        memset(visited, 0, sizeof(visited));

        // dfs(0, 0);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(!visited[i][j]) dfs(i,j);
                if(sum == _map[i][j]) flag = true;
            }
        }

        // 이동한 인구가 없으면 종료
        if(flag) break;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(visited[i][j] == 1){
                    _map[i][j] = sum / num;
                }
            }
        }

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                cout << _map[i][j] << " ";
            }
            cout << endl;
        }

        ret++;
    }
    cout << ret << '\n';

    return 0;
}