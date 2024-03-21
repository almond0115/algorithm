#include <bits/stdc++.h>
#define mx 1004 
using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0 , -1, 0};
int r, c, y, x;
char _map[mx][mx];
int visited[mx][mx];
vector<pair<int, int>> jihoon, fire;

// 어떻게 불이 확산되는 로직과 지훈이가 이동하는 로직을 어떻게 구현할 것인가?
// 불이 확산되는 좌표, 지훈이 이동하는 좌표를 저장
// 매 분 확산되는 단계마다 지훈이가 이동하는 좌표를 비교 저장 어떻게?
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> r >> c;
    for(int i=0 ; i<r ; i++){
        for(int j=0 ; j<c ; j++){
            cin >> _map[i][j];
            if(_map[i][j] == 'J') jihoon.push_back({i, j});
            if(_map[i][j] == 'F') fire.push_back({i, j}); 
        }
    }

    // 순회 기준 : 매 분마마다 불이 퍼지고 지훈이가 이동
    // 불이 퍼질때마다 퍼진 불 맵에 추가
    // 지훈이가 이동하는 기준? 업데이트 된 맵에 지훈이는 한번만 이동이 가능
    while(true){
        // 불은 네 지점으로 퍼짐
        // 업데이트 된 맵에 지훈이 위치 
        for(int i=0 ; i<r ; i++){
            for(int j=0 ; j<c ; j++){
                if(!visited[i][j] && _map[i][j] == 'J'){
                    bfs(i, j, fire);
                }
            }
        }
    }
}