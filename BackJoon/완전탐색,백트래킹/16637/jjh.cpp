#include <bits/stdc++.h>
using namespace std;

int n, ret = -987654321;
string s;
vector<int> num;
vector<char> oper_str;

int oper(char a, int b, int c){
    if(a == '+') return b+c;
    if(a == '-') return b-c;
    if(a == '*') return b*c;
    return b;
}

// here : 현재 인덱스
// _num : 누적합 
void go(int here, int _num){
    // 완전 탐색은 반드시 기저 사례 구현
    if(here == num.size() - 1){
        ret = max(ret, _num);
        return;
    }


    go(here + 1, oper(oper_str[here], _num, num[here + 1]));

    if(here + 2 <= num.size() - 1){
        int temp = oper(oper_str[here + 1], num[here + 1], num[here + 2]);
        go(here + 2, oper(oper_str[here], _num, temp));
    }
}

// 어떻게 누적합으로 구현? 
// 완전 탐색으로 풀이 시 "인덱스 기반"으로 로직을 구성해야 함
int main(){
    // 1 <= n <= 19
    // Stack? DFS? 누적합?
    // 괄호 처리는 이전의 연산 값에 이번의 값을 연산하는 누적합
    cin >> n >> s;
    // 먼저 연산자와 숫자 별도 처리 필요
    for(int i=0 ; i<n ; i++){
        if(i % 2 == 0) num.push_back(s[i] - '0');
        else oper_str.push_back(s[i]);
    }

    // 완전 탐색, 누적합 & 재귀 방식 풀이
    go(0, num[0]);
    cout << ret << '\n';

    return 0;
}