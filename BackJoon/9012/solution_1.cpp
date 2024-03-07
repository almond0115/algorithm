#include <bits/stdc++.h>
using namespace std;

int n;

bool check(int n){
    string str;
    stack<char> stk;
    cin >> str;
    for(int i=0 ; i<str.length() ; i++){
        if(str[i] == '('){
            stk.push(str[i]);
        } else {
            if(!stk.empty()) stk.pop();
            else return false;
        }
    }
    return stk.empty();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for(int i=0 ; i<n ; i++){
        if(check(n)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}