## split() 만들기 
***

**C++에서는 STL에서 split() 함수를 지원하지 않습니다.**

> split() 함수는 보통 다음과 같이 구현하고 **시간복잡도는 O(N)입니다.**
```c++
#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimiter){
    vector<string> ret;
    long long pos = 0;
    string token = "";

    while((pos = input.find(delimiter)) != string::npos){
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

int main() {
    string s = "abcdabc", d = "d";
    vector<string> a = split(s, d);
    for(string b : a) cout << b << "\n";
}

// 결과 값
// abc
// abc
```

* while 문 3줄만 외우면 됩니다.

