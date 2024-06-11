from typing import List


class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def canShipInDays(weights, days, capacity):
            curr_weight = 0
            days_needed = 1
            for weight in weights:
                if weight + curr_weight > capacity:
                    curr_weight = 0
                    days_needed += 1
                curr_weight += weight

            return days_needed <= days 

        left, right = max(weights), sum(weights)

        while left < right:
            mid = (left + right) // 2
            
            if canShipInDays(weights, days, mid):
                right = mid
            else:
                left = mid + 1

        return left