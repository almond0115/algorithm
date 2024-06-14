## [[1476] Subrectangle Queries](https://leetcode.com/problems/subrectangle-queries/)

Implement the class SubrectangleQueries which receives a rows x cols rectangle 

as a matrix of integers in the constructor and supports two methods:

1. updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)

Updates all values with newValue in the subrectangle

whose upper left coordinate is (row1,col1) and bottom right coordinate is (row2,col2).

2. getValue(int row, int col)

Returns the current value of the coordinate (row,col) from the rectangle.


## 제한 사항

1. There will be at most 500 operations considering both methods: updateSubrectangle and getValue.
2. 1 <= rows, cols <= 100
3. rows == rectangle.length
4. cols == rectangle[i].length
5. 0 <= row1 <= row2 < rows
6. 0 <= col1 <= col2 < cols
7. 1 <= newValue, rectangle[i][j] <= 10^9
8. 0 <= row < rows
9. 0 <= col < cols

***

### 풀이 코드

- [@JongHyunJung](https://github.com/viaunixue/algorithm-study/blob/main/leetcode/medium/1476/jjh.py)

### TIL

* [1476 Subrectangle Queries](https://almond0115.tistory.com/entry/)