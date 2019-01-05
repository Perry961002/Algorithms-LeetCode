class Solution:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxlen = 0 #可以跳到的最远位置
        index = 0 #跳到的位置
        count = 0
        for i in range(len(nums)):
            if i > index:
                index = maxlen
                count += 1
            maxlen = max(maxlen, i + nums[i])
        return count