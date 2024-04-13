// N : 1 ~ 10만 
// K : 1 ~ 10만 - 1
// 온도는 -100 ~ 100
// 온도의 합 "최대" WHEN? -> 구간합 prefix sum, psum[i] = psum[i-1] + a[i];
// 이 문제의 최솟값? <최악> -100 * (10만번) >> -1000만
// 최대값 어디서부터?

// 최댓값? 최솟값부터 >>> 최대값
// 최솟값? 최댓값부터 >>> 최소값

// ret = max(ret, value);
// ret = min(ret, value);

#include <bits/stdc++.h>

using namespace std;

string s;

int N, K, temp, psum[100001], ret = -10000004;

int main() {

    cin >> N >> K;

    for(int i=1; i<=N ; i++) {
        cin >> temp;
        psum[i] = psum[i-1] + temp;
    }

    for(int i=K ; i<=N ; i++) {
        ret = max(ret, psum[i] - psum[i - K]);
    }

    cout << ret << '\n';
    
    return 0;
}