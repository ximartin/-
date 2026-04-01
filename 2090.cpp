class Solution:
    def getAverages(self, nums, k):
        n = len(nums)
        res = [-1] * n
        
        window_size = 2 * k + 1
        if window_size > n:
            return res
        
        window_sum = sum(nums[:window_size])
        res[k] = window_sum // window_size
        
        for i in range(window_size, n):
            window_sum += nums[i]
            window_sum -= nums[i - window_size]
            
            center = i - k
            res[center] = window_sum // window_size
        
        return res