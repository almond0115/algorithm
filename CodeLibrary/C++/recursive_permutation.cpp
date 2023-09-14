#include <bits/stdc++.h>
using namespace std;
vector<int> v;

void printV(vector<int> &v){
    for(int i=0 ; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

void makePermutations(int n, int r, int depth) {
    cout << n << " : " << r << " : " << depth << '\n';
    if(r == depth){
        printV(v);
        return;
    }

    for(int i=0 ; i<n ; i++){
        swap(v[i], v[depth]);
        makePermutations(i, r, depth+1);
        swap(v[i], v[depth]);
    }
    return;
}

int main(){
    for(int i=1 ; i <= 3 ; i++) v.push_back(i);
    makePermutations(3, 3, 0);
    return 0;
}