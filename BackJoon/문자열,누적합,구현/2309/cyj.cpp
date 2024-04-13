#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  using std::cout;
  using std::cin;
  const int SIZE = 9;
  int sum = 0;  // 모든 난쟁이들의 키의 합
  std::vector<int> heightList(SIZE);

  // 난쟁이 키 입력(100을 넘지 않으며 모두 다름)
  for (int i = 0; i < SIZE; i++) {
    cin >> heightList[i];
    sum += heightList[i];
  }

  // 리스트를 오름차순 정렬
  std::sort(heightList.begin(), heightList.end());

  for (int i = 0; i < SIZE; i++) {
    for(int j = i + 1; j < SIZE; j++){
      // 난쟁이 두 명의 키를 합한 값이 100 - sum값과 같다면
      if(sum - heightList[i] - heightList[j] == 100){
        // 그 두 명의 키를 빼고 출력
        for(int k = 0; k < SIZE; k++){
          if(k != i && k != j){
            cout << heightList[k] << "\n";
          }
        }
        return 0;
      }
    }
  }
}