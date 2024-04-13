#include <bits/stdc++.h>
using namespace std;

int h, w;
string s;
int arr[104][104];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 1 <= h(세로), w(가로) <= 100
    cin >> h >> w;

    for(int i=0 ; i<h ; i++){
        for(int j=0 ; j<w ; j++){
            // 다 입력을 한 후 처리? 입력 하면서 처리?
            // 입력 하면서 처리가 가능한지 체크
            cin >> s;
            if(s == "c"){
                arr[i][j] = 0;
            } else if(s == "."){
                while(true){
                    if(j == 0) arr[i][j] = -1;
                    // 입력 값 이전의 값들을 체크하는테 반복문이 또 필요함
                    // -> 입력 하면서 처리 불가능 판단
                    if(j>0 && arr[i][j-1] == -1) arr[i][j] = -1;
                    else arr[i][j] = arr[i][j-1] + 1;
                    j++;
                }
            }
        }
    }

    // for(int i=0 ; i<h ; i++){
    //     cin >> s;
    //     for(int j=0 ; j<w ; j++){
    //         if(s[j] == 'c') arr[i][j] = 0;
    //         else arr[i][j] = -1;
    //     }
    // }

    // for(int i=0 ; i<h ; i++){
    //     for(int j=0 ; j<w ; j++){
    //         if(arr[i][j] == 0){
    //             int cnt = 1;
    //             while(arr[i][j+1] == -1){
    //                 arr[i][j+1] += cnt + 1;
    //                 cnt++; j++;
    //             }

    //         }
    //     }
    // }

    for(int i=0 ; i<h ; i++){
        for(int j=0 ; j<w ; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }    

    return 0;
}