#include <bits/stdc++.h>
using namespace std;

int a[9];
int n=9, r=7;

void solve() {
    int sum = 0;
    for(int i=0; i<r ; i++) {
        sum += a[i];
    }

    if (sum == 100) {
        cout << "\n";
        sort(a, a+7);
        for (int i=0 ; i<r ; i++) cout << a[i] << "\n";
        // return 과 다르게 exit은 전체 함수를 종료
        exit(0);
    }

}

// void print() {
//     for (int i=0 ; i<r ; i++) cout << a[i] << " ";
//     cout << '\n';
// }

// 재귀 함수로 만든 순열
void makePermutation(int n, int r, int depth) {
    if(depth == r) {
        // print();
        solve();
        return;
    }
    for(int i=depth ; i<n ; i++){
        swap(a[i], a[depth]);
        makePermutation(n, r, depth+1);
        swap(a[i], a[depth]);
    }
    return;
}

int main() {
    for(int i=0 ; i<n ; i++) {
        cin >> a[i];
    }
    makePermutation(n, r, 0);
    return 0;
}