class Solution:
    def dfs(self, nums, visit, cur, res):
        """
        visit记录元素是否被使用
        cur是一个排列
        res是最后的结果
        """
        if sum(visit) == len(nums):
            res.append(cur[:])
        for i in range(len(nums)):
            if visit[i]:
                continue
            else:
                # 深搜
                cur.append(nums[i])
                visit[i] = 1
                self.dfs(nums, visit, cur, res)
                # 回溯
                visit[i] = 0
                cur.pop()
                
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) < 2:
            return [nums]
        visit = [0] * len(nums)
        cur = []
        res = []
        self.dfs(nums, visit, cur, res)
        return res