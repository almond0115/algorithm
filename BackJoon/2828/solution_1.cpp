#include <bits/stdc++.h>

using namespace std;

int n, m, j, loc, l, r, ret;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> j;

    l = 1;

    for(int i=0 ; i<j ; i++){
        r = l + m -1;
        cin >> loc;
        if(loc >= l && loc <= r) continue;
        if(loc  < l){
            ret += l - loc;
            l = loc;
        } else {
            l += loc - r;
            ret += loc - r;
        }
    }

    cout << ret << '\n';

    return 0;
}