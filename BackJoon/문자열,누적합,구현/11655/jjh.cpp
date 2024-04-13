#include <bits/stdc++.h>

using namespace std;

string str, ret;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // cin >> str;
    // getline() 으로 공백 처리
    getline(cin, str);

    for(char s : str) {
        if('a' <= s && 'z' >= s) {
            if(s <= 'a' + 12) ret += (s + 13);
            else if(s > 'a' + 12) ret += (s - 13); 
        } else if('A' <= s && 'Z' >= s) {
            if(s <= ('A' + 12)) ret += (s + 13);
            else if(s > ('A' + 12)) ret += (s - 13);
        } else {
            ret += s;
        }
    }

    cout << ret << '\n';

    return 0;
}