class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        #创建空字典
        dict = {}
        for i in range(len(nums)):
            x = target - nums[i]
            if x in dict:
                return dict[x],i
            else:
                dict[nums[i]] = i