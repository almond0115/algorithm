from typing import List


class Solution:
    def countSquare(self, matrix: List[List[int]]) -> int:
        # 정사각형 개수
        m, n = len(matrix), len(matrix[0])
        # dp는 각 위치에서 끝나는 최대 정사각형의 개수
        dp = [[0] * n for _ in range(m)]
        cnt = 0

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 1:
                    if i == 0 or j == 0:
                        dp[i][j] += 1
                    else:
                        dp[i][j] += min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                    cnt += dp[i][j]

        return cnt