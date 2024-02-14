#include <bits/stdc++.h>

using namespace std;

int cnt[26], flag;
string str, ret;
char mid;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> str;
    
    for(char s : str) {
        cnt[s - 'A']++;
    }

    for(int j=25 ; j >= 0 ; j--) {
        if(cnt[j] == 0) continue;
        if(cnt[j]) {
            // 홀수가 2개 이상이면 펠린드롬 성립 불가
            if(cnt[j] % 2 != 0){ 
                mid = char(j + 'A'); 
                flag++;
                cnt[j + 'A']--;
            }
            if(flag == 2) break;

            // 입력 값 문자열 앞 뒤로 insert로 삽입
            for(int k=0 ; k<cnt[j] ; k += 2) {
                ret = char(j + 'A') + ret;
                ret += char(j + 'A');
            }
        }
    }

    // 홀수일 때 중간 값 언제 저장? 
    if(mid) ret.insert(ret.begin() + ret.length() / 2, mid);
    if(flag == 2) cout << "I'm Sorry Hansoo \n";
    else cout << ret << '\n';   

    return 0;
}