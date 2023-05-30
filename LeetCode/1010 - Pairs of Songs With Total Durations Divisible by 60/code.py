class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        count = [0] * 60
        total = 0

        for s in time:
            total += count[-s % 60]
            count[s % 60] += 1

        return total