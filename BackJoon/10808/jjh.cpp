#include <bits/stdc++.h>

using namespace std;

string s;
int cnt[26];

int main() {
    // 단어 S 입력
    cin >> s;

    for (char a : s) {
        cnt[a - 'a']++;
    }

    for (int i = 0 ; i < 26 ; i++) {
        cout << cnt[i] << " ";
    }

    return 0;
}