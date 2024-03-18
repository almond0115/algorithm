#include <bits/stdc++.h>
using namespace std;

int n, m;
int result = 987654321;                 // 0 으로 초기화 하면 최소값 찾는데 문제가 생길 수 있음
int _map[54][54];                        // 크기 n x n 도시 
vector<pair<int, int>> chicken, house;  // 도시에 치킨집과 집의 좌표 값
vector<vector<int>> chickenList;        // 치킨집 좌표 인덱스 

void comp(int start, vector<int> v){
    if(v.size() == m){
        chickenList.push_back(v);
        return;
    }

    for(int i=start+1 ; i<chicken.size() ; i++){
        v.push_back(i);     // 저장된 치킨집 좌표 인덱스
        comp(i, v);         // 재귀를 통해 조합 구하기
        v.pop_back();       // 다음 조합을 위해 마지막 원소 제거
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> _map[i][j];
            if(_map[i][j] == 2) chicken.push_back({i, j});
            if(_map[i][j] == 1) house.push_back({i, j});
        }
    }

    vector<int> v;  // chicken에 저장된 각 좌표 값의 인덱스를 저장
    comp(-1, v);

    // comp 함수를 통해 구한 치킨집 좌표 인덱스 값 조합 순회
    for(vector<int> cList : chickenList){
        int ret = 0;
        // 각각의 저장된 집 좌표 인덱스마다 해당 조합의 치킨집 좌표 인덱스들 사이의 거리 구하기
        // 가장 가까운 치킨집과의 거리 저장 후 ret 변수에 저장 하기
        // 모든 집이 가지고 있는 치킨 거리를 ret에 더하면 ret은 해당 조합에서 도출된 "도시의" 치킨 거리가 됨
        for(pair<int, int> h : house){
            int _min = 987654321;     
            for(int c : cList){   
                int dist = abs(h.first - chicken[c].first) + abs(h.second - chicken[c].second);
                _min = min(dist, _min);   
            }
            ret += _min;
        }

        // 모든 조합에서 도출된 "도시의" 치킨 거리 중 최소 값을 result 변수에 저장
        result = min(result, ret);
    }

    cout << result << '\n';
    return 0;
}