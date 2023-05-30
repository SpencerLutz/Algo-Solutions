class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0
        if n == 2:
            return 0 if nums[0] > nums[1] else 1
        mp = n//2
        if nums[mp] < nums[mp - 1]:
            return self.findPeakElement(nums[: mp])
        elif nums[mp] < nums[mp + 1]:
            return self.findPeakElement(nums[mp + 1 :]) + mp + 1
        else:
            return mp