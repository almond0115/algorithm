from typing import List
from collections import defaultdict

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        answer = defaultdict(int)
        result = set()

        for num in nums:
            answer[num] += 1
        
        answer = sorted(answer.items(), key=lambda x:x[1], reverse=True)

        cnt = 0
        for key, value in answer:
            if cnt == k:
                break
            cnt += 1
            result.add(key)

        return result 