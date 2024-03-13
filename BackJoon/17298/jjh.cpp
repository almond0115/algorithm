#include <bits/stdc++.h>
#define mx 1000001
using namespace std;

int n, num;
int arr[mx];
vector<int> rbn;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 1 <= n, a <= 백만
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    // 시간 초과 발생 (100만 x 100만) 
    // for(int i=0 ; i<n ; i++){
    //     rbn.clear();
    //     for(int j=i+1 ; j<n ; j++){
    //         if(arr[i] < arr[j]) {
    //             rbn.push_back(arr[j]);
    //             // 가장 왼쪽 수를 찾으면 break 하게 하면 되지 않을까 -> 안됨
    //             break;
    //         }
    //     }
    //     if(rbn.size() == 0) cout << -1 << ' ';
    //     else cout << rbn.front() << ' ';
    // }

    // 시간 초과 어떻게 해결? dfs? stack?

    return 0;
}