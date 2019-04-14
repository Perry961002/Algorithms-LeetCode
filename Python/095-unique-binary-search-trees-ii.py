# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        """
        结合卡特兰数和二叉搜索树的性质
        假设根节点为 i, 那么左子树为1 到 i - 1的二叉搜索树, 右子树为 i + 1到n的二叉搜索树
        """
        def createBetween(start, end):
            # 返回只含一个空结点的列表
            if start > end:
                return [None]
            elif start == end:
                #返回只含一个以start为结点值的列表
                return [TreeNode(start)]
            
            res = []
            #依次选start 到end的值作为根节点，再分别递归构造左右子树, 并组合
            for i in range(start, end + 1):
                leftList, rightList = createBetween(start, i - 1), createBetween(i + 1, end)
                for left in leftList:
                    for right in rightList:
                        root = TreeNode(i)
                        root.left, root.right = left, right
                        res.append(root)
            return res
        
        if n == 0:
            return []
        return createBetween(1, n)