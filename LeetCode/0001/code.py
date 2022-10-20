class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_map = {}
        
        for i, n in enumerate(nums):
            if target - n in hash_map:
                return [i, hash_map[target - n]]
            else:
                hash_map[n] = i