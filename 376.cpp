from typing import List

class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if not nums:
            return 0

        count = 1
        Diff = 0

        for i in range(1, len(nums)):
            diff = nums[i] - nums[i - 1]

            if (diff > 0 and Diff <= 0) or (diff < 0 and Diff >= 0):
                count += 1
                Diff = diff

        return count      