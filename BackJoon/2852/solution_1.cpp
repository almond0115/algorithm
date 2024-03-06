#include <bits/stdc++.h>
using namespace std;
#define prev nero

int n, p, score1, score2, sum1, sum2;
string t, prev;

string print(int ret){
    string h = "00" + to_string(ret / 60);
    string m = "00" + to_string(ret % 60);
    return h.substr(h.size() - 2, 2) + ":" + m.substr(m.size() - 2, 2); 
}

int changeToInt(string a){
    return stoi(a.substr(0, 2)) * 60 + stoi(a.substr(3, 2));
    // return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}

// 매개변수 &sum은 return 없이 해당 매개변수에 들어간 변수 값에 직접 값을 추가하는 방식
void go(int &sum, string s){
    sum += (changeToInt(s) - changeToInt(prev));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> p >> t;
        
        // string -> int
        if(score1 > score2) go(sum1, t);
        else if(score2 > score1) go(sum2, t);

        // 로직 순서 유의 (score1, score2 값 비교 후 증가 처리)
        p == 1 ? score1++ : score2++;
        prev = t;
    }

    if(score1 > score2) go(sum1, "48:00");
    else if(score2 > score1) go(sum2, "48:00");

    // int -> string
    cout << print(sum1) << '\n';
    cout << print(sum2) << '\n';

    return 0;
}