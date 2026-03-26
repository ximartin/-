class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        counts = [0] * 20001 
        
        for num in nums:
            counts[num + 10000] += 1
      
        for i in range(20000, -1, -1):
            k -= counts[i]
            if k <= 0:
                return i - 10000
                