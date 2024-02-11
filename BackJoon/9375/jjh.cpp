#include <bits/stdc++.h>

using namespace std;

// n : 의상 갯수
// m : 의상 개수
int n, m[30], ret;
string name;
vector<string> clothes, word;

// 입력 값 : 의상 갯수 n, 의상 개수 m, 의상 이름 name, 의상 종류 type 
// -> getline 쓸 필요 없다. 접근 방식에서 이미 fail
// 경우의 수로 접근하기 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0 ; i<n ; i++) {
        cin >> m[i];
        // m[i] 입력받은 후 남은 개행 문자 처리
        string bufferflush;
        getline(cin, bufferflush);
        
        for(int j=0 ; j<m[i] ; j++) {
            getline(cin, name);
            clothes.push_back(name);
        }

        for(int k=0 ; k<m[i] ; k++) {
            string tmp = split(clothes[k], " ");
            cout << tmp << endl;
            word.push_back(tmp);   
        }

        clothes_count(word, m[i]);
    }

    return 0;
}