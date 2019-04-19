# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        """
        在每一个节点时有下面4种情况：
            1.root->val(左、右子树最大值都是非正的)
            2.leftmax + root->val(右子树最大值非正，左子树最大值是正值)
            3.rightmax + root->val(左子树最大值非正，右子树最大值是正值)
            4.rightmax + leftmax + root->val(左子树最大值是正值，右子树最大值是正值)
        从上面情况中选出成立的，与暂存的最大值比较
        """
        self.maxSum = root.val
        #这个函数返回的是从root开始的走某个子树的最长路径值(局部), 在这个函数里面处理全局最大值
        def getMaxSum(root: TreeNode) -> int:
            if root == None:
                return 0
            #递归, 从左右子树开始的最大值
            leftMax, rightMax = getMaxSum(root.left), getMaxSum(root.right)
            rootMax = root.val + max(leftMax, 0) + max(rightMax, 0) #考虑合并两个子树方向上的最大值
            self.maxSum = max(self.maxSum, rootMax)
            #返回从root开始的走某个子树的最长路径值
            return root.val + max(max(leftMax, rightMax), 0)
        getMaxSum(root)
        return self.maxSum