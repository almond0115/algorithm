#include <bits/stdc++.h>

using namespace std;

int h, w;
string s;
int arr[104][104];

int main() {
    cin >> h >> w;
    
    for(int i=0 ; i<h ; i++){
        cin >> s;
        for(int j=0 ; j<w ; j++){
            if(s[j] == 'c') arr[i][j] = 0;
            else arr[i][j] = -1;
        }
    }

    for(int i=0 ; i<h ; i++){
        for(int j=0 ; j<w ; j++){
            if(arr[i][j] == 0){
                int cnt = 1;
                while(arr[i][j+1] == -1){
                    // arr[i][j] += cnt + 1;
                    arr[i][j+1] = cnt++;
                    j++;
                }
            }
        }
    }

    for(int i=0 ; i<h ; i++){
        for(int j=0 ; j<w ; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}