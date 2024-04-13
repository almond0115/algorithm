#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // n <= 10,000
    // 187 입력 -> 66666 출력?
    // 문제 이해 하기
    // 2 : 1666 -> 3 : 2666 -> 4 : 3666 -> 5 : 4666 -> 6 : 5666 -> 7 : 6660 
    // (?) why? n번째로 작은 종말의 수
    cin >>n;

    int num = 666;

    while(num) {
        if(to_string(num).find("666") != std::string::npos) {
            n--;
        }
        if(n == 0) {
            cout << num << '\n';
            break;
        }
        num++;
    }

    return 0;
}