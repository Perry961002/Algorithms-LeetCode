class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        result = []
        lens = len(nums)
        for i in range(lens-3):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            for j in range(i+1, lens-2):
                if j > i + 1 and nums[j] == nums[j-1]:
                    continue
                target_temp = target - nums[i] - nums[j]
                m = j + 1
                n = lens - 1
                while m < n:
                    if nums[m] + nums[n] == target_temp:
                        result.append([nums[i], nums[j], nums[m], nums[n]])
                        while m < n and nums[m] == nums[m+1]:
                            m += 1
                        while m < n and nums[n] == nums[n-1]:
                            n -= 1
                        m += 1
                        n -= 1
                    elif nums[m] + nums[n] > target_temp:
                        n -= 1
                    else:
                        m += 1
        return result