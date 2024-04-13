#include <bits/stdc++.h>
using namespace std;

int n, m, ny, nx, h, ret;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int arr[101][101];
bool visited[101][101];
vector<pair<int, int>> cheeseList;

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i=0 ; i<4 ; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        if(arr[ny][nx] == 1) cheeseList.push_back({ny, nx}); continue;
        dfs(ny, nx);
    }
}

int solve(){
    fill(&visited[0][0], &visited[0][0] + 101*101, 0);
    for(auto it : cheeseList){
        cout << it.first << " " << it.second << endl;
        arr[it.first][it.second] = 0;
    }
    h++;
    cheeseList.clear();

    int cnt = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(arr[i][j] == 1) cnt++;
        }
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> arr[i][j];
        }
    }

    // 치즈 바깥쪽 어떻게 인식할까
    // 0과 맞닿아 있는 1? 
    // 바깥 0 완전 탐색을 통한 바깥 1 좌표 저장?
    while(!cheeseList.empty()){
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                // 0. "0"인 경우 DFS 완전 탐색
                // 1. {ny, nx} 좌표 값이 "1"인 경우 좌표 저장  
                if(arr[i][j] == 0 && !visited[i][j]){
                    dfs(i, j);
                }
            }
        }

        for(auto it : cheeseList){
            cout << it.first << " " << it.second << endl;
        }


        ret = solve();
    }

    cout << h << " and " << ret << '\n';
    
    return 0;
}