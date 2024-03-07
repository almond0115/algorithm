#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    string ret[n];
    for(int i=0 ; i<n ; i++){
        string str;
        stack<char> q;
        int l = 0, r = 0;
        cin >> str;
        for(int j=0 ; j<str.length() ; j++){
            if(str[j] == '(') {
                l++; q.push(str[j]);
                while(true){
                    if(j == str.length()) break;
                    if(q.size() && str[j+1] == ')') {
                        r++; q.pop();                     
                    } else if(str[j+1] == '(') {
                        l++; q.push(str[j+1]);
                    } else if(!q.size() && str[j+1] == ')'){
                        r++;
                    }
                    j++;
                }
                if(l == r && q.empty()) ret[i] = "YES";
                else ret[i] = "NO";
            } else if(str[j] == ')') {
                ret[i] = "NO";
                break;
            }
        }
    }

    for(string i : ret){
        cout << i << '\n';
    }

    return 0;
}