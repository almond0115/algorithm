#include <bits/stdc++.h>

using namespace std;

int cnt[200], flag;
string str, ret;
char mid;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> str;
    
    for(char s : str) cnt[s]++;

    for(int j='Z' ; j >= 'A' ; j--) {
        if(cnt[j]) {
            // 홀수인 경우 
            if(cnt[j] & 1){       // 홀수라는 의미
                mid = char(j); 
                flag++;
                cnt[j]--;
            }
            if(flag == 2) break;
            for(int k=0 ; k<cnt[j] ; k += 2) {
                ret = char(j) + ret;
                ret += char(j);
            }
        }

        
    }
    
    if(mid) ret.insert(ret.begin() + ret.length() / 2, mid);
    if(flag == 2) cout << "I'm Sorry Hansoo \n";
    else cout << ret << '\n';   

    return 0;
}