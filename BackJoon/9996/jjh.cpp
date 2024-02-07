#include <bits/stdc++.h>

using namespace std;

int N, starPos;
string pattern, str[100], f, b, sf, sb;

int main() {
    cin >> N;
    // 소문자 여러개와 '*' 하나
    cin >> pattern;
    starPos = pattern.find('*');
    f = pattern.substr(0, starPos);
    b = pattern.substr(starPos+1);

    for(int i=0 ; i<N ; i++) {
        cin >> str[i];
        if(str[i].length() > 100){
            cout << "INVALID NAME" << '\n';
            return 0;
        }
    }

    for(int i=0 ; i<N ; i++) {
        sf = str[i].substr(0, f.length());
        sb = str[i].substr(str[i].length() - b.length());
        
        if(sf == f && sb == b) cout << "DA" << '\n';
        else cout << "NE" << '\n';
    }

    return 0;
}