## [[9996] 한국이 그리울 떈 서버에 접속하지](https://www.acmicpc.net/problem/11655)
선영이는 이번 학기에 오스트레일리아로 교환 학생을 가게 되었다. 

호주에 도착하고 처음 며칠은 한국 생각을 잊으면서 즐겁게 지냈다. 몇 주가 지나니 한국이 그리워지기 시작했다. 

선영이는 한국에 두고온 서버에 접속해서 디렉토리 안에 들어있는 파일 이름을 보면서 그리움을 잊기로 했다. 매일 밤, 파일 이름을 보면서 파일 하나하나에 얽힌 사연을 기억하면서 한국을 생각하고 있었다.

어느 날이었다. 한국에 있는 서버가 망가졌고, 그 결과 특정 패턴과 일치하는 파일 이름을 적절히 출력하지 못하는 버그가 생겼다.

패턴은 알파벳 소문자 여러 개와 별표(*) 하나로 이루어진 문자열이다.

파일 이름이 패턴에 일치하려면, 패턴에 있는 별표를 알파벳 소문자로 이루어진 임의의 문자열로 변환해 파일 이름과 같게 만들 수 있어야 한다. 별표는 빈 문자열로 바꿀 수도 있다. 예를 들어, "abcd", "ad", "anestonestod"는 모두 패턴 "a*d"와 일치한다. 하지만, "bcd"는 일치하지 않는다.

패턴과 파일 이름이 모두 주어졌을 때, 각각의 파일 이름이 패턴과 일치하는지 아닌지를 구하는 프로그램을 작성하시오.

## 입력
첫째 줄에 파일의 개수 N이 주어진다. (1 ≤ N ≤ 100)

둘째 줄에는 패턴이 주어진다. 패턴은 알파벳 소문자와 별표(아스키값 42) 한 개로 이루어져 있다. 문자열의 길이는 100을 넘지 않으며, 별표는 문자열의 시작과 끝에 있지 않다.

다음 N개 줄에는 파일 이름이 주어진다. 파일 이름은 알파벳 소문자로만 이루어져 있고, 길이는 100을 넘지 않는다.

## 출력
총 N개의 줄에 걸쳐서, 입력으로 주어진 i번째 파일 이름이 패턴과 일치하면 "DA", 일치하지 않으면 "NE"를 출력한다.

참고로, "DA"는 크로아티어어로 "YES"를, "NE"는 "NO"를 의미한다.

***

### 풀이 코드

- [@JongHyunJung](https://github.com/almond0115/Algorithm-CodingTest/blob/main/BackJoon/9996/jjh.cpp)

### 풀이 개념

- [Exception 처리](https://github.com/almond0115/Algorithm-CodingTest/blob/main/BackJoon/9996/solution_1.cpp)

***

### 참고 링크

* [string값 split 하는 3가지 방법](https://almond0115.tistory.com/entry/C에서-문자열-자르기-3가지-방법)

* [C++에서 length() 와 size()의 차이](https://almond0115.tistory.com/entry/C에서-length와-size의-차이)