#include <bits/stdc++.h>

using namespace std;

int N;
string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i=0 ; i<N ; i++) {
        // 단어의 길이 2 <= s <= 100,000
        cin >> s;
        stack<char> st;
        for(int j=0 ; j<s.size() ; j++) {
            if(st.empty()) {
                st.push(s[j]);
            } else {
                if(st.top() == s[j]) {
                    st.pop();
                } else {
                    st.push(s[j]);
                }
            }
        }
        if(st.empty()) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }   
    }


    return 0;
}