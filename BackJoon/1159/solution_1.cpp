#include <bits/stdc++.h>

using namespace std;

int N, alphabet[26];
string s, ret;

int main() {
    cin >> N;

    for(int i=0 ; i<N ; i++) {
        cin >> s;
        // {String 값}[i] 으로 표현하면 char 값만 추출할 수 있다.
        alphabet[s[0] - 'a']++;
    }

    for(int i=0 ; i<26 ; i++) {
        if(alphabet[i] >= 5) {
            // ret 변수가 string 값이므로 아래 표현으로 ASCII 변환이 가능하다.
            ret += (i + 'a');
        }
    }

    if(ret.size()){
        cout << ret << '\n';
    } else {
        cout << "PREDAJA" << '\n';
    }

    return 0;
}