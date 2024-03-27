## [[16637] 괄호 추가하기](https://www.acmicpc.net/problem/12869)
길이가 N인 수식이 있다. 수식은 0보다 크거나 같고, 9보다 작거나 같은 정수와 연산자(+, -, ×)로 이루어져 있다. 

연산자 우선순위는 모두 동일하기 때문에, 수식을 계산할 때는 왼쪽에서부터 순서대로 계산해야 한다. 

예를 들어, 3+8×7-9×2의 결과는 136이다.

수식에 괄호를 추가하면, 괄호 안에 들어있는 식은 먼저 계산해야 한다. 단, 괄호 안에는 연산자가 하나만 들어 있어야 한다.

예를 들어, 3+8×7-9×2에 괄호를 3+(8×7)-(9×2)와 같이 추가했으면, 식의 결과는 41이 된다. 
<br>
하지만, 중첩된 괄호는 사용할 수 없다. 즉, 3+((8×7)-9)×2, 3+((8×7)-(9×2))은 모두 괄호 안에 괄호가 있기 때문에, 올바른 식이 아니다.

수식이 주어졌을 때, 괄호를 적절히 추가해 만들 수 있는 식의 결과의 최댓값을 구하는 프로그램을 작성하시오. 

추가하는 괄호 개수의 제한은 없으며, 추가하지 않아도 된다.

## 입력
첫째 줄에 수식의 길이 N(1 ≤ N ≤ 19)가 주어진다. 둘째 줄에는 수식이 주어진다. 

수식에 포함된 정수는 모두 0보다 크거나 같고, 9보다 작거나 같다. 

문자열은 정수로 시작하고, 연산자와 정수가 번갈아가면서 나온다. 연산자는 +, -, * 중 하나이다. 

여기서 *는 곱하기 연산을 나타내는 × 연산이다. 항상 올바른 수식만 주어지기 때문에, N은 홀수이다.

## 출력
첫째 줄에 괄호를 적절히 추가해서 얻을 수 있는 결과의 최댓값을 출력한다. 정답은 2^31보다 작고, -2^31보다 크다.

***

### 풀이 코드

- [@JongHyunJung](https://github.com/almond0115/Algorithm-CodingTest/blob/main/BackJoon/16637/jjh.cpp)

### 모범 답안

- [Recursive Function & Prefix Sum](https://github.com/almond0115/Algorithm-CodingTest/blob/main/BackJoon/16637/solution_1.cpp)

- [DFS](https://github.com/almond0115/Algorithm-CodingTest/blob/main/BackJoon/16637/solution_2.cpp)

***

### 참고 자료

* [C++에서 누적합 구하기](https://almond0115.tistory.com/entry/C에서-누적합-구하기)

* [Depth First Search](https://almond0115.tistory.com/entry/DFS-Depth-First-Search-이란)