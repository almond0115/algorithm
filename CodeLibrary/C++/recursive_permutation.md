## 재귀함수로 만드는 순열
***
```c++
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

    for(int i=depth ; i<n ; i++){
        swap(v[i], v[depth]);
        makePermutations(n, r, depth+1);
        swap(v[i], v[depth]);
    }
    return;
}

int main(){
    for(int i=1 ; i <= 3 ; i++) v.push_back(i);
    makePermutations(3, 3, 0);
    return 0;
}
```
> 재귀함수로 만든 순열 도식화

![permutation_0](https://github.com/almond0115/algorithm/assets/77084379/73754e68-ef8f-4817-9f2f-71b3fa77fb3b)

> 결과 값

<img width="734" alt="스크린샷 2023-09-15 18 51 59" src="https://github.com/almond0115/algorithm/assets/77084379/9520fd88-cd19-43f1-a71e-185846010bf1">

* 재귀 함수를 통한 순열 구현 방법도 유용하지만 실제 문제에서는
nextPermutation() 함수 사용 후 do while 문으로 해결하는게 빠름 