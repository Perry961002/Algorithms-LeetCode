class Solution:
    def numTrees(self, n: int) -> int:
        """
        结合卡特兰数和二叉搜索树的性质
        假设根节点为 i, 那么左子树为1 到 i - 1的二叉搜索树, 右子树为 i + 1到n的二叉搜索树
        """
        dp = [0] * (n + 1)
        dp[0], dp[1] = 1, 1
        for i in range(2, n + 1):
            for j in range(1, i + 1):
                dp[i] += dp[j - 1] * dp[i - j]
        return dp[n]