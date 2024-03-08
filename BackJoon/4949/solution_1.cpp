#include <bits/stdc++.h>
using namespace std;

string str;

bool check(string n){
    stack<char> stk;
    for(int i=0 ; i<n.length() ; i++){
        if(n[i] == '.') break;
        if(n[i] == '(' || n[i] == '['){
            stk.push(n[i]);
        } else if(n[i] == ')'){
            if(!stk.empty() && stk.top() == '(') stk.pop();
            else return false;
        } else if(n[i] == ']'){
            if(!stk.empty() && stk.top() == '[') stk.pop();
            else return false;
        }
    }
    return stk.empty();
}

int main() {

    while(getline(cin, str)){
        if(str == ".") break;
        if(check(str)) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}