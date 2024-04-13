#include <bits/stdc++.h>
using namespace std;

int n, p, tm, prev_team = -1, prev_time, t1, t2, s1, s2;
string t;
map<int, int> score;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 1 <= n <= 100
    cin >> n;
    for(int i=0 ; i<n ; i++){
        // 득점 팀 번호(1 or 2), 득점 시간(MM:SS)
        cin >> p >> t;
        
        if (p == 1) s1++;
        else if (p == 2) s2++;

        tm = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));

        if(i == n-1 && s1 > s2){
            t1 += 48 * 60 - tm; 
            continue;
        } else if(i == n-1 && s2 > s1) t2 += 48 * 60 - tm; continue;

        if(i>0 && s1 > s2){
            if(prev_team == 0) {
                prev_team = 1;
                prev_time = tm;
                continue;
            }
            t1 += tm - prev_time;
        } else if (i>0 && s2 > s1){
            if(prev_team == 0) {
                prev_team = 2;
                prev_time = tm;
                continue;
            }
            t2 += tm - prev_time;
        } else if (i>0 && s1 == s2){
            if(prev_team == 1){
                t1 += tm - prev_time;
            } else if(prev_team == 2){
                t2 += tm - prev_time;
            }
        }

        // score.insert(make_pair(stoi(tm, p));
        if(s1 > s2){
            prev_team = 1;
        } else if(s2 > s1){
            prev_team = 2;
        } else if(s1 == s2){
            prev_team = 0;
        }

        prev_time = tm; 
    }

    int h1 = t1 / 60;
    int m1 = t1 - (h1 * 60);

    int h2 = t2 / 60;
    int m2 = t2 - (h2 * 60);

    cout << h1 << ":" << m1 << '\n';
    cout << h2 << ":" << m2 << '\n';

    return 0;
}