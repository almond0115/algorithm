#include <bits/stdc++.h>

using namespace std;

int n, m, j, ret;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 1 <= m <= n <= 10
    cin >> n >> m;
    // 1 <= j <= 20
    cin >> j;
    int loc[j], ret[j-1];
    for(int i=0 ; i<j ; i++){
        cin >> loc[i];

        if(i >= 1){
            int size = abs(loc[i] - loc[i-1]);
            if(size % m == 0) {
                ret += size / m;
            } else {
                ret += size / m + 1;
            }
        }
    }

    cout << ret << '\n';

    return 0;
}