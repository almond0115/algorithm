#include <bits/stdc++.h>
using namespace std;

// typedef INF = 987654321;

int n, hp, cnt, ret;
vector<int> scv;
const int attack[] = {9, 3, 1};

int main(){
    // 1 <= n <= 3
    cin >> n;
     
    for(int i=0 ; i<n ; i++){
        cin >> hp;
        scv.push_back(hp);
    }

    // 오름차순 정렬 이후 -9, -3, -1 순으로 공격 반복
    // while(true){
    //     if(cnt >= scv.size()) break;

    //     sort(scv.begin(), scv.end(), greater<int>());

    //     for(int i=0 ; i<scv.size() ; i++){
    //         cout << "scv : " << scv[i] << " , cnt : " << cnt << '\n';
    //         if(scv[i] <= 0) {
    //             scv[i] = 0;
    //             cnt++; 
    //             continue;
    //         }
    //         scv[i] -= attack[i];
    //         cout << "attack : " << attack[i] << '\n';
    //     }

    //     for(int s : scv){
    //         cout << s << " ";
    //     }
    //     cout << '\n';

    //     ret++;
    // }

    // cout << ret-1 << '\n';

    // 모든 scv 파괴하기 위한 공격 횟수의 최솟값? BFS 
    // 그래프로 어떻게 표현?

    return 0;
}