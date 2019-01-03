class Solution:
    def reverse(self, nums, left, right):
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        lens = len(nums)
        first = lens - 2
        second = lens - 1
        #从右往左寻找第一个满足nums[first] < nums[first+1]的first
        while first >= 0 and nums[first] >= nums[first+1]:
            first -= 1
        #数字不是按降序排序
        if first >= 0:
            while nums[second] <= nums[first]:
                second -= 1
            nums[first], nums[second] = nums[second], nums[first]
        else:
            return nums.reverse()
        return self.reverse(nums, first+1, lens-1)