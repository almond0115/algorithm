#include <bits/stdc++.h>
using namespace std;

int n, ret = -987654321;
string s;

int cal(int a, int b, char op){
    switch(op){
        case '+' : 
            a += b; break;
        case '-' : 
            a -= b; break;
        case '*' : 
            a *= b; break;
    }
    return a;
}

void dfs(int idx, int num){
    if(idx > n-1){
        ret = max(ret, num);
        return;
    }

    char op = (idx == 0) ? '+' : s[idx-1];

    if(idx + 2 < n){
        int brk = cal(s[idx] - '0', s[idx+2] - '0', s[idx+1]);
        dfs(idx+4, cal(num, brk, op));
    }

    dfs(idx+2, cal(num, s[idx] - '0', op));
}

int main(){
    cin >> n >> s;
    dfs(0, 0);
    cout << ret << '\n';
    return 0;
}