## 중복된 요소 제거하는 방법과 unique()

### Map 을 통한 중복 제거

```c++
#include<bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main(){
    vector<int> v{1,1,2,2,3,3};
    
    for(int i : v) {
        if(mp[i]){
            continue;
        } else {
            mp[i] = 1;
        }
    }
    vector<int> ret;
    for(auto it : mp){
        ret.push_back(it.first);
    }

    for(int i : ret) cout << i << endl;
}

// result
// 1, 2, 3
```

### unique() 통한 중복 제거

* 범위 안의 있는 요소 중 앞에서부터 서로 비교해가며 중복되는 요소를 제거하고 <br> 
나머지 요소들은 삭제하지 않고 그대로 두는 함수입니다. **O(n)의 시간 복잡도를 가집니다.**

```c++
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
    for(int i=1 ; i<=5 ; i++) {
        v.push_back(i);
        v.push_back(i);
    }
    for(int i : v) cout << i << " ";
    cout << '\n';
    // 중복되지 않은 요소로 채운 후, 그 다음 iterator를 반환
    auto it = unique(v.begin(), v.end());
    cout << it - v.begin() << '\n';
    // 앞에서부터 중복되지 않게 채운 후 나머지 요소들은 그대로 둠
    for(int i : v) cout << i << " ";
    cout << '\n';
    return 0;
}

// result
// 1 1 2 2 3 3 4 4 5 5 
// 5
// 1 2 3 4 5 3 4 4 5 5
```

`unique() 쓸 경우 꼭 sort()와 같이 사용해야 합니다`
<br>
&rarr; sort()를 써야 "우리가 예상하는 로직"인 중복된 수를 제거한 배열이 나옴

```c++
#include<bits/stdc++.h>
using namespace std;
vector<int> v {2, 2, 1, 1, 2, 2, 3, 3, 5, 6, 7, 8, 9};
int main() {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i: v) cout << i << " ";
    cout << '\n';
    return 0;
}
```
* erase 를 통해 unique() 처리 이후 나머지 값들 삭제