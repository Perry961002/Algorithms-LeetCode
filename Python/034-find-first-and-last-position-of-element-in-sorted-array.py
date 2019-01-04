class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        left = 0
        right = len(nums) - 1
        res = []
        while left <= right:
            mid = (left + right) // 2
            if target == nums[mid]:
                begin = mid
                end = mid
                while begin-1 >= left and nums[begin-1] == target:
                    begin -= 1
                while end+1 <= right and nums[end+1] == target:
                    end += 1
                res.append(begin)
                res.append(end)
                return res
            elif target > nums[mid]:
                left = mid + 1
            else:
                right = mid - 1
        res.append(-1)
        res.append(-1)
        return res