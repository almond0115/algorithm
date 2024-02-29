#include <bits/stdc++.h>
#define pp pair<int, int>
using namespace std;

int n, c, tmp;
map<int, int> m;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 1 <= n <= 1,000
    // 1 <= c <= 1,000,000,000
    cin >> n >> c;

    for(int i=0 ; i<n ; i++) {
        cin >> tmp;
        m[tmp]++;
    }

    vector<pp> num(m.begin(), m.end());
    sort(num.begin(), num.end(), cmp);

    // for(pp final : num){
    //     cout << final.first << " ";
    // }

    for(int i=num.size() - 1 ; i>=0 ; i--) {
        for(int j=0 ; j<num[i].second ; j++){
            cout << num[i].first << " ";
        }
    }

    // for(int i=0 ; i<num.size() ; i++) {
    //     if()
    // }
    return 0;
}