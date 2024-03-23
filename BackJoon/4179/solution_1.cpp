#include <bits/stdc++.h>
#define max_n 1004
using namespace std;

const int INF = 987654321;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int r, c, y, x, sy, sx, ret;
char _map[max_n][max_n];
int fire[max_n][max_n], person[max_n][max_n];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 가장 빠른 탈출시간을 구하는 문제이므로 BFS 사용 -> 큐 
    queue<pair<int, int>> q;
    
    cin >> r >> c;
    // 불 확산 배열 INF 값으로 초기화
    // 왜 불 확산 배열 INF 값으로 초기화?
    // 지훈이 좌표, 불 확산 좌표 비교하는 코드에서 불 확산 지도를 기준으로 비교하기 때문
    fill(&fire[0][0], &fire[0][0] + max_n * max_n, INF);
    for(int i=0 ; i<r ; i++){
        for(int j=0 ; j<c ; j++){
            cin >> _map[i][j];
            if(_map[i][j] == 'F'){
                fire[i][j] = 1;    // 불이 난 공간 여러 개
                q.push({i, j});    // 지도 큐에 좌표 저장
            } else if(_map[i][j] == 'J'){
                // 지훈이 공간 한 개
                // 좌표 값만 저장
                sy = i;
                sx = j;
            }
        }
    }

    // BFS로 불 확산 좌표에 최단 거리 값 저장
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i=0  ; i<4 ; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if(fire[ny][nx] != INF || _map[ny][nx] == '#') continue;
            fire[ny][nx] = fire[y][x] + 1;
            q.push({ny, nx});
        }
    }

    // 불 확산으로 사용한 큐 q에 BFS로 그 다음 지훈이가 이동 좌표 저장
    person[sy][sx] = 1;
    q.push({sy, sx});
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        // 지훈이가 가장자리에 도착 했을 경우 최단 거리 값 리턴
        if(x == r-1 || y == c-1 || x == 0 || y == 0){
            ret = person[y][x];
            break;
        }
        for(int i=0 ; i<4 ; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if(person[ny][nx] || _map[ny][nx] == '#') continue;
            // 지훈이 좌표, 불 확산 좌표 비교 해 지훈이의 값이 더 클 경우 
            // 불 확산 좌표에 저장된 값과 지훈이 좌표에 저장된 값에 1을 더한 값(다음 단계) 비교
            if(fire[ny][nx] <= person[ny][nx] + 1) continue;
            person[ny][nx] = person[y][x] + 1;
            q.push({ny, nx});
        }
    }
    if(ret != 0) cout << ret << '\n';
    else cout << "IMPOSSIBLE" << '\n';
    return 0;
}