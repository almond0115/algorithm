#include <bits/stdc++.h>

using namespace std;

int n, m;
string name, catag;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    while(n--) {
        // 의상 종류만 저장
        map<string, int> type;
        cin >> m;
        for(int i=0 ; i<m ; i++) {
            cin >> name >> catag;
            type[catag]++;
        }

        // 경우의 수가 커질 수 있으므로 long long 권장 
        long long ret = 1;
        for(auto t : type) {
            // (의상의 종류 갯수 + 안 입는 경우(1))  
            ret *= ((long long) t.second + 1);
        }

        // 모두 안입는 경우 -1
        cout << ret - 1 << '\n';
    }
    return 0;
}