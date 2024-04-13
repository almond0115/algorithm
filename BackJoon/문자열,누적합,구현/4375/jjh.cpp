#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    
    // 1 <= n <= 10000
    cin >> n;
    
    while(n) {
        int num = 0;
        for(int i=0 ; ; i++) {
            num = (num * 10) + 1;
            if(num % n == 0) {
                cout << i+1 << '\n';
                break;
            } else {
                num = num % n;
            }
        }
        cin >> n;
    }

    return 0;
}