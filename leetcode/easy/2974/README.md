## [[2974] Minimum Number Game](https://leetcode.com/problems/valid-parentheses/description/)

You are given a 0-indexed integer array nums of even length and there is also an empty array arr. 

Alice and Bob decided to play a game where in every round Alice and Bob will do one move. 

The rules of the game are as follows:

* Every round, first Alice will remove the minimum element from nums, and then Bob does the same.

* Now, first Bob will append the removed element in the array arr, and then Alice does the same.

* The game continues until nums becomes empty.

Return the resulting array `arr`.

## 제한 사항

* 2 <= nums.length <= 100

* 1 <= nums[i] <= 100

* nums.length % 2 == 0

***

### 풀이 코드

- [@JongHyunJung](https://github.com/viaunixue/algorithm-study/blob/main/leetcode/easy/2974/jjh.py)