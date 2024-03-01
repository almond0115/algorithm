#include <bits/stdc++.h>

using namespace std;

string n;

bool pwd_reader(string pwd){
    cout << "enter pwd_reader" << '\n';
    int vowel = 0, consonant = 0;
    for(int i=0 ; i<pwd.length() ; i++){
        if(pwd[i] < 'a' || pwd[i] > 'z') break;
        cout << "pass a to z" << '\n';
        if(pwd[i] == 'a' || pwd[i] == 'e' || pwd[i] == 'i' || pwd[i] == 'o' || pwd[i] == 'u'){
            vowel++;
            consonant = 0;
        } else {
            consonant++;
            vowel = 0;
        }
        cout << "pass vowel, consonant test" << '\n';
        // if(i>=1 && (pwd[i] == pwd[i-1]) && (pwd[i] == 'e' || pwd[i] == 'o')) {
        //     cout << pwd[i-1] << pwd[i] << '\n';
        //     continue;
        // }
        // cout << "pass e, o test" << '\n';
        cout << "현재 i 값 : " << i << ", " << "pwd[i-1] : " << pwd[i-1] << ", " << "pwd[i] : " << pwd[i] << '\n';
        if(i>=1 && (pwd[i] == pwd[i-1])) {
            cout << "pwd[i] : " << pwd[i] << '\n';
            if(pwd[i] == 'e' || pwd[i] == 'o') {
                cout << "[e o]" << '\n';
                continue;
            }
            break;
        } 
        cout << "pass e, o test" << '\n';
        if(vowel == 3 || consonant == 3) break;
        cout << "pass dup test" << '\n';
        if(i == pwd.length() - 1) return 0;
    }
    return 1;
};

int main() {
    ios_base::sync_with_stdio(false);

    while(cin >> n){
        if(n == "end") break;
        if(n.length() >= 1 && n.length() <= 20) pwd_reader(n);
        if(pwd_reader(n)) {
            cout << "<" << n << "> " << "is acceptable." << '\n';
        } else  {
            cout << "<" << n << "> " << "is not acceptable." << '\n';
        }
    }

    return 0;
}