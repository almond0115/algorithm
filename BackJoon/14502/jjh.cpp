#include <bits/stdc++.h>
using namespace std;

int arr[10][10], visited[10][10];
vector<pair<int, int>> vlist, wlist;
int n, m, ny, nx, ret;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i=0 ; i<4 ; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m  || visited[ny][nx] || arr[ny][nx] == 1) continue;
        dfs(ny, nx);
    }
    return;
}

int solve(){
    // 초기화
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
    // 2. 바이러스 위치 DFS
    for(pair<int, int> i : vlist){
        dfs(i.first, i.second);
    }

    // 3. 빈칸 개수 구하기
    int cnt = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(arr[i][j] == 0 && !visited[i][j]) cnt++;
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 3 <= n, m <= 8
    cin >> n >> m;
    
    // 2 : 바이러스 ( 2 <= {2} <= 10)
    // 1 : 벽 (반드시 3개)
    // 0 : 빈 칸 (3개 이상)
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2) vlist.push_back({i, j});
            if(arr[i][j] == 0) wlist.push_back({i, j});
        }
    }

    for(int i=0 ; i<wlist.size() ; i++){
        for(int j=0 ; j<i ; j++){
            for(int k=0 ; k<j ; k++){
                // 1. 벽 3개 세우기
                arr[wlist[i].first][wlist[i].second] = 1;
                arr[wlist[j].first][wlist[j].second] = 1;
                arr[wlist[k].first][wlist[k].second] = 1;

                // 4. 빈칸 최대 영역 구하기
                ret = max(ret, solve());
                arr[wlist[i].first][wlist[i].second] = 0;
                arr[wlist[j].first][wlist[j].second] = 0;
                arr[wlist[k].first][wlist[k].second] = 0;
            }
        }
    }

    cout << ret << '\n';

    return 0;
}