from typing import List


class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        answer = []
        while nums:
            a = min(nums)
            nums.remove(min(nums))
            b = min(nums) 
            nums.remove(min(nums))
            answer.append(b)
            answer.append(a)

        return answer