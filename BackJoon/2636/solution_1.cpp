#include <bits/stdc++.h>
using namespace std;

int n, m, ny, nx, hours, cnt;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int arr[104][104];
bool visited[104][104];
vector<pair<int, int>> cheeseList;

void dfs(int y, int x){
    visited[y][x] = 1;
    // 치즈일 경우 치즈 배열에 추가 후 재귀 리턴하기  
    if(arr[y][x] == 1){
        cheeseList.push_back({y, x});
        return;
    }
    for(int i=0 ; i<4 ; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0 ; i<n ;i++){
        for(int j=0 ; j<m ; j++){
            cin >> arr[i][j];
        }
    }

    while(true){
        // 방문 배열/바깥 치즈 배열 초기화 
        fill(&visited[0][0], &visited[0][0] + 104*104, 0);
        cheeseList.clear();
        
        // 바깥 치즈 DFS 완전 탐색
        dfs(0, 0);

        // 바깥 치즈 개수 저장하기
        cnt = cheeseList.size();

        // 저장된 바깥 치즈 배열 좌표 지도에서 0으로 바꾸기
        for(auto it : cheeseList){
            arr[it.first][it.second] = 0;
        }

        // 지도가 모두 0이 될때까지 반복하는 로직
        bool flag = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ;j++){
                if(arr[i][j] != 0) flag = 1;  
            }
        }

        // break 하기 전에 1시간 추가
        hours++;
        
        // 지도가 모두 0일때 break
        if(!flag) break;
    }

    cout << hours << '\n';
    cout << cnt << '\n';

    return 0;
}