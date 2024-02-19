#include <bits/stdc++.h>

using namespace std;

int n, m, a[15001], cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0 ; i<n ; i++) cin >> a[i];

    // 갑옷 만드는데 필요한 수 (1<= m <= 10,000,000) 이므로 예외처리
    if(m > 200000) cout << 0 << '\n';
    else {
        // 이 반복문만 제출해도 정답
        for(int i=0 ; i < n ; i++) {
            for(int j = i+1 ; j < n ; j++) {
                if(a[i] + a[j] == m) cnt ++;
            }
        }

        cout << cnt << '\n';
    }
    
    return 0;
}