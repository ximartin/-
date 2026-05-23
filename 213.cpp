from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)

        if n == 1:
            return nums[0]

        def rob_line(arr: List[int]) -> int:
            prev2 = 0
            prev1 = 0

            for money in arr:
                curr = max(prev1, prev2 + money)
                prev2 = prev1
                prev1 = curr

            return prev1

        return max(
            rob_line(nums[:-1]),
            rob_line(nums[1:])
        )