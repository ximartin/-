class Solution:
    def sortArray(self, nums):
        self.temp = [0] * len(nums)   # 只建立一次
        self.merge_sort(nums, 0, len(nums) - 1)
        return nums

    def merge_sort(self, nums, left, right):
        if left >= right:
            return
        
        mid = (left + right) // 2
        
        self.merge_sort(nums, left, mid)
        self.merge_sort(nums, mid + 1, right)

        if nums[mid] <= nums[mid + 1]:
            return

        self.merge(nums, left, mid, right)

    def merge(self, nums, left, mid, right):
        i = left
        j = mid + 1
        k = left

        while i <= mid and j <= right:
            if nums[i] <= nums[j]:
                self.temp[k] = nums[i]
                i += 1
            else:
                self.temp[k] = nums[j]
                j += 1
            k += 1

        while i <= mid:
            self.temp[k] = nums[i]
            i += 1
            k += 1

        while j <= right:
            self.temp[k] = nums[j]
            j += 1
            k += 1

        for t in range(left, right + 1):
            nums[t] = self.temp[t]