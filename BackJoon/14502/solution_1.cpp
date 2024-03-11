#include <bits/stdc++.h>
using namespace std;

int arr[9][9];
bool visited[9][9];
const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> virusList, wallList;
int n, m, ny, nx, ret;

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i=0 ; i<4 ; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        // 범위 밖이거나 벽이거나 이미 방문한 곳인 경우 continue
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] == 1 || visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int solve(){
    // 방문 배열 초기화
    fill(&visited[0][0], &visited[0][0] + 9*9, 0);
    // virus 위치 DFS
    for(auto it : virusList){
        dfs(it.first, it.second);
    }

    // 빈칸 개수 구하기
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

    cin >> n >> m;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            // 지도 값 입력
            cin >>  arr[i][j];

            // 0일 때 빈 칸 좌표 vector 저장
            if(arr[i][j] == 0) wallList.push_back({i, j});
            // 2일 때 바이러스 좌표 vector 저장
            if(arr[i][j] == 2) virusList.push_back({i, j});
        }
    }

    // 1. 벽 3개 세울 경우의 수 (Brute Force)
    for(int i=0 ; i<wallList.size() ; i++){
        for(int j=0 ; j<i ; j++){
            for(int k=0 ; k<j ; k++){
                // 지도에 벽 3개 세우기
                arr[wallList[i].first][wallList[i].second] = 1;
                arr[wallList[j].first][wallList[j].second] = 1;
                arr[wallList[k].first][wallList[k].second] = 1;

                // 바이러스 구간 DFS & 빈칸 최대 영역 개수 구하기
                ret = max(ret, solve());

                // 지도에 벽 3개 다시 내리기 (why? 다음 경우의 수를 위해) 
                arr[wallList[i].first][wallList[i].second] = 0;
                arr[wallList[j].first][wallList[j].second] = 0;
                arr[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }

    cout << ret << '\n';

    return 0;
}