#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, cnt;
ll n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    int ret[t];
    for(int i=0 ; i<t ; i++){
        // 1 <= n <= 10억
        cin >> n;
        for(int j=5 ; j<n ; j*=5){
            cnt += n/j;
        }
        ret[i] = cnt;
        cnt = 0;
    }

    for(int i : ret){
        cout << i << '\n';
    }

    return 0;
}