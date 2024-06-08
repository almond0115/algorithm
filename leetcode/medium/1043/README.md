## [[1043] Partition Array for Maximum Sum](https://leetcode.com/problems/partition-array-for-maximum-sum/)

Given an integer array `arr`, partition the array into (contiguous) subarrays of length at most k. 

After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. 

Test cases are generated so that the answer fits in a 32-bit integer.

Example 1: <br>
Input: arr = [1,15,7,9,2,5,10], k = 3 <br>
Output: 84 <br>
Explanation: arr becomes [15,15,15,9,10,10,10] <br>

Example 2: <br>
Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4 <br>
Output: 83 <br>

Example 3: <br>
Input: arr = [1], k = 1 <br>
Output: 1

## 제한 사항

1. 1 <= arr.length <= 500
2. 0 <= arr[i] <= 10^9
3. 1 <= k <= arr.length

***

### 풀이 코드

- [@JongHyunJung](https://github.com/viaunixue/algorithm-study/blob/main/leetcode/medium/1043/jjh.py)

### TIL

* [1043 Partition Array for Maximum Sum](https://almond0115.tistory.com/entry/LeetCode-1043-Partition-Array-for-Maximum-Sum)