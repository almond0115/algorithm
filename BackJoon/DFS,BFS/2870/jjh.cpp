#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> num;

int int_width(int num)
{
    int ret;
    if (num < 0) num = -num;
    for (ret = 0; num > 0; num /= 10, ret ++) /* NULL */;
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 1 <= n <= 100
    cin >> n;
    for(int i=0 ; i<n ; i++){
        string st; 
        cin >> st;

        // cout << "[st] : " << st << '\n';

        for(int j=0 ; j<st.length() ; j++){
            // 각각의 s[j]는 char 타입이다
            // string 타입으로 일정 범위의 char 값들을 합치려면 어떻게 해야하는지?
            if(isdigit(st[j])){
                // st[j]가 0일때 stoi(&st[j]) 값은 1이므로 조건문 추가
                if(st[j] == '0' && isdigit(st[j+1])) continue;
                int idx = stoi(&st[j]);
                // cout << "[idx] : " << idx << '\n';

                // stoi 함수는 주소값으로 값을 받아 전체 숫자로 변환
                // 값이 숫자로만 이루어져있다면 어떻게 처리하지?
                 int st_length = int_width(idx);
                // cout << "[st_length] : " << st_length << '\n';
                // cout << "[st.length()] : " << st.length() << '\n';
                 if(st_length == st.length()) {
                    num.push_back(idx);
                    break;
                 }

                while(isdigit(st[j+1])){
                    // idx = idx*10 + stoi(&st[j+1]);
                    // cout << "[stoi] : " << stoi(&st[j+1]) << '\n';
                    // cout << "[while] : "<< idx << '\n';
                    j++;
                }
                // cout << "while out" << '\n';
                num.push_back(idx);
            }

        }
    }

    sort(num.begin(), num.end());

    for(int i : num){
        cout << i << '\n';
    }

    return 0;
}