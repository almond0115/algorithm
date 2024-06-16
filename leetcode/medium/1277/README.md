## [[1277] Count Square Submatrices with All Ones](https://leetcode.com/problems/count-square-submatrices-with-all-ones/)

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

```
Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15

Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
```

```
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7

Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
```

## 제한 사항

1. 1 <= arr.length <= 300
2. 1 <= arr[0].length <= 300
3. 0 <= arr[i][j] <= 1

***

### 풀이 코드

- [@JongHyunJung](https://github.com/viaunixue/algorithm-study/blob/main/leetcode/medium/1277/jjh.py)

### TIL

* [1277 Count Square Submatrices with All Ones](https://almond0115.tistory.com/entry/LeetCode-1277-Count-Square-Submatrices-with-All-Ones)