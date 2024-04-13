#include <bits/stdc++.h>
#define max_n 1000004
using namespace std;

int n, m;
int arr[max_n], ret[max_n];
stack<int> stk;

int main(){
    cin >> n;

    // 자기 자신이 가장 큰 경우 -1이므로 전체 -1로 미리 치환
    memset(ret, -1, sizeof(ret));
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
        // 스택 내부에 비교할 인덱스 값이 존재해야 함
        // 스택 가장 위에 저장된 인덱스의 배열 값과 비교 대상인 다음 인덱스의 배열 값 비교하기
        while(stk.size() && arr[stk.top()] < arr[i]){
            // 다음 인덱스의 배열 값이 더 크면 스택 가장 위에 저장된 인덱스의 배열 값 저장하기
            ret[stk.top()] = arr[i];
            // 비교가 끝난 인덱스 pop
            stk.pop();
        }

        // 스택에 비교할 배열 값의 인덱스 저장
        stk.push(i);
    }

    for(int i=0 ; i<n ; i++) cout << ret[i] << ' ';
    return 0;

}