#include <bits/stdc++.h>

using namespace std;

int a[9];

int main() {
    // 난쟁이 키 입력
    for(int i=0 ; i<9 ; i++) {
        cin >> a[i];
    }
    
    // 저장된 배열 오름차순 정렬
    sort(a, a+9);
    cout << '\n';

    // 순열에 따른 반복문 진행
    do {
        for (int i : a) cout << i << " ";
        cout << '\n';

        int sum = 0;
        for (int i=0 ; i<7 ; i++) sum += a[i];

        if (sum == 100) break; 
    } while(next_permutation(a, a+9));

    cout << '\n';

    for (int i=0 ; i<7 ; i++) {
        cout << a[i] << endl;
    }

    return 0;
}