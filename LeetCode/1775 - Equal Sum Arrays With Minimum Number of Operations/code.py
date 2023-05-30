class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        n1 = len(nums1)
        n2 = len(nums2)
        if n1 * 6 < n2 or n2 * 6 < n1:
            return -1

        s1 = sum(nums1)
        s2 = sum(nums2)
        diff = abs(s2 - s1)
        if diff == 0:
            return 0

        if s1 < s2:
            low = nums1
            high = nums2
        else:
            low = nums2
            high = nums1
        values = [6 - l for l in low] + [h - 1 for h in high]
        values.sort(reverse=True)

        total = 0
        for v in values:
            diff -= v
            total += 1
            if diff <= 0:
                return total
        
        return -1