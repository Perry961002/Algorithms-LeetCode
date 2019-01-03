class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        lens = len(nums)
        if lens < 2:
            return lens
        index = 0
        for i in range(1, lens):
            if nums[i] != nums[index]:
                index += 1
                nums[index] = nums[i]
        return index+1