#include <bits/stdc++.h>

using namespace std;

int n, a[9];

int main(){
    int sum = 0, b[7], m = 0;

    for (int i=0 ; i < 9 ; i++){
        cin >> n;
        a[i] = n;
    }

    
    // 오름차순 정렬? 
    sort(a, a+9);

    cout << '\n' << endl;

    for (int j=0 ; j<9 ; j++) {
        cout << a[j] << endl;
    }
    
    // 키의 합은 100, 난쟁이 수는 7명
    while(m <= 6){
        if(sum > 100) {
            m++;
            continue;
        }
        sum += a[m];
        b[m] = a[m];
        m++;
    }

    cout << '\n' << endl;

    for (int j=0 ; j<7 ; j++) {
        cout << b[j] << endl;
    }

    return 0;
}