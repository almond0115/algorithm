#include <bits/stdc++.h>
using namespace std;

int n, ret = -987654321;
char s[20];
vector<int> num;
vector<char> oper;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int calc(int a, int b, char op){
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    if(op == '*') return a * b;
    return a;
}

void go(int idx, int p_num){
    if(idx == num.size() - 1){
        ret = max(ret, p_num);
        return;
    }

    go(idx+1, calc(p_num, num[idx+1], oper[idx]));

    if(idx+2 <= num.size() - 1){
        int tmp = calc(num[idx+1], num[idx+2], oper[idx+1]);
        go(idx+2, calc(p_num, tmp, oper[idx]));
    }
}

int main(){
    fastIO();

    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> s[i];
        if(i % 2 == 0) num.push_back(s[i] - '0');
        else oper.push_back(s[i]); 
    }
    go(0, num[0]);
    cout << ret << '\n';
    return 0;
}
