#include <bits/stdc++.h>

using namespace std;

int n;
string s, pattern, pre, suf, p2, s2;

int main() {
    cin >> n;
    cin >> pattern;
    
    int pos = pattern.find("*");
    pre = pattern.substr(0, pos);
    suf = pattern.substr(pos + 1);

    for(int i=0 ; i< n ; i++) {
        cin >> s;

        // ab*ab 패턴일때 입력값 'ab'도 허용되는 것 방지하는 예외처리 필요함
        if(pre.size() + suf.size() > s.size()){
            cout << "NE" << '\n';
        } else {
            if(pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) {
                cout << "DA\n"; 
            } else {
                cout << "NE\n";
            }
        }
    }

    return 0;
}