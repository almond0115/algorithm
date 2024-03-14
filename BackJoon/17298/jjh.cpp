#include <bits/stdc++.h>
#define mx 1000004
using namespace std;

int n, num;
int arr[mx], ret[mx];
// vector<int> rbn;
stack<int> rbn;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 1 <= n <= 백만
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
        while(rbn.size() && arr[rbn.top()] < arr[i]){
            ret[rbn.top()] = arr[i];
            rbn.pop();
        }
        rbn.push(i);
    }

    for(int i=0 ; i<n ; i++) {
        if(ret[i] == 0) cout << -1 << ' ';
        else cout << ret[i] << ' ';
    }
    
    // 예제 정상 출력 but 시간 초과 발생 (100만 x 100만) 
    // for(int i=0 ; i<n ; i++){
    //     rbn.clear();
    //     for(int j=i+1 ; j<n ; j++){
    //         if(arr[i] < arr[j]) {
    //             rbn.push_back(arr[j]);
    //             break;
    //         }
    //     }
    //     if(rbn.size() == 0) cout << -1 << ' ';
    //     else cout << rbn.front() << ' ';
    // }

    // 시간 초과 어떻게 해결? dfs? stack?

    return 0;
}