## [[1282] Group the People Given the Group Size They Belong To](https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/)

There are n people that are split into some unknown number of groups. 

Each person is labeled with a unique ID from 0 to n - 1.

You are given an integer array groupSizes, where groupSizes[i] is the size of the group 

that person i is in. For example, if groupSizes[1] = 3, then person 1 must be in a group of size 3.

Return a list of groups such that each person i is in a group of size groupSizes[i].

Each person should appear in exactly one group, and every person must be in a group. 

If there are multiple answers, return any of them. 

It is guaranteed that there will be at least one valid solution for the given input.

## 제한 사항

1. groupSizes.length == n
2. 1 <= n <= 500
3. 1 <= groupSizes[i] <= n

***

### 풀이 코드

- [@JongHyunJung](https://github.com/viaunixue/algorithm-study/blob/main/leetcode/medium/1282/jjh.py)

### TIL

* [1282 Group the People Given the Group Size They Belong To](https://almond0115.tistory.com/entry/LeetCode-1282-Group-the-People-Given-the-Group-Size-They-Belong-To)