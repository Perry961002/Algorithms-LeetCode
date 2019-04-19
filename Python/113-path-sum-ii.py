# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    #dfs方式遍历所有路径并判断
    def foundPath(self, root: TreeNode, sum: int, result: List[List[int]], res: List[int]):
        res.append(root.val)
        #只有一个结点且满足和
        if root.left == None and root.right == None and root.val == sum:
            result.append(res.copy())
            return None
        #递归并回溯
        if root.left != None:
            self.foundPath(root.left, sum - root.val, result, res)
            res.pop()
        if root.right != None:
            self.foundPath(root.right, sum - root.val, result, res)
            res.pop()
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        result, res = [], []
        if root == None:
            return result
        self.foundPath(root, sum, result, res)
        return result