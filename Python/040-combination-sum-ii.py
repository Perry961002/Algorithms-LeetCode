class Solution:
    def combination(self, candidates, tmp_target, start, possible, res):
            """
            candidates是输入数组
            tmp_target是临时需要组合的数
            start是开始遍历的下标
            possible是一个可能的组合方案
            res是最后的解集
            """
            if tmp_target == 0:
                res.append(copy.deepcopy(possible))
                return
            for i in range(start, len(candidates)):
                if tmp_target >= candidates[i]:
                    if i>start and candidates[i] == candidates[i-1]:
                        continue
                    possible.append(candidates[i])
                    self.combination(candidates, tmp_target-candidates[i], i+1, possible, res)
                    #回溯
                    possible.pop()
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        possible = []
        res = []
        self.combination(candidates, target, 0, possible, res)
        return res