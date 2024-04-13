#include <bits/stdc++.h>
using namespace std;

int n, m, ny, nx, sum;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int map[54][54];
vector<pair<int, int>> chicken, house;

// void dfs(int y, int x){
//     visited[y][x] = 1;
//     for(int i=0 ; i<4 ; i++){
//         ny = y + dy[i];
//         nx = x + dx[i];
//         if(ny < 0 ||nx < 0 || ny >= n || nx >= n || visited[ny][nx] == 1) continue;
//         dfs(ny, nx);
//     }
// }

int solve(int y, int x){

}

// 도시에 있는 치킨집 중 최대 m개
// 어떻게 고르면 "도시의" 치킨 거리가 가장 작게 될지 구하는 프로그램
// "도시의" 치킨 거리 = 모든 집의 치킨 거리의 합
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    // 2 <= n <= 50 : 도시 크기
    // 1 <= m <= 13 : 수익을 가장 많이 낼 수 있는 치킨 집 개수
    cin >> n >> m;
    int dts[m];

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            // 1 < "1" <= 2n
            // m <= "2" <= 13
            cin >> map[i][j];
            if(map[i][j] == 1) house.push_back({i, j});
            if(map[i][j] == 2) chicken.push_back({i, j});
        }
    }

    // 치킨집 m개에서 최소 도시의 치킨 거리
    // chicken 크기 중 m개를 뽑아서 최소 거리

    // 1. m개를 뽑는 경우의 수 -> 조합? 재귀? 어떻게? 
    // 2. 각 경우의 수에서 "도시의" 치킨 거리 구하기
    // 3. 최소 도시의 치킨 거리 구하기
    // 4. 출력



    return 0;
}