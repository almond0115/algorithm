#include <bits/stdc++.h>
using namespace std;

const int max_n = 65;
// const int dy[] = {0, 1, 0, -1};
// const int dx[] = {1, 0, -1, 0};
int n, ny, nx;
int arr[max_n][max_n], visited[max_n][max_n];

void quard_tree(int n){
    // 압축 유무
    int num[n], cnt = 0, sum = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(arr[i][j] == 1){
                num[cnt] = 1;
                sum++; cnt++;
            } else if(arr[i][j] == 0){
                num[cnt] = 0;
                cnt++;
            }
        }
    }
    if(sum == n*n){
        cout << 1;
    } else if(sum == 0){
        cout << 0;
    } else {
        cout << '(';
        quard_tree(n/2);
        cout << ')';
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 1 <= n <= 64, n은 2의 제곱수
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    cout << '(';
    quard_tree(n);
    cout << ')';

    return 0;
}