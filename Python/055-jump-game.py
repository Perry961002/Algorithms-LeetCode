class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        l = len(nums)
        #最大可以到达的位置
        maxjump = 0
        for i in range(l):
            #已经可以到达终点或者当前位置已经超出最远距离
            if maxjump >= l-1 or i > maxjump:
                break
            maxjump = max(maxjump, i + nums[i])
        return maxjump >= l - 1