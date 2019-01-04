class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        result = 1
        for i in range(len(nums)):
            #直到遇到第一个正数
            if nums[i] < 1:
                continue
            #遇到和前面相同的:
            if i > 0 and nums[i] == nums[i-1]:
                continue
            #是否出现应该匹配的数
            if nums[i] == result:
                result += 1
            else:
                break
        return result