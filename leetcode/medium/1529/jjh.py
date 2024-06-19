import sys
sys.setrecursionlimit(10 ** 6)

# 시간 초과
class Solution:

    def minFlip_1(self, target: str) -> int:
        result = float("inf")

        def dfs(num, s, target, n):
            nonlocal result
            if s == target:
                result = min(result, num)
                return result

            for i in range(num, n):
                flipped = s[:i] + ''.join('1' if x == '0' else '0' for x in s[i:])
                dfs(num+1, flipped, target, n)

        n = len(target)
        s = "0" * n
        dfs(0, s, target, n)
        return result 
    
    def minFlip_2(self, target: str) -> int:
        cnt = 0
        status = '0'

        for ch in target:
            if status != ch:
                cnt += 1
                status = '0' if stat == '1' else '1'

        return cnt
    


