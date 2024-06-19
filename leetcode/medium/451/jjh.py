from collections import defaultdict

class Solution:
    def frequencySort(self, s: str) -> str:
        s_cnt = defaultdict(int)
        for alph in s:
            s_cnt[alph] += 1

        max_cnt = - float('inf')
        result = ""

        # 내림차순 정렬
        s_cnt = sorted(s_cnt.items(), key=lambda x: x[1], reverse=True)

        # 조건에 맞게 정렬
        for key, value in s_cnt:
            result  += key * value
        
        return result