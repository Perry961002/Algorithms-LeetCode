class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        res = []
        for i in range(len(nums)):
            #出现正数，后面的数不可能再组成和为0的三元组
            if nums[0] > 0:
                break
            #和前面的重复
            if i > 0 and nums[i] == nums[i-1]:
                continue
            target = 0 - nums[i]
            #开始从两端开始搜索
            left = i + 1
            right = len(nums) - 1
            while left < right:
                sum = nums[left] + nums[right]
                if sum == target:
                    res.append([nums[i], nums[left], nums[right]])
                    #继续收缩的时候避免重复
                    while left < right and nums[left] == nums[left+1]:
                        left += 1
                    while left < right and nums[right] == nums[right-1]:
                        right -= 1
                    left += 1
                    right -= 1
                #和太大，说明右端取大了
                elif sum > target:
                    right -= 1
                else:
                    left += 1
        return res