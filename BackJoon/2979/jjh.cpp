#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int start, finish;
int e_st, e_fin;
int n, ret;

// typedef pair<int, int> tm;
vector<pair<int, int>> v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c;

    for (int i=0 ; i<3 ; i++) {
        cin >> start >> finish;
        v.push_back(make_pair(start, finish));
        if (i==0 || e_st > start) e_st = start;
        if (e_fin < finish) e_fin = finish;
    }
    

    int num = e_fin - e_st + 1;
    int sum[num];
    for(int i=0  ; i<num ; i++) {
        sum[i] = 0;
    }

    for (int i=e_st ; i<=e_fin ; i++) {
        for (int j=0 ; j<3 ; j++){
            if(v[j].first <= i && v[j].second > i) {
                sum[n]++; 
            }
        }
        n++;
    }

    for(int i=0 ; i<e_fin ; i++) {
        cout << sum[i] << " ";
    }
    
    return 0;

    for (int i=0 ; i<e_fin ; i++) {
        if(sum[i] == 1) {
            ret += a;
        } else if(sum[i] == 2) {
            ret += b*2;
        } else if(sum[i] == 3) {
            ret += c*3;
        }
    }

    cout << ret << '\n';

    return 0;
}