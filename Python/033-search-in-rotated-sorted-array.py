class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        """
        有数组 a0,a1,....,ak-1, ak,ak+1,...an-1
        旋转后 ak,ak+1,...an-1，a0,a1,....,ak-1
        二分搜索:
        当发现a[mid] != target时，判断target在前半部分还是后半部分
        """
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = (left+right) // 2
            if target == nums[mid]:
                return mid
            elif nums[mid] > target:
                if nums[left] > nums[right] and nums[mid] >= nums[left] and target < nums[left]:
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                if nums[left] > nums[right] and nums[mid] < nums[right] and target > nums[right]:
                    right = mid - 1
                else:
                    left = mid + 1
        return -1
                