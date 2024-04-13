#include <bits/stdc++.h>

using namespace std;

// 1 <= A, B, C <= 2,147,483,647
long long A, B, C;
stack<int> rt;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B >> C;

    int n = A;

    for(int i=1 ; i<=B ; i++) {
        A *= n; 
        rt.push(A % C);
        cout << A << ": " << rt.top() << ' ';
    }
    cout << '\n';

    cout << rt.top() << '\n';

    return 0;
}