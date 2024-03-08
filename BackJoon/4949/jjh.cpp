#include <bits/stdc++.h>
using namespace std;

string str;

bool check(string n){
    stack<char> stk;
    vector<char> tmp;
    for(int i=0 ; i<n.length() ; i++){  
        if(n[i] == '.') break;
        if(n[i] == '(' || n[i] == '['){
            cout << "n[i] : " << n[i] << endl;
            stk.push(n[i]);
            tmp.push_back(n[i]);
        } else if(n[i] == ')'){
            cout << "tmp : " << tmp.back() << endl;
            if(!stk.empty() && tmp.back() == '(') {
                stk.pop(); 
                tmp.pop_back();
            } else {
                return false;
            }
        } else if(n[i] == ']'){
            cout << "tmp[i-1] : " << tmp.back() << endl;
            if(!stk.empty() && tmp.back() == '[') {
                stk.pop(); 
                tmp.pop_back();
            }
            else {
                return false;
            }
        }
    }
    return stk.empty();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while(getline(cin, str)){
        if(str == ".") break;
        if(check(str)) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}