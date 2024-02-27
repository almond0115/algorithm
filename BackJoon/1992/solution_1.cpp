#include <bits/stdc++.h>

using namespace std;

const int max_n = 65;
int n;
string s;
char arr[max_n][max_n];

string quard_tree(int y, int x, int size){
    if(size == 1) return string(1, arr[y][x]);
    string ret = "";
    char tmp = arr[y][x];
    for(int i=y ; i<y+size ; i++){
        for(int j=x ; j<x+size ; j++){
            if(arr[i][j] != tmp){
                ret += '(';
                ret += quard_tree(y, x, size/2);
                ret += quard_tree(y, x+size/2, size/2);
                ret += quard_tree(y+size/2, x, size/2);
                ret += quard_tree(y+size/2, x+size/2, size/2);
                ret += ')';

                return ret;  
            }
        }
    }
    // arr[y][x] 에 해당하는 문자 하나로 이루어진 문자열을 생성하여 반환
    return string(1, arr[y][x]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0 ; i < n ; i++) {
        cin >> s;
        for(int j=0 ; j < n ; j++) {
            arr[i][j] = s[j];
        }
    }

    cout << quard_tree(0, 0, n) << '\n';

    return 0;
}