## 조합으로 만드는 조합
***
```c++
#include <bits/stdc++.h>
using namespace std;

int n = 5, k = 3, a[5] = {1, 2, 3, 4, 5};
void printC(vector<int> b){
	for(int i : b) cout << i << " ";
	cout << "\n";
}

void combi(int start, vector<int> b){
	if(b.size() == k){
		printC(b);
		return;
	}
	
	for(int i = start + 1; i<n ; i++){
		b.push_back(i);
		combi(i,b);
		b.pop_back();
	}
	return;
}

int main(){
	vector<int> b;
	combi(-1, b);
	return 0;
}
```
> 재귀함수로 만든 조합 도식화

![combination_0](https://github.com/almond0115/algorithm/assets/77084379/1731d520-0027-4927-a9e7-1e6b03583569)

> 결과 값

<img width="712" alt="스크린샷 2023-09-15 20 35 20" src="https://github.com/almond0115/algorithm/assets/77084379/1ef45f77-dc2c-4c34-b36e-4595a2f9bf7a">

<br>

## 중첩 for 문으로 만드는 조합

> k 가 작을 때 이렇게 구현하는 게 효율적임

**만약 여기서 k가 10 이거나 20 이라면 재귀함수가 효율적**

```c++
#include <bits/stdc++.h>
using namespace std;

int n = 5, k = 3, a[5] = {1, 2, 3, 4, 5};

int main(){
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<i ; j++){
			for(int k=0 ; k<j ; k++){
				cout << i << " " << j << " " << k << '\n';
			}
		}
	}
	return 0;
}
```
<br>

```c++
#include <bits/stdc++.h>
using namespace std;

int n = 5, k = 3, a[5] = {1, 2, 3, 4, 5};

int main(){
	for(int i=0 ; i<n ; i++){
		for(int j=i+1 ; j<n ; j++){
			for(int k=j+1 ; k<n ; k++){
				cout << i << " " << j << " " << k << '\n';
			}
		}
	}
	return 0;
}
```

### 만약에 두 개를 뽑는다면? <br>
**3중 -> 2중 for문으로 바꾸면 됨**