## 메모리와 포인터

### 메모리와 주소

![1  메모리와 주소](https://github.com/almond0115/algorithm-study/assets/77084379/c84cfbf6-ac22-49aa-a183-381ef6b72a04)

```c++
#include <bits/stdc++.h>
using namespace std;
int i;

int main() {
    cout << &i << '\n';
}

// 결과 값
// 0x100ea4000
```
**메모리 주소는 OS, 실행시간 등에 따라 달라짐**

```c++
#include <bits/stdc++.h>
using namespace std;
int i;

int main() {
    cout << &i << '\n';
    i = 0;
    cout << &i << '\n';
}

// 결과 값
// 0x100ea4000
// 0x100ea4000
```

**변수에 값을 할당하기 전과 후의 주소 값이 동일함**

### 포인터

![2  포인터](https://github.com/almond0115/algorithm-study/assets/77084379/b720370b-7288-4886-9eaf-b6b92a49ffa0)

> **자바, 파이썬 자바스크립트는 개발자가 직접 변수에 메모리를 할당하거나 해제할 수 없음**
&rarr; 가비지 컬렉터 사용

> **하위레벨 언어인 C, C++ 등은 가비지 컬렉터가 없고 직접 필요한 메모리를 예약하고 해제함**

#### 포인터 : 메모리의 주소를 가리키는 타입이며 변수의 첫번째 Byte 주소를 가리킨다

`메모리 동적할당, 데이터를 복사하지 않고 함수 매개변수로 사용, 클래스 및 구조체 연결 시 사용함`

```c++
#include <bits/stdc++.h>
using namespace std;
int a = 4;
double b = 4.4;
int main() {
    <타입> * <변수명> = <해당 타입의 변수명 주소>
    int *b = &a;
    double *c = &b;
```
* C++ 에서 * 라는 별표는 `에스터리스크 (asterisk operator)`라고 불립니다.

```c++
#include <bits/stdc++.h>
using namespace std;

double a = 4.4;
int c = 10;
int main() {
    double *b = &a;
    int *d = &c;
    cout << sizeof(b) << '\n';
    cout << sizeof(d) << '\n';
}

// 결과 값
// 8
// 8
```
`포인터의 크기는 실행 OS 체제의 bit 마다 다름`
<br> &rarr; 만약에 64bit 위에서 실행한다면 무조건 8 byte

### 역참조 연산자

![3  역참조 연산자](https://github.com/almond0115/algorithm-study/assets/77084379/1b0d36dc-4648-4f77-8dce-66b1fe723395)

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    string a = "almond";
    string *b = &a;
    cout << b << '\n';
    cout << *b << '\n';
    return 0;
}

// 결과 값
// 0x16d632f40
// almond
```

### Array to Pointer 

![4  array to pointer](https://github.com/almond0115/algorithm-study/assets/77084379/7f07cda0-2a10-4eda-804d-cef67fd065c2)

```c++
#include <bits/stdc++.h>
using namespace std;
int a[3] = {1, 2, 3};
int main() {
    int *c = a;
    cout << c << "\n";
    cout << &a[0] << "\n";
    cout << c + 1 << "\n";
    cout << &a[1] << "\n";
    return 0;
}

// 결과 값
// 0x100424000
// 0x100424000
// 0x100424004
// 0x100424004
```



