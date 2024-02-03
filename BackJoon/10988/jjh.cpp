#include <bits/stdc++.h>

using namespace std;

string word;
int length, i, str[100];

int main() {
    cin >> word;
    length = word.length();

    for (char s: word) {
        str[i] = s;
        i++;
    }

    for (int i=0 ; i<length ; i++) {
        if (str[i] == str[length - i - 1]){
            if (i > length/2) break;
            continue;
        }
        cout << "0" << '\n';
        return 0;
    }
    cout << "1" << '\n';
    return 0;
}