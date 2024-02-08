#include <bits/stdc++.h>

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;

    int temp[N], sum[N-K+1], max;

    for(int i = 0; i < N; i++) {
        cin >> temp[i];
    }

    for(int i=0 ; i< N-K+1 ; i++) {
        sum[i] = 0;
        for(int j=i ; j<i+K ; j++) {
            sum[i] += temp[j];
        }
        if (max < sum[i]) max = sum[i];
    }

    cout << max << '\n';

    return 0;
}