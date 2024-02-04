#include <bits/stdc++.h>

using namespace std;

int N, alphabet[26];
string fn[150];
char num, cnt;

int main() {
    cin >> N;
    
    for(int i=0 ; i<N ; i++) {
        cin >> fn[i];
        // 1. String 값을 받아서 char로 어떻게 변환하지?
        strcpy(&num, fn[i].substr(0, 1).c_str());
        alphabet[num - 'a']++;
    }

    for (int i=0 ; i<26 ; i++) {
        if(alphabet[i] >= 5) {
            // 2. ASCII 코드의 int 값을 어떻게 해당 숫자에 대응되는 문자로 변환하지?
            cout << char(i + 97);
            cnt++;
        } 
    }

    if(cnt == 0) cout << "PREDAJA" << '\n';

    return 0;
}